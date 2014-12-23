/********************************************************************************
** Form generated from reading UI file 'mdi.ui'
**
** Created: Mon Dec 22 15:23:42 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDI_H
#define UI_MDI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MDIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MDIClass)
    {
        if (MDIClass->objectName().isEmpty())
            MDIClass->setObjectName(QString::fromUtf8("MDIClass"));
        MDIClass->resize(600, 400);
        menuBar = new QMenuBar(MDIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MDIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MDIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MDIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MDIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MDIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MDIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MDIClass->setStatusBar(statusBar);

        retranslateUi(MDIClass);

        QMetaObject::connectSlotsByName(MDIClass);
    } // setupUi

    void retranslateUi(QMainWindow *MDIClass)
    {
        MDIClass->setWindowTitle(QApplication::translate("MDIClass", "MDI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MDIClass: public Ui_MDIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDI_H
