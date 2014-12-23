#ifndef MDI_H
#define MDI_H

#include <QtGui/QMainWindow>
#include "ui_mdi.h"

class MDI : public QMainWindow
{
	Q_OBJECT

public:
	MDI(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MDI();

private:
	Ui::MDIClass ui;
};

#endif // MDI_H
