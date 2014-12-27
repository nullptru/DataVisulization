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
#include <textwidget.h>
#include <qmdiarea.h>
#include <qmdisubwindow.h>
#include <qlist.h>
#include <qtextstream.h>
#include <QTextEdit>
#include <QTableWidget>
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

	//Ԥ��ֵ�ŵ�λ��
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
	textwidget textwid;
	QTextEdit *text;
public slots:
	void ExponentialSmo();
	void SeasonExp();
	void BpNeuralNet();
	void Open();

	void changeExpertExp();
	void changeFactors();
	void changeMental();

	void addTableItem();
public:
	void settable();
	enum {row = 100,col= 2};
	QTableWidget *tab;
};

#endif // PROJECT_H
