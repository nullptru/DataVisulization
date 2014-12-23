#ifndef WID_H
#define WID_H

#include <QtGui/QMainWindow>
#include "ui_wid.h"

class wid : public QMainWindow
{
	Q_OBJECT

public:
	wid(QWidget *parent = 0, Qt::WFlags flags = 0);
	~wid();

private:
	Ui::widClass ui;
private slots:
	void Open();
};

#endif // WID_H
