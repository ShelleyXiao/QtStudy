#include <QCoreApplication>

#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Avaiable drivers";
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug() << driver;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(":memory");

    if(!db.open()) {
        return false;
    }

    QSqlQuery query;
    query.exec("create table student int primay key, name varchar");
    query.exec("insert into student values(1, 'xiaogang')");
    query.exec("insert into student values(2, 'xiaogang')");
    query.exec("insert into student values(3, 'xiaogang')");

    query.exec("select id, name from student where id >= 2");

    while(query.next()) {
        int value0 = query.value(0).toInt();
        QString value1 = query.value(1).toString();
        qDebug() << value0 << value1;
    }

    return a.exec();
}
