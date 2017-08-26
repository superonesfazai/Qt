/********************************************************************************
** Form generated from reading UI file 'tourist.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURIST_H
#define UI_TOURIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Tourist
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Tourist)
    {
        if (Tourist->objectName().isEmpty())
            Tourist->setObjectName(QStringLiteral("Tourist"));
        Tourist->resize(243, 251);
        lineEdit = new QLineEdit(Tourist);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 60, 113, 31));
        lineEdit_2 = new QLineEdit(Tourist);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 120, 113, 31));
        lineEdit_3 = new QLineEdit(Tourist);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 180, 113, 31));
        pushButton = new QPushButton(Tourist);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 60, 101, 31));
        pushButton_2 = new QPushButton(Tourist);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 120, 101, 31));
        pushButton_3 = new QPushButton(Tourist);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 180, 101, 31));
        label = new QLabel(Tourist);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 191, 21));
        label_2 = new QLabel(Tourist);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 220, 171, 20));

        retranslateUi(Tourist);

        QMetaObject::connectSlotsByName(Tourist);
    } // setupUi

    void retranslateUi(QDialog *Tourist)
    {
        Tourist->setWindowTitle(QApplication::translate("Tourist", "Dialog", 0));
        pushButton->setText(QApplication::translate("Tourist", "\346\214\211\345\212\250\350\275\246\347\274\226\345\217\267\346\237\245\350\257\242", 0));
        pushButton_2->setText(QApplication::translate("Tourist", "\346\214\211\350\265\267\345\247\213\347\253\231\346\237\245\350\257\242", 0));
        pushButton_3->setText(QApplication::translate("Tourist", "\346\214\211\347\273\210\347\202\271\347\253\231\346\237\245\350\257\242", 0));
        label->setText(QApplication::translate("Tourist", "<html><head/><body><p><span style=\" font-size:11pt; color:#0000ff;\">\350\257\267\345\234\250\345\257\271\345\272\224\344\275\215\347\275\256\350\276\223\345\205\245\345\206\205\345\256\271\346\237\245\350\257\242:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("Tourist", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Tourist: public Ui_Tourist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURIST_H
