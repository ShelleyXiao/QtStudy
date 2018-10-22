#include "masterthread.h"

#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QMutexLocker>

QT_USE_NAMESPACE

MasterThread::MasterThread(QObject *parent)
    :QThread(parent),
      waitTimeout(0),
      quit(false)
{

}

MasterThread::~MasterThread()
{
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}

void MasterThread::transaction(const QString &portName, int waitTimeout, const QString &request)
{
    QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->request = request;
    if(!isRunning()) {
        start();
    } else {
        cond.wakeOne();
    }
}

void MasterThread::run()
{
    bool currentPortNameChanged = false;
    QString currentPortName ;
    if(currentPortName != portName) {
        currentPortName = portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = waitTimeout;
    QString currentRequest = request;
    mutex.unlock();

    QSerialPort port;

    while(!quit) {
        if(currentPortNameChanged) {
            port.close();
            port.setPortName(currentPortName);
            if(!port.open(QIODevice::ReadWrite)) {
                emit error(tr("can't open %1, error code %2")
                           .arg(portName)
                           .arg(port.error()));
                return;

            }
        }

        QByteArray requestData = currentRequest.toLocal8Bit();
        port.write(requestData);
        if(port.waitForBytesWritten(waitTimeout)) {
            if(port.waitForReadyRead(currentWaitTimeout)) {
                QByteArray responeData = port.readAll();
                while(port.waitForReadyRead(10)) {
                    responeData += port.readAll();
                }
                QString respone(responeData);
                emit this->response(respone);
            } else {
                emit this->timeout(tr("wait read response timeout %1")
                                   .arg(QTime::currentTime().toString()));
            }
        } else {
            emit this->timeout(tr("wait write request timeout %1")
                               .arg(QTime::currentTime().toString()));
        }

        mutex.lock();
        cond.wait(&mutex);
        if(currentPortName != portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }

        currentWaitTimeout  = waitTimeout;
        currentRequest = request;
        mutex.unlock();

    }
}
