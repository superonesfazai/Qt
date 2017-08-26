#include "logindialog.h"
#include "admindialog.h"
#include "tourist.h"
#include "userdialog.h"
#include <QApplication>
//#include <QTextCodec>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));       //避免中文QString乱码
    LoginDialog w;


    w.show();
    return a.exec();
}
