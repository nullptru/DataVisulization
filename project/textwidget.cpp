#include "textwidget.h"

textwidget::textwidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButtontext1,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(ui.pushButtontext2,SIGNAL(clicked()),this,SLOT(close()));
}

textwidget::~textwidget()
{

}

void textwidget::writeData()
{
	//text = new QTextEdit(this);
	////setCentralWidget(text);
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		return;
	}
	//文本写出到widget文本框
	QTextStream infile(&file);
	QString line = infile.readLine();
	QStringList list1;
	ui.Edittext1->append(line);
	while(!line.isNull()){
		line = infile.readLine();
		list1 = line.split(" ",QString::SkipEmptyParts);
		for (int i =0; i<list1.size(); ++i)
		{
			qDebug()<<list1.at(i).toLocal8Bit().constData()<<endl;
		}
		ui.Edittext1->append(line);
		qDebug()<<line;
	}
}