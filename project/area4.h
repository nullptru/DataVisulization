#ifndef AREA4_H
#define AREA4_H

#include <QGLWidget>
#include "sqlHelper.h"
#include "DataHelper.h"
#include "para.h"
#include <qDebug.h>

const int NUMLINE = 6;

struct Color{
	float r;
	float g;
	float b;
	Color(){}
	Color(float rr, float gg, float bb){r = rr; g = gg; b =bb;}
};

class Area4 : public QGLWidget
{
	Q_OBJECT

public:
	Area4(QWidget *parent);
	~Area4();
	void readData();
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void drawSingleSquare(int x, int y, int len, Color color);
	//
	void mousePressEvent(QMouseEvent *);
private:
	void initializeAxis();
	double changeXY(double);
	void drawLabel();
	void drawData();

	double width;//windows width
	double height;
	double cWidth;//canvas width
	double cHeight;
	double sSize;//the smaller part of cWidth and cHeight
	double Point[NUMLINE + 1];
	double Offset;//坐标系内坐标的偏移

	double off_w;
	double off_h;//画布的偏移，使画布居中

	QString label[NUMLINE];
	Color color[NUMLINE][NUMLINE];
	bool leftButtonPressed;
};

#endif // AREA4_H
