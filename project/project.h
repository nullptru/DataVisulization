#ifndef PROJECT_H
#define PROJECT_H

#include <QtGui/QMainWindow>
#include <QMainWindow>
#include "ui_project.h"
#include <QtGui/QMessageBox>
#include <QTimer>
#include "para.h"
#include <QString.h>
#include "sqlHelper.h"
#include <QDebug>
#include <qfiledialog.h>
//#include <qtextedit.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>
#include <qlist.h>
#include <qmdiarea.h>
#include <qtextstream.h>
const int NN=100;

struct Time_methanol{
	QString timess;
	double methanol;
};
class Project : public QMainWindow
{
	Q_OBJECT

public:
	Project(QWidget *parent = 0, Qt::WFlags flags = 0);
	void setData();
	QTimer *timer;
	~Project();

	void Exponent();
	void Season();
	void BpNe();

	//预测值放的位置
	double labeldataSmo[3];
	double labeldataSeason[3];
	double labedataBp[3];

private:
	Ui::ProjectClass ui;
	QSqlQuery query;
	double meth_all[NN];
	Time_methanol time_methanol[NN];
	double smo1[NN];
	double smo2[NN];
	double smo3[NN];
	int len_methanol;
	
	void createActions();
	QString getString(int n);
	void WriteData();
	void loadFile(const QString &fileName);

	QString curFile;
	QMdiArea *mdiarea;
	QWidget *qwidget;
public slots:
	void ExponentialSmo();
	void SeasonExp();
	void BpNeuralNet();
	void Open();

	void changeExpertExp();
	void changeFactors();
	void changeMental();
};

#endif // PROJECT_H
