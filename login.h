#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <mainwindow.h>
#include <QSqlQuery>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    
public:
    explicit login(QWidget *parent = 0);
    ~login();
    
private slots:
    void on_login_login_clicked();

    void on_login_exit_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
