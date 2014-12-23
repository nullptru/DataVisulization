#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QtGui/QMainWindow>
#include <QWidget>
#include "ui_textwidget.h"
#include <qtextedit.h>
#include <QFile>
#include <QStringList>
#include <qtextstream.h>
#include "para.h"
#include <QDebug>
#include <qmdisubwindow.h>
class textwidget : public QWidget
{
	Q_OBJECT

public:
	textwidget(QWidget *parent = 0);
	~textwidget();
	void writeData();

private:
	Ui::textwidgetClass ui;
	QTextEdit *text;

};

#endif // TEXTWIDGET_H
