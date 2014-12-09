#include "area2.h"
#include <QtOpenGL/QtOpenGL>
#include <qdatetime.h>

Area2::Area2(QWidget *parent)
	: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	MaxY = 10;
	xLabelN = NumYear;
	for(int i = 0; i < xLabelN; ++i){
		xLabel[i] = QString::number(i + 2008);
	}
}


void Area2::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area2::resizeGL(int width, int height)
{
	this->width = width;
	this->height = height;
	cWidth = width - DISFONT;
	cHeight = height -DISFONT;

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, 0, height, -10, 10.0);
	glMatrixMode(GL_MODELVIEW);
}


void Area2::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(DISFONT, DISFONT, -5.0);//move (0 , 0) to (disfont, disfont)
	qglColor(Qt::black);

	initializeAxis();

	//draw labels in x and y axises
	drawLabel();

	//draw data
	drawData();

	glFlush();
}

void Area2::getData(double data1[])
{
}

double Area2::changeY(double y)
{
	return (cHeight * (y + MaxY / 2) / MaxY);
}

void Area2::drawData()
{	
	glColor3f(1.0,0.0,0.0);
	glPointSize(2);

	//data need to draw
	int draw[] = {OriPriKey, CoalPriKey, PPIKey, TankPriKey, ImVolKey};
	int len = sizeof(draw) / sizeof(draw[0]);

	for(int j = 0; j < len; ++j){
		//数据归一化
		double aver;
		double staDeviation = DataHelper::standardDeviation(dataArray, dataNum, draw[j], aver);

		if(draw[j] == TankPriKey){
			glColor3f(1,0,0);
		}
		else{
			glColor3f(1. / (j + 2),1. / (j + 2),1. / (j + 2));
		}
		glBegin(GL_LINE_STRIP);
		
		for(int i = 0; i < dataNum; ++i)
		{
			glVertex2f(xPoint[(int)dataArray[i][Year] - 2008] + dataArray[i][Mon] * tinyxOffset,
				changeY((dataArray[i][draw[j]] - aver) / staDeviation));

		}
		if(draw[j] == TankPriKey && press_button1){
			glColor3f(0, 0, 1);
			for(int m = 0; m < 3; ++m){
				glVertex2f(xPoint[(int)dataArray[dataNum - 1][Year] - 2008] + (dataArray[dataNum - 1][Mon] + m + 1) * tinyxOffset,
					changeY((labelData[m] - aver) / staDeviation));
			}
		}
		glEnd();
	}
}

void Area2::initializeAxis()
{
	xOffset = cWidth / NumYear;
	yOffset = (cHeight - DISFONT) / NumYear;
	tinyxOffset = xOffset / 12;//each month

	for(int i = 0; i < NumYear; ++i)
		xPoint[i] = xOffset * i;
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(cWidth, 0);//draw x axis

	glVertex2f(0,0);
	glVertex2f(0,cHeight - DISFONT);
	glEnd();

	//draw x point
	for (int i = 1; i <= NumYear; ++i)
	{
		glBegin(GL_LINES);
		glVertex2f(0, yOffset * i);
		glVertex2f(DISFONT / 5, yOffset * i);
		glEnd();
	}

	//draw y point
	for (int i = 1; i <= NumYear; ++i)
	{
		glBegin(GL_LINES);
		glVertex2f(xPoint[i], 0);
		glVertex2f(xPoint[i], DISFONT / 5);
		glEnd();
	}
}

void Area2::drawLabel(){
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(10);
	fontnew.setBold(true);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i < xLabelN; ++i){
		renderText(xPoint[i] - 10, -15, -5, xLabel[i], fontnew);
	}
}