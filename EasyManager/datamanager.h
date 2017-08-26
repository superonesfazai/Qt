#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QMainWindow>
#include <QDomDocument>

namespace Ui {
class DataManager;
}

class QStandardItemModel;//这个类为Qt中提供了存储定制数据的通用模型

class DataManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataManager(QWidget *parent = 0);
    ~DataManager();

    enum DataTimeType{Time, Date, DateTime};//定义时间的枚举类型
    QString getDataTime(DataTimeType type);

private slots:
    void on_sellTypeComboBox_currentIndexChanged(const QString &arg1);

    void on_sellBrandComboBox_currentIndexChanged(const QString &arg1);

    void on_sellNumSpinBox_valueChanged(int arg1);

    void on_sellCancelButton_clicked();

    void on_sellOkButton_clicked();

    void on_typeComboBox_currentIndexChanged(const QString &arg1);

    void on_updateButton_clicked();

    void on_manageButton_clicked();

    void on_chartButton_clicked();

    void on_passwordButton_clicked();

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DataManager *ui;

    QDomDocument doc;
    QStandardItemModel *chartModel;
    bool docRead();
    bool docWrite();
    void writeXml();
    void createNodes(QDomElement &data);
    void showDailyList();

    void createChartModelView();
    void showChart();
};

#endif // DATAMANAGER_H
