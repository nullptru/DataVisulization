#include "wid.h"

wid::wid(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.pushbutton,SIGNAL(chicked),this,SLOT(Open()));
}

wid::~wid()
{

}

void wid::Open()
{

}