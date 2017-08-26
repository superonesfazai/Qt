/********************************************************************************
** Form generated from reading UI file 'traininformation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININFORMATION_H
#define UI_TRAININFORMATION_H

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

class Ui_TrainInformation
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *satisfyButton;
    QPushButton *unsatisfyButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;

    void setupUi(QDialog *TrainInformation)
    {
        if (TrainInformation->objectName().isEmpty())
            TrainInformation->setObjectName(QStringLiteral("TrainInformation"));
        TrainInformation->resize(192, 239);
        label = new QLabel(TrainInformation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 71, 31));
        label_2 = new QLabel(TrainInformation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 31));
        label_3 = new QLabel(TrainInformation);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 71, 31));
        label_4 = new QLabel(TrainInformation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 71, 31));
        satisfyButton = new QPushButton(TrainInformation);
        satisfyButton->setObjectName(QStringLiteral("satisfyButton"));
        satisfyButton->setGeometry(QRect(10, 200, 75, 31));
        unsatisfyButton = new QPushButton(TrainInformation);
        unsatisfyButton->setObjectName(QStringLiteral("unsatisfyButton"));
        unsatisfyButton->setGeometry(QRect(100, 200, 75, 31));
        lineEdit = new QLineEdit(TrainInformation);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 71, 31));
        lineEdit_2 = new QLineEdit(TrainInformation);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 80, 121, 31));
        lineEdit_3 = new QLineEdit(TrainInformation);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(70, 120, 81, 31));
        lineEdit_4 = new QLineEdit(TrainInformation);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(70, 160, 81, 31));
        label_5 = new QLabel(TrainInformation);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 171, 31));

        retranslateUi(TrainInformation);

        QMetaObject::connectSlotsByName(TrainInformation);
    } // setupUi

    void retranslateUi(QDialog *TrainInformation)
    {
        TrainInformation->setWindowTitle(QApplication::translate("TrainInformation", "Dialog", 0));
        label->setText(QApplication::translate("TrainInformation", "\350\257\245\345\212\250\350\275\246\347\274\226\345\217\267:", 0));
        label_2->setText(QApplication::translate("TrainInformation", "\345\217\221\350\275\246\346\227\266\351\227\264:", 0));
        label_3->setText(QApplication::translate("TrainInformation", "\350\265\267\345\247\213\347\253\231:", 0));
        label_4->setText(QApplication::translate("TrainInformation", "\347\273\210\347\202\271\347\253\231:", 0));
        satisfyButton->setText(QApplication::translate("TrainInformation", "\346\273\241\346\204\217", 0));
        unsatisfyButton->setText(QApplication::translate("TrainInformation", "\344\270\215\346\273\241\346\204\217", 0));
        label_5->setText(QApplication::translate("TrainInformation", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TrainInformation: public Ui_TrainInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININFORMATION_H
