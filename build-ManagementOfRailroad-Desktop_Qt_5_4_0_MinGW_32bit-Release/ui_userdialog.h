/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *label_11;
    QPushButton *DeletePassengerButton;
    QLabel *label_12;
    QWidget *tab;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName(QStringLiteral("UserDialog"));
        UserDialog->resize(387, 311);
        tabWidget = new QTabWidget(UserDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 391, 321));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 70, 331, 71));
        DeletePassengerButton = new QPushButton(tab_2);
        DeletePassengerButton->setObjectName(QStringLiteral("DeletePassengerButton"));
        DeletePassengerButton->setGeometry(QRect(90, 190, 201, 51));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 30, 211, 21));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 71, 21));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 113, 21));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 81, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 60, 61, 21));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 61, 21));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 100, 71, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 140, 131, 21));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 230, 61, 21));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 180, 61, 21));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 180, 61, 21));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 230, 61, 21));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 60, 81, 20));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 60, 81, 20));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 100, 101, 20));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(260, 100, 91, 20));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(150, 140, 81, 20));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(70, 180, 131, 20));
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(280, 180, 81, 20));
        lineEdit_9 = new QLineEdit(tab);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(60, 230, 81, 20));
        lineEdit_10 = new QLineEdit(tab);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(240, 230, 81, 20));
        tabWidget->addTab(tab, QString());

        retranslateUi(UserDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QApplication::translate("UserDialog", "Dialog", 0));
        label_11->setText(QApplication::translate("UserDialog", "<html><head/><body><p><span style=\" font-size:12pt; color:#ff0000;\">\345\246\202\346\236\234\346\202\250\345\257\271\350\207\252\345\267\261\347\232\204\347\245\250\344\270\215\346\273\241\346\204\217,</span></p><p><span style=\" font-size:12pt; color:#ff0000;\">\345\217\257\344\273\245\346\214\211\344\270\213\351\235\242\347\232\204\351\200\200\347\245\250\351\224\256\350\277\233\350\241\214\351\200\200\347\245\250:</span></p></body></html>", 0));
        DeletePassengerButton->setText(QApplication::translate("UserDialog", "\351\200\200\350\256\242\350\207\252\345\267\261\347\232\204\347\245\250", 0));
        label_12->setText(QApplication::translate("UserDialog", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserDialog", "\351\200\200\350\256\242\350\207\252\345\267\261\347\232\204\347\245\250", 0));
        label->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215:", 0));
        label_2->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204\347\234\237\345\256\236\345\247\223\345\220\215:", 0));
        label_3->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204\346\200\247\345\210\253:", 0));
        label_4->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204ID:", 0));
        label_5->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204\346\211\213\346\234\272\345\217\267:", 0));
        label_6->setText(QApplication::translate("UserDialog", "\346\202\250\347\232\204\346\211\200\344\271\230\345\235\220\347\232\204\345\212\250\350\275\246\347\274\226\345\217\267:", 0));
        label_7->setText(QApplication::translate("UserDialog", "\347\273\210\347\202\271\347\253\231:", 0));
        label_8->setText(QApplication::translate("UserDialog", "\345\217\221\350\275\246\346\227\266\351\227\264:", 0));
        label_9->setText(QApplication::translate("UserDialog", "\345\272\247\344\275\215\347\261\273\345\236\213:", 0));
        label_10->setText(QApplication::translate("UserDialog", "\350\265\267\345\247\213\347\253\231:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserDialog", "\346\265\217\350\247\210\350\207\252\345\267\261\347\232\204\350\256\242\347\245\250\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
