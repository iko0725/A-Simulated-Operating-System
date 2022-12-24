/********************************************************************************
** Form generated from reading UI file 'opening.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENING_H
#define UI_OPENING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Opening
{
public:

    void setupUi(QDialog *Opening)
    {
        if (Opening->objectName().isEmpty())
            Opening->setObjectName(QString::fromUtf8("Opening"));
        Opening->resize(400, 300);

        retranslateUi(Opening);

        QMetaObject::connectSlotsByName(Opening);
    } // setupUi

    void retranslateUi(QDialog *Opening)
    {
        Opening->setWindowTitle(QApplication::translate("Opening", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Opening: public Ui_Opening {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENING_H
