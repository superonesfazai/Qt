#include <QApplication>
#include "datamanager.h"
#include "connection.h"
#include "logindialog.h"
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    if(!createConnection() || !createXml())//可以直接调用头文件中的函数
        return 0;
    DataManager w;//两个界面类都要定义
    LoginDialog dlg;
    //当在LoginDialog中运行QDialog::accept()函数时，会发送QDialog::Accepted信号，当接收到时，再调用DataManager界面
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }


}


//http://www.cnblogs.com/tornadomeet/archive/2012/09/19/2694332.html网站链接
