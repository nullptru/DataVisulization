#include "project.h"

Project::Project(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//setWindowState(Qt::WindowMaximized);
	//�����ݿ��ж�ȡ�״�ʱ��ͳ��޼�
	
	query.exec("Select Date, TankPri from data");
	setData();
	settable();
	createActions();
}
Project::~Project()
{
}
void Project::settable()
{
	tab = new QTableWidget(ui.tab2);
	tab->setRowCount(row);
	tab->setColumnCount(col);
	tab->setGeometry (10,60,500,500);
	//���ú��ǩ
	QColor color;
	QStringList headerLabels;
	headerLabels<<"�״����޼�"<<"C2";

	tab->setHorizontalHeaderLabels(headerLabels);
	tab->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	//�����ݱ�ǩ
	QStringList rowLabels;
	for (int i=0; i<row; i++)
	{
			rowLabels<<time_methanol[i].timess;
	}
	tab->setVerticalHeaderLabels(rowLabels);
	tab->setSelectionBehavior(QAbstractItemView::SelectItems);
	//���ñ༭��ʽ
	tab->setEditTriggers(QAbstractItemView::DoubleClicked);
	//���ñ������
	for (int i=0; i<len_methanol;i++)
	{
		QTableWidgetItem *item0, *item1;
		item0 = new QTableWidgetItem;
		item1 = new QTableWidgetItem;

		QString txt = QString("%1").arg(time_methanol[i].methanol);
		item0->setText(txt);
		item0->setBackgroundColor(Qt::gray);
		tab->setItem(i, 0,item0);
		
		txt =QString("%1").arg((i+1)*2);
		item1->setText(txt);
		tab->setItem(i, 1,item1);
	}
}
void Project::createActions()
{
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),ui.area2,SLOT(updateGL()));
	connect(timer,SIGNAL(timeout()),ui.area3,SLOT(updateGL()));
	//�ļ���
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(openChoice()));
	//����ѡ��
	QObject::connect(ui.pushButton_12,SIGNAL(clicked()),this,SLOT(chooseFunction()));
	//Ӱ������
	QObject::connect(ui.pushButton1,SIGNAL(clicked()),this,SLOT(changeFactors()));
	QObject::connect(ui.comboBox_3,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(changeFactorsType(const QString &)));
	//δ������
	QObject::connect(ui.pushButton4,SIGNAL(clicked()),this,SLOT(futureTrend()));
	//���������
	QObject::connect(ui.pushButtonadd1,SIGNAL(clicked()),this,SLOT(addTableItem()));
	//combobox���
	QObject::connect(ui.comboBox,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(cboSel(const QString &)));
	QObject::connect(ui.pushButton_12,SIGNAL(clicked()),this,SLOT(cboSelect()));
	//
	timer->start(10);

}
void Project::setData()
{
	/*labelData[0] = ui.label1_data->text().toDouble();
	labelData[1] = ui.label2_data->text().toDouble();
	labelData[2] = ui.label3_data->text().toDouble();
	ui.area2->getData(labelData);*/
	choose[0]= "ָ��ƽ����";
	choose[1]= "����ָ����";
	choose[2]= "ARMA��";
	choose[3]= "Bp������";
	choose[4]= "С��������";
	choose[5]= "GARCHģ��";
	choose[6]= "Bp+ָ��ƽ��";
	choose[7]= "С��+����ָ��ƽ��";
	choose[8]= "GARCH+ָ��ƽ��";
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
	//ָ��ƽ����Ԥ��
	Exponent();
	//����ָ����
	Season();
	//bp������
	//BpNe();
}


void Project::chooseFunction()
{
	if (indexChoose==0){
		ExponentialSmo();
	}else if (indexChoose==1){
		SeasonExp();
	}
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

void Project::openChoice()
{
	QString str;
	str = ui.comboBox_5->currentText();
	if ((QString::compare(str,"��")) == 0)
	{
		Open();
	}
	if ((QString::compare(str,"���һ����¼")) == 0)
	{
		addItem();
	}
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
	aveall = aveall/(numyear*12);//�����������ƽ����ֵ
	//yearָ��Ԥ��
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
	//����Ԥ��
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
	//���Ԥ���24���µ�ֵ
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
	//���
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
	ui.label4_data->setText(QString::number(labelData[0]));
	ui.label5_data->setText(QString::number(labelData[1]));
	ui.label6_data->setText(QString::number(labelData[2]));
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

void Project::addItem()
{
	addonetext.show();
}
void Project::changeFactors()
{
	int labeltemp= ui.horizontalSlider1->value();
	ui.label1_data->setText(QString::number(labelData[0]+labeltemp));
}
void Project::changeFactorsType( const QString & txt )
{
	QString str = txt;
	qDebug()<<txt;
}
void Project::futureTrend()
{
	QString str;
	str = ui.comboBox_4->currentText();
	double labeltemp1,labeltemp2;
	if((QString::compare(str,"һֱ����"))==0)
	{
		labeltemp1 = labelData[1]+30;
		labeltemp2 = labelData[2]+30; 
		ui.label2_data->setText(QString::number(labeltemp1));
		ui.label3_data->setText(QString::number(labeltemp2));
	}else if ((QString::compare(str,"���Ǻ��"))==0)
	{
		labeltemp1 = labelData[1]+30;
		labeltemp2 = labelData[2]-30; 
		ui.label2_data->setText(QString::number(labeltemp1));
		ui.label3_data->setText(QString::number(labeltemp2));
	}else if((QString::compare(str,"һֱ�µ�"))==0)
	{
		labeltemp1 = labelData[1]-30;
		labeltemp2 = labelData[2]-30; 
		ui.label2_data->setText(QString::number(labeltemp1));
		ui.label3_data->setText(QString::number(labeltemp2));
	}else{
		labeltemp1 = labelData[1]-30;
		labeltemp2 = labelData[2]+30; 
		ui.label2_data->setText(QString::number(labeltemp1));
		ui.label3_data->setText(QString::number(labeltemp2));
	}
}
void Project::addTableItem()
{
		QTableWidgetItem *item0, *item1;
		item0 = new QTableWidgetItem;
		item1 = new QTableWidgetItem;
		QString a1 = ui.lineEditadd1->text();
		QString txt = QString("%1").arg(a1);
		item0->setText(txt);
		//item0->setBackgroundColor(Qt::gray);
		tab->setItem(len_methanol, 0,item0);

		txt =QString("%1").arg(len_methanol+1);
		item1->setText(txt);
		tab->setItem(len_methanol, 1,item1);
}

void Project::cboSelect()
{
	QString str ;
	str = ui.comboBox_2->currentText();
	for (int i =0;i<CHOOSE;i++)
		if ((QString::compare(str,choose[i]))==0)
		{	indexChoose = i;
			break;
		}
	qDebug()<<str<<indexChoose;
}

void Project::cboSel( const QString & txt)
{
	QString str = txt;
	qDebug()<<str;
	ui.comboBox_2->clear();
	if ((QString::compare(str,"������Ԥ��"))==0)
	{
		ui.comboBox_2->addItem(QWidget::tr("ָ��ƽ��"));
		ui.comboBox_2->addItem(QWidget::tr("����ָ����"));
		ui.comboBox_2->addItem(QWidget::tr("ARMA��"));
	}else if ((QString::compare(str,"����Ԥ��"))==0)
	{
		ui.comboBox_2->addItem(QWidget::tr("Bp������"));
		ui.comboBox_2->addItem(QWidget::tr("С��������"));
		ui.comboBox_2->addItem(QWidget::tr("GARCHģ��"));
	}else{
		ui.comboBox_2->addItem(QWidget::tr("Bp+ָ��ƽ��"));
		ui.comboBox_2->addItem(QWidget::tr("С��+����ָ��ƽ��"));
		ui.comboBox_2->addItem(QWidget::tr("GARCH+ָ��ƽ��"));
	}

}