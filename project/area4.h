#ifndef AREA4_H
#define AREA4_H

#include <QGLWidget>
#include "sqlHelper.h"
#include "DataHelper.h"
#include "para.h"

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
	double changeY(double y);
	double changeX(double x);
	void drawLabel();
	void drawData();

	int *draw;
	double width;//windows width
	double height;
	double cWidth;//canvas width
	double cHeight;
	double sSize;//the smaller part of cWidth and cHeight
	double Point[NUMLINE + 1];
	double Offset;

	int index_x;
	int index_y;
	Color color[NUMLINE][NUMLINE];
	bool leftButtonPressed;
};

#endif // AREA4_H
