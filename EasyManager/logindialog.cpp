#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordEdit->setFocus();
    ui->loginButton->setDefault(true);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginButton_clicked()
{
    if(ui->passwordEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("请输入密码"), tr("请输入密码再登录"), QMessageBox::Ok);
        ui->passwordEdit->setFocus();
    }
    else
    {
        QSqlQuery query;
        query.exec("select pwd from password");
        query.next();
        if(query.value(0).toString() == ui->passwordEdit->text())
        {
            QDialog::accept();
        }
        else
        {
           QMessageBox::warning(this, tr("密码错误"), tr("请输入正确密码后再登录"),QMessageBox::Ok);
           ui->passwordEdit->clear();
           ui->passwordEdit->setFocus();//给一个输入焦点
        }
     }
}

void LoginDialog::on_quitButton_clicked()
{
    QDialog::reject();//隐藏对话框，发送拒绝信号
}
