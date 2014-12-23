/********************************************************************************
** Form generated from reading UI file 'wid.ui'
**
** Created: Mon Dec 22 19:26:27 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WID_H
#define UI_WID_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *widClass)
    {
        if (widClass->objectName().isEmpty())
            widClass->setObjectName(QString::fromUtf8("widClass"));
        widClass->resize(600, 400);
        centralWidget = new QWidget(widClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 60, 75, 23));
        widClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(widClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        widClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(widClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        widClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(widClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        widClass->setStatusBar(statusBar);

        retranslateUi(widClass);

        QMetaObject::connectSlotsByName(widClass);
    } // setupUi

    void retranslateUi(QMainWindow *widClass)
    {
        widClass->setWindowTitle(QApplication::translate("widClass", "wid", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("widClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widClass: public Ui_widClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WID_H
