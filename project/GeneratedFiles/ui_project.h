/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created: Tue Dec 23 15:40:04 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "area1.h"
#include "area2.h"
#include "area3.h"
#include "area4.h"

QT_BEGIN_NAMESPACE

class Ui_ProjectClass
{
public:
    QAction *action11;
    QAction *action12;
    QAction *action13;
    QAction *action21;
    QAction *action22;
    QAction *action23;
    QAction *action31;
    QAction *action32;
    QAction *action33;
    QAction *actionopen;
    QAction *actionclose;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Area4 *area4;
    Area2 *area2;
    Area3 *area3;
    Area1 *area1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_title1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_title2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_title3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_1;
    QLabel *label1_data;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label2_data;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *label3_data;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label_8;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QSlider *verticalSlider_4;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_14;
    QSlider *verticalSlider_6;
    QLabel *label_15;
    QGroupBox *groupBox_3;
    QLabel *label_16;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_17;
    QSlider *verticalSlider_7;
    QLabel *label_18;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectClass)
    {
        if (ProjectClass->objectName().isEmpty())
            ProjectClass->setObjectName(QString::fromUtf8("ProjectClass"));
        ProjectClass->resize(1193, 790);
        action11 = new QAction(ProjectClass);
        action11->setObjectName(QString::fromUtf8("action11"));
        action12 = new QAction(ProjectClass);
        action12->setObjectName(QString::fromUtf8("action12"));
        action13 = new QAction(ProjectClass);
        action13->setObjectName(QString::fromUtf8("action13"));
        action21 = new QAction(ProjectClass);
        action21->setObjectName(QString::fromUtf8("action21"));
        action22 = new QAction(ProjectClass);
        action22->setObjectName(QString::fromUtf8("action22"));
        action23 = new QAction(ProjectClass);
        action23->setObjectName(QString::fromUtf8("action23"));
        action31 = new QAction(ProjectClass);
        action31->setObjectName(QString::fromUtf8("action31"));
        action32 = new QAction(ProjectClass);
        action32->setObjectName(QString::fromUtf8("action32"));
        action33 = new QAction(ProjectClass);
        action33->setObjectName(QString::fromUtf8("action33"));
        actionopen = new QAction(ProjectClass);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionclose = new QAction(ProjectClass);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        centralWidget = new QWidget(ProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        area4 = new Area4(centralWidget);
        area4->setObjectName(QString::fromUtf8("area4"));

        gridLayout->addWidget(area4, 1, 1, 1, 1);

        area2 = new Area2(centralWidget);
        area2->setObjectName(QString::fromUtf8("area2"));

        gridLayout->addWidget(area2, 0, 1, 1, 1);

        area3 = new Area3(centralWidget);
        area3->setObjectName(QString::fromUtf8("area3"));

        gridLayout->addWidget(area3, 1, 0, 1, 1);

        area1 = new Area1(centralWidget);
        area1->setObjectName(QString::fromUtf8("area1"));
        horizontalLayout_2 = new QHBoxLayout(area1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox1 = new QGroupBox(area1);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        horizontalLayout_3 = new QHBoxLayout(groupBox1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_title1 = new QLabel(groupBox1);
        label_title1->setObjectName(QString::fromUtf8("label_title1"));
        label_title1->setLayoutDirection(Qt::LeftToRight);
        label_title1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title1->setWordWrap(true);

        horizontalLayout_3->addWidget(label_title1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(groupBox1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(groupBox1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 7);

        verticalLayout_4->addWidget(groupBox1);

        groupBox2 = new QGroupBox(area1);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_title2 = new QLabel(groupBox2);
        label_title2->setObjectName(QString::fromUtf8("label_title2"));
        label_title2->setLayoutDirection(Qt::LeftToRight);
        label_title2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title2->setWordWrap(true);

        horizontalLayout_4->addWidget(label_title2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_4 = new QPushButton(groupBox2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_6);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 7);

        verticalLayout_4->addWidget(groupBox2);

        groupBox3 = new QGroupBox(area1);
        groupBox3->setObjectName(QString::fromUtf8("groupBox3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_title3 = new QLabel(groupBox3);
        label_title3->setObjectName(QString::fromUtf8("label_title3"));
        label_title3->setLayoutDirection(Qt::LeftToRight);
        label_title3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title3->setWordWrap(true);

        horizontalLayout_5->addWidget(label_title3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_7 = new QPushButton(groupBox3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(groupBox3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(groupBox3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_9);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 7);

        verticalLayout_4->addWidget(groupBox3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        groupBox_4 = new QGroupBox(area1);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_1 = new QLabel(groupBox_4);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setTextFormat(Qt::PlainText);

        horizontalLayout_6->addWidget(label_1);

        label1_data = new QLabel(groupBox_4);
        label1_data->setObjectName(QString::fromUtf8("label1_data"));
        label1_data->setTextFormat(Qt::AutoText);
        label1_data->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label1_data);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::PlainText);

        horizontalLayout_7->addWidget(label_2);

        label2_data = new QLabel(groupBox_4);
        label2_data->setObjectName(QString::fromUtf8("label2_data"));
        label2_data->setTextFormat(Qt::PlainText);
        label2_data->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label2_data);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::PlainText);

        horizontalLayout_8->addWidget(label_3);

        label3_data = new QLabel(groupBox_4);
        label3_data->setObjectName(QString::fromUtf8("label3_data"));
        label3_data->setTextFormat(Qt::PlainText);
        label3_data->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label3_data);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_5);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));

        horizontalLayout_9->addWidget(groupBox_5);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 180, 72, 15));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 10, 26, 161));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);

        verticalSlider_4 = new QSlider(layoutWidget_2);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setMinimum(-10);
        verticalSlider_4->setMaximum(10);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_4->setInvertedAppearance(false);
        verticalSlider_4->setTickPosition(QSlider::NoTicks);

        verticalLayout_7->addWidget(verticalSlider_4);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_7->addWidget(label_10);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 180, 72, 15));
        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 10, 26, 161));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_9->addWidget(label_14);

        verticalSlider_6 = new QSlider(layoutWidget_3);
        verticalSlider_6->setObjectName(QString::fromUtf8("verticalSlider_6"));
        verticalSlider_6->setMinimum(-10);
        verticalSlider_6->setMaximum(10);
        verticalSlider_6->setOrientation(Qt::Vertical);
        verticalSlider_6->setInvertedAppearance(false);
        verticalSlider_6->setTickPosition(QSlider::NoTicks);

        verticalLayout_9->addWidget(verticalSlider_6);

        label_15 = new QLabel(layoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_9->addWidget(label_15);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 180, 72, 15));
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 10, 26, 161));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_10->addWidget(label_17);

        verticalSlider_7 = new QSlider(layoutWidget_4);
        verticalSlider_7->setObjectName(QString::fromUtf8("verticalSlider_7"));
        verticalSlider_7->setMinimum(-10);
        verticalSlider_7->setMaximum(10);
        verticalSlider_7->setOrientation(Qt::Vertical);
        verticalSlider_7->setInvertedAppearance(false);
        verticalSlider_7->setTickPosition(QSlider::NoTicks);

        verticalLayout_10->addWidget(verticalSlider_7);

        label_18 = new QLabel(layoutWidget_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_10->addWidget(label_18);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_6->addLayout(horizontalLayout);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 2);

        horizontalLayout_2->addWidget(groupBox_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        gridLayout->addWidget(area1, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        ProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1193, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        ProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProjectClass->setStatusBar(statusBar);

        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(action11);
        menu->addAction(action12);
        menu->addAction(action13);
        menu_2->addAction(action21);
        menu_2->addAction(action22);
        menu_2->addAction(action23);
        menu_3->addAction(action31);
        menu_3->addAction(action32);
        menu_3->addAction(action33);
        menu_4->addAction(actionopen);
        menu_4->addAction(actionclose);

        retranslateUi(ProjectClass);

        QMetaObject::connectSlotsByName(ProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectClass)
    {
        ProjectClass->setWindowTitle(QApplication::translate("ProjectClass", "Project", 0, QApplication::UnicodeUTF8));
        action11->setText(QApplication::translate("ProjectClass", "\346\214\207\346\225\260\345\271\263\346\273\221\346\263\225", 0, QApplication::UnicodeUTF8));
        action12->setText(QApplication::translate("ProjectClass", "\345\255\243\350\212\202\346\214\207\346\225\260\346\263\225", 0, QApplication::UnicodeUTF8));
        action13->setText(QApplication::translate("ProjectClass", "ARMA\346\263\225", 0, QApplication::UnicodeUTF8));
        action21->setText(QApplication::translate("ProjectClass", "BP\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        action22->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        action23->setText(QApplication::translate("ProjectClass", "GARCA\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
        action31->setText(QApplication::translate("ProjectClass", "BP+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        action32->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242+\345\255\243\350\212\202\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        action33->setText(QApplication::translate("ProjectClass", "GARCA + \346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        actionopen->setText(QApplication::translate("ProjectClass", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        actionclose->setText(QApplication::translate("ProjectClass", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        groupBox1->setTitle(QString());
        label_title1->setText(QApplication::translate("ProjectClass", "\345\215\225\345\217\230\351\207\217\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ProjectClass", "\346\214\207\346\225\260\345\271\263\346\273\221\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ProjectClass", "\345\255\243\350\212\202\346\214\207\346\225\260\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ProjectClass", "ARMA\346\263\225", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QString());
        label_title2->setText(QApplication::translate("ProjectClass", "\345\233\240\347\264\240\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ProjectClass", "BP\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ProjectClass", "GARCA\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
        groupBox3->setTitle(QString());
        label_title3->setText(QApplication::translate("ProjectClass", "\347\273\204\345\220\210\351\242\204\346\265\213\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("ProjectClass", "BP+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242+\345\255\243\350\212\202\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("ProjectClass", "GARCA+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        label_1->setText(QApplication::translate("ProjectClass", "\344\270\213\344\270\200\346\234\210", 0, QApplication::UnicodeUTF8));
        label1_data->setText(QApplication::translate("ProjectClass", "50", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProjectClass", "\344\270\213\344\272\214\346\234\210", 0, QApplication::UnicodeUTF8));
        label2_data->setText(QApplication::translate("ProjectClass", "300", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProjectClass", "\344\270\213\344\270\211\346\234\210", 0, QApplication::UnicodeUTF8));
        label3_data->setText(QApplication::translate("ProjectClass", "400", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QString());
        groupBox->setTitle(QString());
        label_8->setText(QApplication::translate("ProjectClass", "\344\270\223\345\256\266\347\273\217\351\252\214", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ProjectClass", "10", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        verticalSlider_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("ProjectClass", "-10", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_11->setText(QApplication::translate("ProjectClass", "\347\252\201\345\217\221\345\233\240\347\264\240", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ProjectClass", "10", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        verticalSlider_6->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("ProjectClass", "-10", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_16->setText(QApplication::translate("ProjectClass", "\345\277\203\347\220\206\345\233\240\347\264\240", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("ProjectClass", "10", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        verticalSlider_7->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("ProjectClass", "-10", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ProjectClass", "\345\215\225\345\217\230\351\207\217\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("ProjectClass", "\345\233\240\347\264\240\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("ProjectClass", "\347\273\204\345\220\210\351\242\204\346\265\213\346\263\225", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("ProjectClass", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectClass: public Ui_ProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H
