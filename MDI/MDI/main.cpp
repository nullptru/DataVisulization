#include <QtGui/QApplication>
#include "mdi.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MDI w;
	w.show();
	return a.exec();
}
