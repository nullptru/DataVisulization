#include "project.h"
#include "sqlHelper.h"
#include <QTextCodec>
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	SqlHelper db;
	
	db.initial();
	
	//��������ʱ�������ݿ�
	SqlHelper::setAllQuery();
	QTextCodec *gbk = QTextCodec::codecForName("gb18030");
	QTextCodec::setCodecForTr(gbk);
	QTextCodec::setCodecForLocale(gbk);
	QTextCodec::setCodecForCStrings(gbk);

	QApplication a(argc, argv);
	Project w;
	w.show();
	return a.exec();
}
