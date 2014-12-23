/********************************************************************************
** Form generated from reading UI file 'textwidget.ui'
**
** Created: Tue Dec 23 15:40:04 2014
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
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textwidgetClass
{
public:
    QPushButton *pushButtontext1;
    QPushButton *pushButtontext2;
    QTextEdit *Edittext1;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

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
        Edittext1->setGeometry(QRect(140, 0, 531, 441));
        groupBox = new QGroupBox(textwidgetClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 120, 151));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 89, 16));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 60, 89, 16));
        groupBox_2 = new QGroupBox(textwidgetClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 190, 120, 221));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 20, 81, 16));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 50, 71, 16));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 80, 71, 16));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 110, 71, 16));

        retranslateUi(textwidgetClass);

        QMetaObject::connectSlotsByName(textwidgetClass);
    } // setupUi

    void retranslateUi(QWidget *textwidgetClass)
    {
        textwidgetClass->setWindowTitle(QApplication::translate("textwidgetClass", "textwidget", 0, QApplication::UnicodeUTF8));
        pushButtontext1->setText(QApplication::translate("textwidgetClass", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButtontext2->setText(QApplication::translate("textwidgetClass", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("textwidgetClass", "\351\234\200\351\242\204\346\265\213\345\217\230\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("textwidgetClass", "\347\224\262\351\206\207\345\207\272\347\275\220\344\273\267", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("textwidgetClass", "\347\205\244\344\273\267", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("textwidgetClass", "\345\233\240\347\264\240\351\200\211\346\213\251\357\274\232", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("textwidgetClass", "CFR china", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("textwidgetClass", "\347\205\244\344\273\267", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("textwidgetClass", "\345\216\237\346\262\271", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("textwidgetClass", "PMI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class textwidgetClass: public Ui_textwidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTWIDGET_H
