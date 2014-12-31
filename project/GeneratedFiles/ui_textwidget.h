/********************************************************************************
** Form generated from reading UI file 'textwidget.ui'
**
** Created: Wed Dec 31 14:27:21 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTWIDGET_H
#define UI_TEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textwidgetClass
{
public:
    QPushButton *pushButtontext1;
    QPushButton *pushButtontext2;
    QTextEdit *Edittext1;

    void setupUi(QWidget *textwidgetClass)
    {
        if (textwidgetClass->objectName().isEmpty())
            textwidgetClass->setObjectName(QString::fromUtf8("textwidgetClass"));
        textwidgetClass->resize(670, 519);
        pushButtontext1 = new QPushButton(textwidgetClass);
        pushButtontext1->setObjectName(QString::fromUtf8("pushButtontext1"));
        pushButtontext1->setGeometry(QRect(420, 470, 75, 23));
        pushButtontext2 = new QPushButton(textwidgetClass);
        pushButtontext2->setObjectName(QString::fromUtf8("pushButtontext2"));
        pushButtontext2->setGeometry(QRect(550, 470, 75, 23));
        Edittext1 = new QTextEdit(textwidgetClass);
        Edittext1->setObjectName(QString::fromUtf8("Edittext1"));
        Edittext1->setGeometry(QRect(0, 0, 671, 441));

        retranslateUi(textwidgetClass);

        QMetaObject::connectSlotsByName(textwidgetClass);
    } // setupUi

    void retranslateUi(QWidget *textwidgetClass)
    {
        textwidgetClass->setWindowTitle(QApplication::translate("textwidgetClass", "textwidget", 0, QApplication::UnicodeUTF8));
        pushButtontext1->setText(QApplication::translate("textwidgetClass", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButtontext2->setText(QApplication::translate("textwidgetClass", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class textwidgetClass: public Ui_textwidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTWIDGET_H
