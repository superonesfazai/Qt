/********************************************************************************
** Form generated from reading UI file 'buyticketdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYTICKETDIALOG_H
#define UI_BUYTICKETDIALOG_H

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
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_BuyTicketDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_7;
    QPushButton *pushButton;

    void setupUi(QDialog *BuyTicketDialog)
    {
        if (BuyTicketDialog->objectName().isEmpty())
            BuyTicketDialog->setObjectName(QStringLiteral("BuyTicketDialog"));
        BuyTicketDialog->resize(428, 321);
        label = new QLabel(BuyTicketDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 101, 31));
        label_2 = new QLabel(BuyTicketDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 30, 101, 31));
        label_3 = new QLabel(BuyTicketDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 91, 31));
        label_4 = new QLabel(BuyTicketDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 90, 81, 31));
        label_5 = new QLabel(BuyTicketDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 81, 31));
        label_6 = new QLabel(BuyTicketDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 140, 91, 31));
        lineEdit = new QLineEdit(BuyTicketDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 113, 31));
        lineEdit_2 = new QLineEdit(BuyTicketDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 30, 113, 31));
        lineEdit_3 = new QLineEdit(BuyTicketDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 90, 113, 31));
        lineEdit_4 = new QLineEdit(BuyTicketDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 140, 113, 31));
        lineEdit_5 = new QLineEdit(BuyTicketDialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(280, 140, 113, 31));
        radioButton = new QRadioButton(BuyTicketDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(90, 220, 89, 21));
        radioButton_2 = new QRadioButton(BuyTicketDialog);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(180, 220, 89, 21));
        radioButton_3 = new QRadioButton(BuyTicketDialog);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(260, 220, 89, 21));
        checkBox = new QCheckBox(BuyTicketDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(300, 100, 71, 16));
        checkBox_2 = new QCheckBox(BuyTicketDialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(350, 100, 71, 16));
        label_7 = new QLabel(BuyTicketDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 190, 191, 21));
        pushButton = new QPushButton(BuyTicketDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 260, 191, 41));

        retranslateUi(BuyTicketDialog);

        QMetaObject::connectSlotsByName(BuyTicketDialog);
    } // setupUi

    void retranslateUi(QDialog *BuyTicketDialog)
    {
        BuyTicketDialog->setWindowTitle(QApplication::translate("BuyTicketDialog", "Dialog", 0));
        label->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204\347\231\273\345\275\225\347\224\250\346\210\267\345\220\215:", 0));
        label_2->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204\347\231\273\345\275\225\345\257\206\347\240\201:", 0));
        label_3->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204\347\234\237\345\256\236\345\247\223\345\220\215:", 0));
        label_4->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204\346\200\247\345\210\253:", 0));
        label_5->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204ID:", 0));
        label_6->setText(QApplication::translate("BuyTicketDialog", "\346\202\250\347\232\204\347\224\265\350\257\235\345\217\267\347\240\201:", 0));
        radioButton->setText(QApplication::translate("BuyTicketDialog", "\347\241\254\345\272\247", 0));
        radioButton_2->setText(QApplication::translate("BuyTicketDialog", "\347\241\254\345\215\247", 0));
        radioButton_3->setText(QApplication::translate("BuyTicketDialog", "\350\275\257\345\215\247", 0));
        checkBox->setText(QApplication::translate("BuyTicketDialog", "\347\224\267", 0));
        checkBox_2->setText(QApplication::translate("BuyTicketDialog", "\345\245\263", 0));
        label_7->setText(QApplication::translate("BuyTicketDialog", "\350\257\267\345\234\250\344\270\213\346\226\271\345\213\276\351\200\211\346\202\250\350\246\201\351\200\211\346\213\251\347\232\204\345\272\247\344\275\215\347\261\273\345\236\213", 0));
        pushButton->setText(QApplication::translate("BuyTicketDialog", "\347\241\256\345\256\232\350\256\242\347\245\250", 0));
    } // retranslateUi

};

namespace Ui {
    class BuyTicketDialog: public Ui_BuyTicketDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYTICKETDIALOG_H
