#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->B_NIO->text().isEmpty() || ui->S_NO->text().isEmpty()){
        QMessageBox::information(this,tr("提示"),tr("不能为空"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    QSqlQuery query;
    QString s_num="";
    QString b_num="";
    QString o_name="";
    QString o_author="";
    QString o_price ="";
    QString s_name="";
    query.prepare("select C_NUM from  COUNT where C_NO = :uid");
    query.bindValue(":uid",ui->S_NO->text());
    query.exec();
    if(query.next()){
        s_num = query.value(0).toString();
    }
    query.prepare("select * from  BOOKS where O_ISBN = :bid");
    query.bindValue(":bid",ui->B_NIO->text());
    query.exec();
    if(query.next()){
        o_name = query.value(1).toString();
        o_author = query.value(2).toString();
        o_price = query.value(4).toString();
        b_num = query.value(5).toString();
    }
    qDebug()<<s_num<<b_num;
    query.prepare("SELECT S_NAME FROM STUDENTS WHERE S_NO = ?");
    query.addBindValue(ui->S_NO->text());
    query.exec();
    if(query.next()){
        s_name = query.value(0).toString();
        qDebug()<<s_name;
    }
    if(s_num.isEmpty() || s_num.toInt() < 1){
        QMessageBox::information(this,tr("提示"),tr("输入学号错误"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    if(b_num.isEmpty() || b_num.toInt() < 1){
        QMessageBox::information(this,tr("提示"),tr("输入ISBN错误"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    int ss_num=s_num.toInt();
    int bb_num=b_num.toInt();
    --bb_num;
    --ss_num;
    QString temss = QString(tr("%1还能借%2本书")).arg(s_name).arg(ss_num);
    QMessageBox::information(this,tr("提示"),temss,QMessageBox::Ok);
    query.prepare("UPDATE BOOKS SET  O_STORAGE = ? WHERE O_ISBN = ?");
    query.addBindValue(QString::number(bb_num,10));
    query.addBindValue(ui->B_NIO->text());
    query.exec();
    query.prepare("UPDATE COUNT SET  C_NUM = ? WHERE C_NO = ?");
    query.addBindValue(QString::number(ss_num,10));
    query.addBindValue(ui->S_NO->text());
    query.exec();
    QDate date;
    date=date.fromString("2012.9.1","yyyy.M.d");
    //date=date.currentDate();
    QString newdate=date.toString("yyyy.M.d");
    qDebug()<<newdate;
    int countI = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(countI);
    ui->tableWidget->setItem(countI,0,new QTableWidgetItem(ui->S_NO->text()));
    ui->tableWidget->setItem(countI,1,new QTableWidgetItem(s_name));
    ui->tableWidget->setItem(countI,2,new QTableWidgetItem(ui->B_NIO->text()));
    ui->tableWidget->setItem(countI,3,new QTableWidgetItem(o_name));
    ui->tableWidget->setItem(countI,4,new QTableWidgetItem(o_author));
    ui->tableWidget->setItem(countI,5,new QTableWidgetItem(o_price));
    ui->tableWidget->setItem(countI,6,new QTableWidgetItem(QString(tr("借出"))));
    ui->tableWidget->setItem(countI,7,new QTableWidgetItem(newdate));
    query.prepare("INSERT INTO BORROW (B_NO,B_ISBN,B_TIME,B_ISRENT) VALUES(?,?,?,?)");
    query.addBindValue(ui->S_NO->text());
    query.addBindValue(ui->B_NIO->text());
    query.addBindValue(newdate);
    query.addBindValue(0);
    query.exec();
    query.clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->B_NIO->text().isEmpty() || ui->S_NO->text().isEmpty()){
        QMessageBox::warning(this,tr("提示"),tr("不能为空"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    QSqlQuery query;
    QString s_num="";
    QString b_num="";
    QString o_name="";
    QString o_author="";
    QString o_price ="";
    QString s_name="";
    QString b_id="";
    query.prepare("select C_NUM from  COUNT where C_NO = :uid");
    query.bindValue(":uid",ui->S_NO->text());
    query.exec();
    if(query.next()){
        s_num = query.value(0).toString();
    }
    query.prepare("select * from  BOOKS where O_ISBN = :bid");
    query.bindValue(":bid",ui->B_NIO->text());
    query.exec();
    if(query.next()){
        o_name = query.value(1).toString();
        o_author = query.value(2).toString();
        o_price = query.value(4).toString();
        b_num = query.value(5).toString();
    }
    qDebug()<<s_num<<b_num;
    query.prepare("SELECT S_NAME FROM STUDENTS WHERE S_NO = ?");
    query.addBindValue(ui->S_NO->text());
    query.exec();
    if(query.next()){
        s_name = query.value(0).toString();
        qDebug()<<s_name;
    }
    if(s_num.isEmpty()){
        QMessageBox::warning(this,tr("提示"),tr("输入学号错误"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    if(b_num.isEmpty()){
        QMessageBox::warning(this,tr("提示"),tr("输入ISBN错误"),QMessageBox::Ok);
        ui->B_NIO->clear();
        ui->S_NO->clear();
        return;
    }
    int ss_num=s_num.toInt();
    int bb_num=b_num.toInt();
    ++bb_num;
    ++ss_num;
    qDebug()<<ss_num<<bb_num;
    query.prepare("UPDATE BOOKS SET  O_STORAGE = ? WHERE O_ISBN = ?");
    query.addBindValue(QString::number(bb_num,10));
    query.addBindValue(ui->B_NIO->text());
    query.exec();
    query.prepare("UPDATE COUNT SET  C_NUM = ? WHERE C_NO = ?");
    query.addBindValue(QString::number(ss_num,10));
    query.addBindValue(ui->S_NO->text());
    query.exec();
    QDate date;
    QDate oldDate;
    QString oldDatetem;
    date=date.currentDate();
    QString newdate=date.toString("yyyy.M.d");
    qDebug()<<newdate;
    int countI = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(countI);
    ui->tableWidget->setItem(countI,0,new QTableWidgetItem(ui->S_NO->text()));
    ui->tableWidget->setItem(countI,1,new QTableWidgetItem(s_name));
    ui->tableWidget->setItem(countI,2,new QTableWidgetItem(ui->B_NIO->text()));
    ui->tableWidget->setItem(countI,3,new QTableWidgetItem(o_name));
    ui->tableWidget->setItem(countI,4,new QTableWidgetItem(o_author));
    ui->tableWidget->setItem(countI,5,new QTableWidgetItem(o_price));
    ui->tableWidget->setItem(countI,6,new QTableWidgetItem(QString(tr("还回"))));
    ui->tableWidget->setItem(countI,8,new QTableWidgetItem(newdate));
    query.prepare("SELECT B_ID,B_TIME FROM BORROW WHERE B_NO = ? AND B_ISBN = ? AND B_ISRENT = 0");
    query.addBindValue(ui->S_NO->text());
    query.addBindValue(ui->B_NIO->text());
    query.exec();
    if(query.first()){
        b_id = query.value(0).toString();
        oldDatetem = query.value(1).toString();
        oldDatetem.replace(QString("-"),QString(""));
        qDebug()<<b_id<<oldDatetem;
    }
    query.prepare("UPDATE BORROW SET B_ISRENT=?,B_RENTTIME=? WHERE B_ID = ?");
    query.addBindValue(1);
    query.addBindValue(newdate);
    query.addBindValue(b_id);
    query.exec();
    oldDate=oldDate.fromString(oldDatetem,"yyyyMMdd");
    qDebug()<<oldDate.toString("yyyy.M.d");
    int timeforBorrow = oldDate.daysTo(date);
    if(timeforBorrow > 30){
        qDebug()<<timeforBorrow;
        QString temOfMessage=QString(tr("超期 %1 天")).arg((timeforBorrow-30));
        QMessageBox::information(this,tr("提示"),temOfMessage,QMessageBox::Ok);
        return;
    }
    query.clear();
}

void MainWindow::on_pushButton_clicked()
{
    search *s = new search();
    s->show();
}
