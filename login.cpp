#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_login_login_clicked()
{
    if(ui->userName->text().isEmpty() || ui->password->text().isEmpty()){
        QMessageBox::information(this,tr("提示"),tr("不能为空"),QMessageBox::Ok);
        ui->userName->clear();
        ui->password->clear();
        return;
    }
    QString uid = ui->userName->text();
    QString pwd = ui->password->text();
    QSqlQuery query;
    query.prepare("select * from ADMIN where A_USER=:uid and A_KEY = :pwd");
    query.bindValue(":uid",uid);
    query.bindValue(":pwd",pwd);
    query.exec();
    if(query.next()){
        MainWindow *m = new MainWindow();
        m->show();
        this->hide();
        query.clear();
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("请重新输入"),QMessageBox::Ok);
        ui->userName->clear();
        ui->password->clear();
        query.clear();
        return;
    }
}

void login::on_login_exit_clicked()
{
    this->close();
}
