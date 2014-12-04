#include "project.h"
#include "sqlHelper.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	SqlHelper db;
	
	db.initial();

	//启动程序时访问数据库
	SqlHelper::setAllQuery();

	QApplication a(argc, argv);
	Project w;
	w.show();
	return a.exec();
}
