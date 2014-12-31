#include "onetext.h"

onetext::onetext(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButtonadd1,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(ui.pushButtonadd2,SIGNAL(clicked()),this,SLOT(close()));
}

onetext::~onetext()
{

}
