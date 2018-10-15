#ifndef CONNECTION_H
#define CONNECTION_H


#include <QSqlDatabase>
#include <QsqlQuery>

static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) {
        return false;
    }

    QSqlQuery query;
    query.exec(QString("create table student (id int primary key, name vchar, course int)"));
    query.exec(QString("insert into student values (0, 'xiao', 1)"));
    query.exec(QString("insert into student values (1, 'yun', 1)"));
    query.exec(QString("insert into student values (2, 'lu', 2)"));

    query.exec(QString("create table course (id int primary key, name vchar, teacher vchar)"));
    query.exec(QString("insert into course values (1, 'math', 'j')"));
    query.exec(QString("insert into course values (2, 'english', 'k')"));
    query.exec(QString("insert into course values (3, 'computer', 'm')"));

    return true;

}

#endif // CONNECTION_H
