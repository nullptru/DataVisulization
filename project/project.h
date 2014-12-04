#ifndef PROJECT_H
#define PROJECT_H

#include <QtGui/QMainWindow>
#include "ui_project.h"
#include <QtGui/QMessageBox>
#include <QTimer>
#include "para.h"
#include "sqlHelper.h"

class Project : public QMainWindow
{
	Q_OBJECT

public:
	Project(QWidget *parent = 0, Qt::WFlags flags = 0);
	void setData();
	QTimer *timer;
	~Project();

private:
	Ui::ProjectClass ui;
public slots:
	void readdata();
};

#endif // PROJECT_H
