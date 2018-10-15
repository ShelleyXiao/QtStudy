#ifndef MID_CHILD_H
#define MID_CHILD_H

#include <QTextEdit>

class MidChild: public QTextEdit
{
    Q_OBJECT
public:
    explicit MidChild(QWidget *parent = 0);

    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFirendlyCurrentFile();

    QString currentFile() {
        return curFile;
    }

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();



private:
    QString curFile;
    bool isUntitled;

    bool maybeSave();
    void setCurrentFile(const QString &fileName);
};

#endif // MID_CHILD_H
