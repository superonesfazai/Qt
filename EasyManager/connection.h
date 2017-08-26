#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>
#include <QtXml>

//该头文件就一个函数，即创建关联表的函数
static bool createConnection()
{
    //SqlDatabase为实现数据库连接的类
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//创建一个数据库，添加数据库驱动
    db.setHostName("tornadomeet");
    db.setDatabaseName("data.db");//设置数据库的名字
    db.setUserName("tornadomeet1");//设置数据库的用户名
//    db.setPassword("2012");//设置数据库的密码
    if(!db.open())
        return false;

    QSqlQuery query;//新建一个查询库

    //创建一个类型表,表名为type;varchar是用来保存可变长度的字符串
    query.exec("create table type(id varchar primary key, name varchar)");
    query.exec(QString("insert into type values('00', '请选择类型')"));//表中的第一个项
    query.exec(QString("insert into type values('01', '电视')"));//加入第二项
    query.exec(QString("insert into type values('02', '空调')"));//第三项

    //创建一个品牌表,表名为brand
    query.exec("create table brand(id varchar primary key, name varchar, "
               "type varchar, price int, sum int, sell int, last int)");
    query.exec(QString("insert into brand values('01', '海信', '电视', '3699', '50', '10', '40')"));
    query.exec(QString("insert into brand values('02', '创维', '电视', '3499', '20', '5', '15')"));
    query.exec(QString("insert into brand values('03', '海尔', '电视', '4199', '80', '40', '40')"));
    query.exec(QString("insert into brand values('04', '王牌', '电视', '3999', '40', '10', '30')"));
    query.exec(QString("insert into brand values('05', '海尔', '空调', '2699', '60', '10', '50')"));
    query.exec(QString("insert into brand values('06', '格力', '空调', '2799', '70', '20', '50')"));
//    query.exec("insert into type brand('05', '海尔', '空调', '2699', '60', '10', '50')");
//    query.exec("insert into type brand('06', '格力', '空调', '2799', '70', '20', '50')");
    query.exec("create table password(pwd varchar primary key)");
    query.exec("insert into password values('2012')");

    return true;
}

static bool createXml()
{
    QFile file("data.xml");//创建一个xml文件
    if(file.exists())
        return true;
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))//以只写方式打开，且清零以前的信息
        return false;
    QDomDocument doc;//新建一个QDomDocument类对象，它代表一个xml文件
    QDomProcessingInstruction instruction;//添加处理指令
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);//xml文件版本等信息
    QDomElement root = doc.createElement(QString("目录销售清单"));
    doc.appendChild(root);//增加根目录
    QTextStream out(&file);//指定文本流
    doc.save(out, 4);//将xml文档保存到文件data.xml文件中，4表示子元素缩进字符数
    file.close();

    return true;
}

#endif // CONNECTION_H
