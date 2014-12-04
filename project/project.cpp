#include "project.h"

Project::Project(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setData();
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),ui.area2,SLOT(updateGL()));
	connect(timer,SIGNAL(timeout()),ui.area3,SLOT(updateGL()));
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(readdata()));
	timer->start(10);
}

Project::~Project()
{
	
}

void Project::setData()
{
	/*labelData[0] = ui.label1_data->text().toDouble();
	labelData[1] = ui.label2_data->text().toDouble();
	labelData[2] = ui.label3_data->text().toDouble();
	ui.area2->getData(labelData);*/
	labelData[0] = 100;
	labelData[1] = 30;
	labelData[2] = 50;
}

void Project::readdata()
{
	ui.label1_data->setText(QString::number(labelData[0]));
	ui.label2_data->setText(QString::number(labelData[1]));
	ui.label3_data->setText(QString::number(labelData[2]));

}