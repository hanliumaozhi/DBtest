#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriverCreator>
#include <QtPlugin>
#include "mainwindow.h"
#include "login.h"

bool createConnections()
{
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setDatabaseName("Library");
    DB.setUserName("root");
    DB.setPassword("");
    DB.setHostName("localhost");

    DB.setPort(3306);
    if(!DB.open()){
        qDebug()<<DB.lastError().databaseText()<<"\n";
        return false;
    }
    return TRUE;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    if(!createConnections()){
        return 1;
    }
    else{
        qDebug()<<"ss"<<"\n";
    }
    login lg;
    lg.show();
    
    return a.exec();
}
