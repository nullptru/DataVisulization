#ifndef ONETEXT_H
#define ONETEXT_H

#include <QWidget>
#include "ui_onetext.h"

class onetext : public QWidget
{
	Q_OBJECT

public:
	onetext(QWidget *parent = 0);
	~onetext();

private:
	Ui::onetextClass ui;
};

#endif // ONETEXT_H
