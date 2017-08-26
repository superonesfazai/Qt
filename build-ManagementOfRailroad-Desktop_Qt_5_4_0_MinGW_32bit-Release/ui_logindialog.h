/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(307, 282);
        LoginDialog->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(LoginDialog);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 54, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 54, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 90, 151, 31));
        lineEdit->setStyleSheet(QStringLiteral("border-image: *url();"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 130, 151, 31));
        lineEdit_2->setStyleSheet(QStringLiteral("border-image: *url();"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(70, 160, 71, 31));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(170, 160, 71, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 190, 121, 31));
        pushButton->setStyleSheet(QStringLiteral("border-image: *url();"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 190, 121, 31));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: *url();"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 311, 81));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 230, 211, 20));
        LoginDialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginDialog);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 307, 23));
        LoginDialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginDialog);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginDialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginDialog);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginDialog->setStatusBar(statusBar);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QMainWindow *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\344\270\255\345\233\275\351\223\201\350\267\257\347\256\241\347\220\206\347\263\273\347\273\237V1.0", 0));
        label->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\257\206\347\240\201   :</span></p></body></html>", 0));
        checkBox->setText(QApplication::translate("LoginDialog", "\347\256\241\347\220\206\345\221\230", 0));
        checkBox_2->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", 0));
        pushButton->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        pushButton_2->setText(QApplication::translate("LoginDialog", "\346\270\270\345\256\242\350\256\242\347\245\250\347\233\264\346\216\245\347\202\271\346\255\244", 0));
        label_3->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><img src=\":/new/prefix1/Login2.JPG\"/></p></body></html>", 0));
        label_4->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" color:#ff0000;\">TextLabel</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
