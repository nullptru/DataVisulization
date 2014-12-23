#include "project.h"

Project::Project(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setWindowState(Qt::WindowMaximized);
	//从数据库中读取甲醇时间和出罐价
	
	query.exec("Select Date, TankPri from data");
	setData();
	createActions();
}


void Project::createActions()
{
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),ui.area2,SLOT(updateGL()));
	connect(timer,SIGNAL(timeout()),ui.area3,SLOT(updateGL()));
	QObject::connect(ui.actionopen,SIGNAL(triggered()),this,SLOT(Open()));
	QObject::connect(ui.actionclose,SIGNAL(triggered()),this,SLOT(close()));
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(ExponentialSmo()));
	QObject::connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(SeasonExp()));
	QObject::connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(BpNeuralNet()));
	ui.pushButton_2->setEnabled(false);
	ui.pushButton_4->setEnabled(false);
	ui.pushButton_5->setEnabled(false);
	ui.pushButton_6->setEnabled(false);
	ui.pushButton_7->setEnabled(false);
	ui.pushButton_8->setEnabled(false);
	ui.pushButton_9->setEnabled(false);
	ui.action13->setEnabled(false);
	ui.action21->setEnabled(false);
	ui.action22->setEnabled(false);
	ui.action23->setEnabled(false);
	ui.action31->setEnabled(false);
	ui.action32->setEnabled(false);
	ui.action33->setEnabled(false);
	QObject::connect(ui.verticalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(changeExpertExp()));
	QObject::connect(ui.verticalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(changeFactors()));
	QObject::connect(ui.verticalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(changeMental()));
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
	labelData[0] = 50;
	labelData[1] = 300;
	labelData[2] = 400;
	int kk=0;
	query.first();
	do 
	{
		QDate time = query.value(0).toDate();
		int year = time.year();
		int month = time.month();
		time_methanol[kk].timess = getString(year)+getString(month);
		meth_all[kk] = query.value(1).toDouble();
		time_methanol[kk].methanol = meth_all[kk];
		qDebug() << time_methanol[kk].timess<<meth_all[kk] ;
		kk++;
	} while (query.next());
	len_methanol = kk;
	//指数平滑法预测
	Exponent();
	//季节指数法
	Season();
	//bp神经网络
	//BpNe();
}
void Project::Exponent()
{
	double a = 0.4;
	int j = 0;
	smo1[0] = (meth_all[0]+meth_all[1]+meth_all[2])/3;
	smo3[0] = smo2[0] = smo1[0];
	while (j<len_methanol)
	{
		smo1[j+1] = a * meth_all[j] + (1-a) * smo1[j];
		smo2[j+1] = a * smo1[j+1] + (1-a) * smo2[j];
		smo3[j+1] = a * smo2[j+1] + (1-a) * smo3[j];
		j++;
	}
	double a1 = 3 *smo1[j] - 3 * smo2[j] + smo3[j];
	double b1 = (a/(2*(1-a)*(1-a))) * ((6-5*a)*smo1[j]- 2*(5-4*a)*smo2[j]+(4-3*a)*smo3[j]);
	double c1 = (a*a)/(2*(1-a)*(1-a))*(smo1[j]-2*smo2[j]+smo3[j]);
	labeldataSmo[0] = a1+b1+c1;
	labeldataSmo[1] = a1+2*b1+2*c1;
	labeldataSmo[2] = a1+3*b1+3*c1;
}

void Project::Season()
{
	Time_methanol year_methanol[NN];
	double aveall=0;
	int numyear = len_methanol/12;
	for (int i = 0;i<numyear ;i++)
	{
		int m = 12*i;
		year_methanol[i].timess = time_methanol[m].timess.left(4);
		double sum = 0;
		for (int j = m;j< (m+12) ; j++)
		{
			sum += time_methanol[j].methanol;
			aveall += time_methanol[j].methanol;
		}
		year_methanol[i].methanol =  sum;
	}
	aveall = aveall/(numyear*12);//计算所有年的平均数值
	//year指数预测
	double a = 0.3;
	int k = 0;
	double smo[NN];
	smo[0]= (year_methanol[0].methanol+year_methanol[1].methanol+year_methanol[2].methanol)/3;
	while (k<numyear)
	{
		smo[k+1]= a*year_methanol[k].methanol+(1-a)*smo[k];
		k++;
	}
	double YuceYear = smo[k];
	double YuceYear2 = a*year_methanol[k-1].methanol+(1-a)*smo[k];
	//qDebug() <<numyear<< YuceYear ;
	//季节预测
	double smotha[12];
	for (int k1 = 0;k1<12;k1++)
	{
		double avemouth = 0;
		for (int k2 = k1;k2<len_methanol;)
		{
			avemouth +=time_methanol[k2].methanol;
			k2+=12;	
		}
		avemouth = avemouth/numyear;
		smotha[k1] = avemouth/aveall;
	}
	//输出预测的24个月的值
	double monthForecast[24];
	for (int k3=0 ; k3<12;k3++)
	{
		monthForecast[k3] = smotha[k3]*YuceYear/12;
	}
	double monthForecast1[12];
	for (int k3=12; k3<24;k3++)
	{
		monthForecast[k3] = smotha[k3]*YuceYear2/12;
	}
	//输出
	labeldataSeason[0]=monthForecast[len_methanol%12];
	labeldataSeason[1]=monthForecast[len_methanol%12+1];
	labeldataSeason[2]=monthForecast[len_methanol%12+2];

}

void Project::BpNe()
{

}

QString Project::getString( int n )
{
	QString str = QString::number(n,10);
	return str;


}
void Project::ExponentialSmo()
{
	press_button1 = true;
	labelData[0]=labeldataSmo[0];
	labelData[1]=labeldataSmo[1];
	labelData[2]=labeldataSmo[2];
	WriteData();
}

void Project::SeasonExp()
{
	labelData[0]=labeldataSeason[0];
	labelData[1]=labeldataSeason[1];
	labelData[2]=labeldataSeason[2];
	WriteData();
}

void Project::BpNeuralNet()
{
}

void Project::WriteData()
{
	ui.label1_data->setText(QString::number(labelData[0]));
	ui.label2_data->setText(QString::number(labelData[1]));
	ui.label3_data->setText(QString::number(labelData[2]));
}

void Project::Open()
{
	fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty()){
		loadFile(fileName);
	}

}
void Project::loadFile(const QString &fileName1)
{
	QFile file(fileName1);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Recent Files"),
			tr("Cannot read file %1:\n%2.")
			.arg(fileName1)
			.arg(file.errorString()));
		return;
	}
	textwid.move(100,100);
	textwid.show();
	textwid.writeData();
	/*text = new QTextEdit(this);
	setCentralWidget(text);
	QTextStream infile(&file);
	QString line = infile.readLine();
	text->setGeometry(QRect(20,20,300,300));
	while(!line.isNull()){
		line = infile.readLine();
	    text->append(line);
		qDebug()<<line;
	}*/
}

void Project::changeExpertExp()
{
	labeltemp[0]= ui.verticalSlider_4->value();
	ui.label1_data->setText(QString::number(labelData[0]+labeltemp[0]+labeltemp[1]+labeltemp[2]));
}

void Project::changeFactors()
{
	labeltemp[1] = ui.verticalSlider_6->value();
	ui.label1_data->setText(QString::number(labelData[0]+labeltemp[0]+labeltemp[1]+labeltemp[2]));
}

void Project::changeMental()
{
	labeltemp[2]= ui.verticalSlider_7->value();
	ui.label1_data->setText(QString::number(labelData[0]+labeltemp[0]+labeltemp[1]+labeltemp[2]));
}
