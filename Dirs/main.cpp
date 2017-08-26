#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QDir mDir("E:/QtDoc");
    QDir mDir;


    //qDebug() << mDir.exists();
    foreach(QFileInfo mItm, mDir.drives())
    {
        qDebug() << mItm.absoluteFilePath();

    }
    return a.exec();
}
