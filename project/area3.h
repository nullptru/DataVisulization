#ifndef AREA3_H
#define AREA3_H

#include <QSqlQuery>
#include <QGLWidget>
#include "DataHelper.h"
#include "para.h"

class Area3 : public QGLWidget
{
	Q_OBJECT
public:
	explicit Area3(QWidget *parent = 0);
	void getData(double[]);
private:
	void initializeAxis();
	double changeY(double);
	void drawData();
	void drawLabel();

	double xPoint[NumYear + 1];//x axis point
	double xOffset;
	double yOffset;
	double tinyxOffset;

	QString xLabel[NumYear + 1];
	QString yLabel[NumYear + 1];
	int xLabelN;
	int yLabelN;

	int width;//windows width
	int height;
	int cWidth;//canvas width
	int cHeight;
	int MaxY;
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
signals:

	public slots:

};

#endif // AREA3_H
