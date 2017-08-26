#include <QApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <>

void Write(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Could not open file for write!";
        return;
    }

    QTextStream out(&mFile);
    out << "Hello world!";
    mFile.flush();
    mFile.close();
}

void Read(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for read!";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();
    qDebug() << mText;

    mFile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString mFilename = "E:/mytestFile.txt";
    Write(mFilename);
    Read(mFilename);

    return a.exec();
}
