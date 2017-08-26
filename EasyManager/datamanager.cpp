#include "datamanager.h"
#include "ui_datamanager.h"
#include "connection.h"
#include "pieview.h"
#include <QtSql>
#include <QtXml>
#include <QtGui>

DataManager::DataManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataManager)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QSqlQueryModel *typeModel = new QSqlQueryModel(this);//新建一个Sql查询模块
    typeModel->setQuery(QString("select name from type"));//执行改句相当于执行查询语句，其结果可以设置在组合框中
    ui->sellTypeComboBox->setModel(typeModel);

    QSplitter *splitter = new QSplitter(ui->managePage);//增加一个分隔符
    splitter->resize(680, 400);
    splitter->move(10, 40);
    splitter->addWidget(ui->toolBox);
    splitter->addWidget(ui->dailyList);
    splitter->setStretchFactor(0, 1);//第一个widget的分割器中所占面积大小之比为1
    splitter->setStretchFactor(1, 1);

    on_sellCancelButton_clicked();//初始化各控件的状态
    showDailyList();

    ui->typeComboBox->setModel(typeModel);
    createChartModelView();

}

DataManager::~DataManager()
{
    delete ui;
}

void DataManager::on_sellTypeComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "请选择类型")
        {;}
    else
    {
        ui->sellBrandComboBox->setEnabled(true);
        QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(QString("select name from brand where type = '%1'").arg(arg1));//注意单引号是英文状态下的
        ui->sellBrandComboBox->setModel(model);
        ui->sellCancelButton->setEnabled(true);//取消按钮可用
    }
}

void DataManager::on_sellBrandComboBox_currentIndexChanged(const QString &arg1)
{
    ui->sellNumSpinBox->setValue(0);//将数量值设置为0
    ui->sellNumSpinBox->setEnabled(false);//数量值那一栏不可更改
    ui->sellSumLineEdit->clear();//金额数清0
    ui->sellSumLineEdit->setEnabled(false);//金额一栏不可用
    ui->sellOkButton->setEnabled(false);//确定按钮也不可用

    QSqlQuery query;
    query.exec(QString("select price from brand where name ='%1' and type ='%2'").
               arg(arg1).arg(ui->sellTypeComboBox->currentText()));
    query.next();//查询记录指向相邻的下一条记录
    ui->sellPriceLineEdit->setEnabled(true);//单价输入框
    ui->sellPriceLineEdit->setReadOnly(true);
    ui->sellPriceLineEdit->setText(query.value(0).toString());//value(0)为获得第0个属性的值，这里指的是price

    query.exec(QString("select last from brand where name ='%1' and type = '%2'").
               arg(arg1).arg(ui->sellTypeComboBox->currentText()));
    query.next();//移向第一个记录
    int num = query.value(0).toInt();//取出来
    if(0 == num)
    {
        QMessageBox::information(this, tr("提示"), tr("该商品已经销售完了!"), QMessageBox::Ok);
    }
    else
    {
        ui->sellNumSpinBox->setEnabled(true);//可用使用
        ui->sellNumSpinBox->setMaximum(num);//设置最大值为剩余数量的值
        ui->sellLastNumLabel->setText(tr("剩余数量: %1").arg(num));
        ui->sellLastNumLabel->setVisible(true);//其实默认情况下就是可见的
    }


}

void DataManager::on_sellNumSpinBox_valueChanged(int arg1)
{
    if(arg1 == 0)
    {
        ui->sellSumLineEdit->clear();//清零且不可用
        ui->sellSumLineEdit->setEnabled(false);
        ui->sellOkButton->setEnabled(false);
    }
    else
    {
        ui->sellSumLineEdit->setEnabled(true);
        ui->sellSumLineEdit->setReadOnly(true);
        //qreal其实就是一个double型
        qreal sum = arg1*(ui->sellPriceLineEdit->text().toInt());//卖出的数量*单价等于总额
        ui->sellSumLineEdit->setText(QString::number(sum));//显示总额
        ui->sellOkButton->setEnabled(true);
    }
}

void DataManager::on_sellCancelButton_clicked()
{
    ui->sellTypeComboBox->setCurrentIndex(0);

    ui->sellBrandComboBox->clear();//品牌框不可用，且清零
    ui->sellBrandComboBox->setEnabled(false);

    ui->sellPriceLineEdit->clear();
    ui->sellPriceLineEdit->setEnabled(false);//单价栏不可用

    ui->sellNumSpinBox->setValue(0);//数量栏清零且不可用
    ui->sellNumSpinBox->setEnabled(false);

    ui->sellSumLineEdit->clear();
    ui->sellSumLineEdit->setEnabled(false);//总额栏不可用

    ui->sellOkButton->setEnabled(false);
    ui->sellCancelButton->setEnabled(false);//按钮不可用
    ui->sellLastNumLabel->setVisible(false);//剩余数不可见
}

void DataManager::on_sellOkButton_clicked()
{
    //QSqlDatabase::database()返回前面成功连接的QSqlDatabase对象。
    QString type = ui->sellTypeComboBox->currentText();
    QString name = ui->sellBrandComboBox->currentText();
    int value = ui->sellNumSpinBox->value();//当前打算卖出的量
    int last = ui->sellNumSpinBox->maximum()-value;//当前还剩余的量
    QSqlQuery query;
    query.exec(QString("select sell from brand where name=%1 and type=2%").arg(name).arg(type));
    query.next();//指向结果集的第一条记录
    int sell = query.value(0).toInt()+value;//总共售出量
    QSqlDatabase::database().transaction();//事务操作开始
    bool rtn = query.exec(QString("update brand set sell=%1, last=%2 where name='%3' and type='%4'").arg(sell).
                          arg(last).arg(name).arg(type));
    if(rtn)
    {
        QSqlDatabase::database().commit();//上面查询操作成功时，则提交事务操作
        QMessageBox::information(this, tr("提示"), tr("购买成功!"), QMessageBox::Ok);
        writeXml();
        showDailyList();
        on_sellCancelButton_clicked();
  //      qDebug() << "It's OK!";
    }
    else
    {
        QSqlDatabase::database().rollback();//如果上述查询操作失败，则执行事务回滚
    }
}


QString DataManager::getDataTime(DataManager::DataTimeType type)
{
    QDateTime datetime = QDateTime::currentDateTime();
    QString date = datetime.toString("yyyy-MM-dd");
    QString time = datetime.toString("hh:mm");
    QString date_time = datetime.toString("yyyy-MM-dd dddd hh:mm");
    if(type == Date)
        return date;
    else if(type == Time)
        return time;
    else return date_time;
}


//将xml文件中的内容读取到QDomDocument类对象中去
bool DataManager::docRead()
{
    QFile file("data.xml");
    if(!file.open(QIODevice::ReadOnly))//打开文件
    {
        return false;
    }
    if(!doc.setContent(&file))//读取文件
    {
        file.close();
        return false;
    }
    file.close();
    return true;
}


//将QDomDocument类对象的内容写到xml文档中去
bool DataManager::docWrite()
{
    QFile file("data.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    QTextStream out(&file);
    doc.save(out, 4);//将doc内容存入到file中
    file.close();
    return true;
}

void DataManager::writeXml()
{
    if(docRead())
    {
        QString currentDate = getDataTime(Date);//获得当前日期
        QDomElement root = doc.documentElement();//获得当前文档根节点
        if(!root.hasChildNodes())
        {
            QDomElement date = doc.createElement(QString("日期"));//增加一个标签
            QDomAttr curDate = doc.createAttribute("date");//增加一个属性
            curDate.setValue(currentDate);//给属性赋值
            date.setAttributeNode(curDate);//给新增加的标签附上该属性
            root.appendChild(date);//往根节点上添加标签
            createNodes(date);//创建标签节点
        }
        else
        {
           QDomElement date = root.lastChild().toElement();
           //已经有了今天的节点信息
           if(date.attribute("date") == currentDate)
           {
                createNodes(date);
           }
           else
           {
                QDomElement date = doc.createElement(QString("日期"));
                QDomAttr curDate = doc.createAttribute("date");
                curDate.setValue(currentDate);
                date.setAttributeNode(curDate);
                root.appendChild(date);
                createNodes(date);
           }
        }
        docWrite();//写入到xml文件中
    }
}


//创建销售商品的信息的节点
void DataManager::createNodes(QDomElement &date)
{
    //创建标签time，并为其设置属性值
    QDomElement time = doc.createElement(QString("时间"));
    QDomAttr curTime = doc.createAttribute("time");
    curTime.setValue(getDataTime(Time));
    time.setAttributeNode(curTime);

    //将新建的time标签加载到date标签上
    date.appendChild(time);

    QDomElement type = doc.createElement(QString("类型"));
    QDomElement brand = doc.createElement(QString("品牌"));
    QDomElement price = doc.createElement(QString("单价"));
    QDomElement num = doc.createElement(QString("数量"));
    QDomElement sum = doc.createElement(QString("金额"));

    QDomText text;//用来存放文本值对象
    text = doc.createTextNode(QString("%1").arg(ui->sellTypeComboBox->currentText()));
    type.appendChild(text);//type标签中的文本内容

    //brand标签
    text = doc.createTextNode(QString("%1").arg(ui->sellBrandComboBox->currentText()));
    brand.appendChild(text);

    //price标签
    text = doc.createTextNode(QString("%1").arg(ui->sellPriceLineEdit->text()));
    price.appendChild(text);

    //num标签
    text = doc.createTextNode(QString("%1").arg(ui->sellNumSpinBox->value()));
    num.appendChild(text);

    //sum标签
    text = doc.createTextNode(QString("%1").arg(ui->sellSumLineEdit->text()));
    sum.appendChild(text);

    time.appendChild(type);//将新建的标签都贴在time标签上
    time.appendChild(brand);
    time.appendChild(price);
    time.appendChild(num);
    time.appendChild(sum);
}


void DataManager::showDailyList()
{
    ui->dailyList->clear();
    if(docRead())
    {
        QDomElement root = doc.documentElement();//获取根标签
        QString title = root.tagName();//获得根标签的名字
        QListWidgetItem *listItem = new QListWidgetItem;//建立一个listWidget
        listItem->setText(QString("......%1......").arg(title));//设置显示的标题
        listItem->setTextAlignment(Qt::AlignCenter);//标题设置为中心对齐
        ui->dailyList->addItem(listItem);//将该listItem添加到QListWidgetItem中
        if(root.hasChildNodes())
        {
           QString currentDate = getDataTime(Date);//得到当前的日期
           QDomElement dateElement = root.lastChild().toElement();//得到最后一个标签
           QString date = dateElement.attribute("date");//得到该标签的的时间属性
           if(date == currentDate)
           {
                ui->dailyList->addItem("");//这里是空格一行
                ui->dailyList->addItem(QString("日期: %1").arg(date));
                ui->dailyList->addItem("");
                QDomNodeList children = dateElement.childNodes();//获得该标签的所有子元素列表
                qDebug() << children.count();
                for(int i = 0; i < children.count(); i++)
                {
                    QDomNode node = children.at(i);//得到第i个子元素的节点
                    QString time = node.toElement().attribute("time");//需先将node转换成element
                    QDomNodeList list = node.childNodes();
                    //分别获取节点中元素的内容
                    QString type = list.at(0).toElement().text();
                    QString brand = list.at(1).toElement().text();
                    QString price = list.at(2).toElement().text();
                    QString num = list.at(3).toElement().text();
                    QString sum = list.at(4).toElement().text();
                    QString str = time + " 出售 " + brand + type
                            + " " + num + "台， " + "单价：" + price
                            + "元， 共" + sum + "元";
                    QListWidgetItem *tempItem =  new QListWidgetItem;
                    tempItem->setText("*************************");
                    tempItem->setTextAlignment(Qt::AlignCenter);
                    ui->dailyList->addItem(tempItem);
                    ui->dailyList->addItem(str);//显示该卖出产品的信息
               }
           }
        }
    }
}


void DataManager::createChartModelView()
{
    chartModel = new QStandardItemModel(this);
    chartModel->setColumnCount(2);//设置为2列显示
    chartModel->setHeaderData(0, Qt::Horizontal, QString("品牌"));
    chartModel->setHeaderData(1, Qt::Horizontal, QString("销售数量"));//模型的字段名

    QSplitter *splitter = new QSplitter(ui->chartPage);//新建分隔器
    splitter->resize(680, 400);
    splitter->move(10, 40);

    QTableView *table = new QTableView;
    PieView *pieChart = new PieView;

    splitter->addWidget(table);//为分隔符2侧添加widget
    splitter->addWidget(pieChart);

    splitter->setStretchFactor(0, 1);//设置比例
    splitter->setStretchFactor(1, 2);

    table->setModel(chartModel);//设置模型？？
    pieChart->setModel(chartModel);

    QItemSelectionModel *selectionModel = new QItemSelectionModel(chartModel);
    table->setSelectionModel(selectionModel);//设置共用选择模型
    pieChart->setSelectionModel(selectionModel);
}


void DataManager::showChart()
{
    QSqlQuery query;
    query.exec(QString("select name, sell from brand where type='%1'").arg(ui->typeComboBox->currentText()));
    //全部删除表中的内容
    //rowCount()为返回参数索引中的行数，QModelIndex()为一个不可用的模型索引，该模型索引通常被用来在顶级项目时被父索引使用
    //removeRows()为删除参数1开始的参数2行个行
    chartModel->removeRows(0, chartModel->rowCount(QModelIndex()), QModelIndex());

    int row = 0;
    while(query.next())
    {
        int r = qrand()%256;
        int g = qrand()%256;
        int b = qrand()%256;

        chartModel->insertRows(row, 1, QModelIndex());//增加一行
        chartModel->setData(chartModel->index(row, 0, QModelIndex()), query.value(0).toString());//第一行第一列设置查询结果值
        chartModel->setData(chartModel->index(row, 1, QModelIndex()), query.value(1).toInt());
        //Qt::DecorationRole是Qt::ItemDataRole中的一种, Qt::ItemDataRole表示每一个model中的Item都有自己的一个数据集,
        //且有自己的特色。这些特点用来指定模型中的哪一种数据类型将被使用。而Qt::DecorationRole指的是说数据将以图表的形式来呈现。
        chartModel->setData(chartModel->index(row, 0, QModelIndex()), QColor(r, g, b), Qt::DecorationRole);
//        chartModel->setData(chartModel->index(row, 1, QModelIndex()), query.value(1).toInt());
//        chartModel->setData(chartModel->index(row, 0, QModelIndex()), QColor(r, g, b), Qt::DecorationRole);
        row ++;
    }
}



void DataManager::on_typeComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 != "请选择类型")
        showChart();
}

void DataManager::on_updateButton_clicked()
{
    if(ui->typeComboBox->currentText() != "请选择类型")
        showChart();//其实是更新品牌的随机颜色
}

void DataManager::on_manageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);//显示stackWidget的第一页
}

void DataManager::on_chartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//显示stackWidget的第二页
}

void DataManager::on_passwordButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//进入密码管理页
}

void DataManager::on_okButton_clicked()
{
    QSqlQuery query;
    query.exec("select pwd from password");
    query.next();
    if(ui->oldPasswordLineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("请输入密码"), tr("请输入旧密码和新密码"), QMessageBox::Ok);
    else if(ui->oldPasswordLineEdit->text() != query.value(0).toString())
    {
        QMessageBox::warning(this, "密码错误", tr("输入的旧密码错误"), QMessageBox::Ok);
        ui->oldPasswordLineEdit->setFocus();
    }
    else
    {
        if(ui->newPasswordLineEdit->text() == ui->surePasswordlineEdit->text())
        {
            QString newPassword = ui->newPasswordLineEdit->text();
            query.exec(QString("update password set pwd=%1").arg(newPassword));//更新密码
            QMessageBox::information(this, tr("修改密码"), tr("修改密码成功！"), QMessageBox::Ok);
        }
        else
            QMessageBox::warning(this, tr("修改密码失败"), tr("新密码两次输入不一致！"), QMessageBox::Ok);
    }
}

void DataManager::on_cancelButton_clicked()
{
    ui->oldPasswordLineEdit->clear();
    ui->oldPasswordLineEdit->setFocus();//把输入焦点放在旧密码处，方便重新输入
    ui->newPasswordLineEdit->clear();
    ui->surePasswordlineEdit->clear();
}
