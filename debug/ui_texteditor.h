/********************************************************************************
** Form generated from reading UI file 'texteditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDITOR_H
#define UI_TEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextEditor
{
public:
    QTextEdit *textEdit;
    QPushButton *save;
    QPushButton *clear;
    QPushButton *undo;
    QPushButton *redo;
    QPushButton *findtext;

    void setupUi(QWidget *TextEditor)
    {
        if (TextEditor->objectName().isEmpty())
            TextEditor->setObjectName(QString::fromUtf8("TextEditor"));
        TextEditor->resize(592, 471);
        textEdit = new QTextEdit(TextEditor);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 40, 551, 381));
        save = new QPushButton(TextEditor);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(370, 430, 91, 31));
        clear = new QPushButton(TextEditor);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(280, 430, 91, 31));
        undo = new QPushButton(TextEditor);
        undo->setObjectName(QString::fromUtf8("undo"));
        undo->setGeometry(QRect(180, 430, 81, 31));
        redo = new QPushButton(TextEditor);
        redo->setObjectName(QString::fromUtf8("redo"));
        redo->setGeometry(QRect(100, 430, 81, 31));
        findtext = new QPushButton(TextEditor);
        findtext->setObjectName(QString::fromUtf8("findtext"));
        findtext->setGeometry(QRect(20, 10, 81, 31));

        retranslateUi(TextEditor);

        QMetaObject::connectSlotsByName(TextEditor);
    } // setupUi

    void retranslateUi(QWidget *TextEditor)
    {
        TextEditor->setWindowTitle(QApplication::translate("TextEditor", "Text Editor", nullptr));
        save->setText(QApplication::translate("TextEditor", "Save", nullptr));
        clear->setText(QApplication::translate("TextEditor", "Clear", nullptr));
        undo->setText(QApplication::translate("TextEditor", "Undo", nullptr));
        redo->setText(QApplication::translate("TextEditor", "Redo", nullptr));
        findtext->setText(QApplication::translate("TextEditor", "finder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextEditor: public Ui_TextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDITOR_H
