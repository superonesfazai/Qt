/********************************************************************************
** Form generated from reading UI file 'datamanager.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMANAGER_H
#define UI_DATAMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DataManager
{
public:

    void setupUi(QDialog *DataManager)
    {
        if (DataManager->objectName().isEmpty())
            DataManager->setObjectName(QStringLiteral("DataManager"));
        DataManager->resize(400, 300);

        retranslateUi(DataManager);

        QMetaObject::connectSlotsByName(DataManager);
    } // setupUi

    void retranslateUi(QDialog *DataManager)
    {
        DataManager->setWindowTitle(QApplication::translate("DataManager", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DataManager: public Ui_DataManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMANAGER_H
