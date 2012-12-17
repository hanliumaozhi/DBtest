#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{
    QString selectBook("select * from  BOOKS where");
    QString ANDFIX(" AND ");
    QSqlQuery query;
    int countSBook = 0;
//ui->tableWidget->clear();
    bool isFirst = true;
    if(!ui->authorName->text().isEmpty()){
        QString fix = QString(tr("'%1'")).arg(ui->authorName->text());
        if(isFirst){
            selectBook = selectBook + "  O_AUTHOR = " + fix;
            isFirst = false;
        }
        else{
            selectBook = selectBook + ANDFIX + "  O_AUTHOR = " + fix;
        }
    }
    if(!ui->bookName->text().isEmpty()){
        QString fix = QString(tr("'%1'")).arg(ui->bookName->text());
        if(isFirst){
            selectBook = selectBook + " O_NAME = " + fix;
            isFirst = false;
        }
        else{
            selectBook = selectBook + ANDFIX + " O_NAME = " + fix;
        }
    }
    if(!ui->ISBN->text().isEmpty()){
        QString fix = QString(tr("'%1'")).arg(ui->ISBN->text());
        if(isFirst){
            selectBook = selectBook + " O_ISBN = " + fix;
            isFirst = false;
        }
        else{
            selectBook = selectBook + ANDFIX + " O_ISBN = " + fix;
        }
    }
    if(!ui->flei->text().isEmpty()){
        QString fix = QString(tr("'%1'")).arg(ui->flei->text());
        if(isFirst){
            selectBook = selectBook + " O_CLASS = " + fix;
            isFirst = false;
        }
        else{
            selectBook = selectBook + ANDFIX + " O_CLASS = " + fix;
        }
    }
    qDebug()<<selectBook;
    query.exec(selectBook);
    isFirst = true;
    while(ui->tableWidget->rowCount()){
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    }
    while(query.next()){
        int i = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(i);
        QString NUM = query.value(5).toString();
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(NUM));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(query.value(6).toString()));
        countSBook += NUM.toInt();
        isFirst=false;
    }
    if(isFirst){
        QMessageBox::information(this,tr("提示"),tr("没有记录"),QMessageBox::Ok);
    }
    else{
        int i = ui->tableWidget->rowCount();
        QString temss = QString(tr("共有%1条记录,共计本%2书")).arg(i).arg(countSBook);
        QMessageBox::information(this,tr("提示"),temss,QMessageBox::Ok);
    }
    query.clear();
}
