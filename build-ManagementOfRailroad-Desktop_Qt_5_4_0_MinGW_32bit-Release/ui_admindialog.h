/********************************************************************************
** Form generated from reading UI file 'admindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDIALOG_H
#define UI_ADMINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *addButton;
    QLabel *label_8;
    QLabel *label_13;
    QWidget *tab_2;
    QPushButton *EditButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLabel *label_11;
    QLineEdit *lineEdit_15;
    QLabel *label_12;
    QWidget *tab_3;
    QLineEdit *lineEdit_8;
    QPushButton *DeleteButton;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *tab_4;
    QTextBrowser *textBrowser;
    QLabel *label_14;

    void setupUi(QDialog *AdminDialog)
    {
        if (AdminDialog->objectName().isEmpty())
            AdminDialog->setObjectName(QStringLiteral("AdminDialog"));
        AdminDialog->resize(478, 350);
        tabWidget = new QTabWidget(AdminDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 481, 351));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 131, 31));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 39, 131, 31));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 110, 113, 31));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(300, 110, 113, 31));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 180, 91, 31));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(300, 180, 91, 31));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(80, 250, 91, 31));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 61, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 40, 54, 31));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 54, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 110, 54, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 54, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 180, 54, 21));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 250, 54, 21));
        addButton = new QPushButton(tab);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(254, 242, 161, 41));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(273, 80, 121, 20));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 295, 231, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        EditButton = new QPushButton(tab_2);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(270, 260, 191, 51));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(100, 10, 121, 31));
        checkBox_2 = new QCheckBox(tab_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(100, 50, 121, 31));
        checkBox_3 = new QCheckBox(tab_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(100, 90, 121, 31));
        checkBox_4 = new QCheckBox(tab_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(100, 130, 121, 31));
        checkBox_5 = new QCheckBox(tab_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(100, 170, 121, 31));
        checkBox_6 = new QCheckBox(tab_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(100, 210, 121, 31));
        lineEdit_9 = new QLineEdit(tab_2);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(200, 10, 131, 31));
        lineEdit_10 = new QLineEdit(tab_2);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(200, 50, 131, 31));
        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(200, 90, 131, 31));
        lineEdit_12 = new QLineEdit(tab_2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(210, 130, 131, 31));
        lineEdit_13 = new QLineEdit(tab_2);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(210, 170, 131, 31));
        lineEdit_14 = new QLineEdit(tab_2);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(210, 210, 131, 31));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 270, 151, 31));
        lineEdit_15 = new QLineEdit(tab_2);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(150, 270, 91, 31));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 310, 281, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_8 = new QLineEdit(tab_3);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(160, 170, 151, 41));
        DeleteButton = new QPushButton(tab_3);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        DeleteButton->setGeometry(QRect(160, 262, 171, 41));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 110, 251, 31));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 180, 71, 21));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        textBrowser = new QTextBrowser(tab_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 481, 291));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 290, 471, 31));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(AdminDialog);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(AdminDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminDialog)
    {
        AdminDialog->setWindowTitle(QApplication::translate("AdminDialog", "Dialog", 0));
        label->setText(QApplication::translate("AdminDialog", "\345\212\250\350\275\246\347\274\226\345\217\267:", 0));
        label_2->setText(QApplication::translate("AdminDialog", "\345\217\221\350\275\246\346\227\266\351\227\264:", 0));
        label_3->setText(QApplication::translate("AdminDialog", "\350\265\267\345\247\213\347\253\231:", 0));
        label_4->setText(QApplication::translate("AdminDialog", "\347\273\210\347\202\271\347\253\231:", 0));
        label_5->setText(QApplication::translate("AdminDialog", "\347\241\254\345\272\247\346\225\260:", 0));
        label_6->setText(QApplication::translate("AdminDialog", "\347\241\254\345\215\247\346\225\260:", 0));
        label_7->setText(QApplication::translate("AdminDialog", "\350\275\257\345\215\247\346\225\260:", 0));
        addButton->setText(QApplication::translate("AdminDialog", "\347\241\256\350\256\244\346\267\273\345\212\240", 0));
        label_8->setText(QApplication::translate("AdminDialog", "(\346\240\274\345\274\217:X\345\271\264X\346\234\210X\345\217\267X:X)", 0));
        label_13->setText(QApplication::translate("AdminDialog", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AdminDialog", "\346\267\273\345\212\240\346\226\260\345\212\250\350\275\246\344\277\241\346\201\257", 0));
        EditButton->setText(QApplication::translate("AdminDialog", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
        checkBox->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\345\217\221\350\275\246\346\227\266\351\227\264", 0));
        checkBox_2->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\350\265\267\345\247\213\347\253\231", 0));
        checkBox_3->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\347\273\210\347\202\271\347\253\231", 0));
        checkBox_4->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\347\241\254\345\272\247\347\232\204\346\225\260\351\207\217", 0));
        checkBox_5->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\347\241\254\345\215\247\347\232\204\346\225\260\351\207\217", 0));
        checkBox_6->setText(QApplication::translate("AdminDialog", "\344\277\256\346\224\271\350\275\257\345\215\247\347\232\204\346\225\260\351\207\217", 0));
        label_11->setText(QApplication::translate("AdminDialog", "\350\257\267\350\276\223\345\205\245\350\246\201\344\277\256\346\224\271\347\232\204\345\212\250\350\275\246\347\232\204\347\274\226\345\217\267:", 0));
        label_12->setText(QApplication::translate("AdminDialog", "<html><head/><body><p><span style=\" color:#ff0000;\">(\350\257\267\345\234\250\350\246\201\344\277\256\346\224\271\347\232\204\344\275\215\347\275\256\346\211\223\345\213\276,\345\271\266\345\234\250\345\220\216\351\235\242\345\206\231\345\205\245\344\277\256\346\224\271\345\220\216\347\232\204\345\206\205\345\256\271)</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AdminDialog", "\344\277\256\346\224\271\345\267\262\346\234\211\345\212\250\350\275\246\344\277\241\346\201\257", 0));
        DeleteButton->setText(QApplication::translate("AdminDialog", "\347\241\256\350\256\244\345\210\240\351\231\244", 0));
        label_9->setText(QApplication::translate("AdminDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-style:italic; color:#ff0000;\">\350\257\267\345\234\250\344\270\213\346\226\271\350\276\223\345\205\245\350\246\201\345\210\240\351\231\244\347\232\204\345\212\250\350\275\246\347\274\226\345\217\267:</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("AdminDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\212\250\350\275\246\347\274\226\345\217\267:</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("AdminDialog", "\345\210\240\351\231\244\346\237\220\345\267\262\346\234\211\345\212\250\350\275\246\344\277\241\346\201\257", 0));
        label_14->setText(QApplication::translate("AdminDialog", "<html><head/><body><p><span style=\" color:#ff0000;\">\344\270\212\346\226\271\344\277\241\346\201\257\344\276\235\346\254\241\344\270\272 (\345\212\250\350\275\246\347\274\226\345\217\267,\345\217\221\350\275\246\346\227\266\351\227\264,\350\265\267\345\247\213\347\253\231,\347\273\210\347\202\271\347\253\231,\347\241\254\345\272\247\346\225\260,\347\241\254\345\215\247\346\225\260,\350\275\257\345\215\247\346\225\260,\346\200\273\345\272\247\344\275\215\346\225\260)</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("AdminDialog", "\346\265\217\350\247\210\346\211\200\346\234\211\345\212\250\350\275\246\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminDialog: public Ui_AdminDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDIALOG_H
