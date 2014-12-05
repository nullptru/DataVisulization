#ifndef PROJECT_H
#define PROJECT_H

#include <QtGui/QMainWindow>
#include "ui_project.h"
#include <QtGui/QMessageBox>
#include <QTimer>
#include "para.h"
#include <QString.h>
#include "sqlHelper.h"
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
	QString getString(int n);
	void WriteData();
public slots:
	void ExponentialSmo();
	void SeasonExp();
	void BpNeuralNet();
};

#endif // PROJECT_H
