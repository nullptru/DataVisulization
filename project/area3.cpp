#include "area3.h"
#include <QtOpenGL/QtOpenGL>
#include <qdatetime.h>

Area3::Area3(QWidget *parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	MaxY = 10;
	xLabelN = NumYear;
	for(int i = 0; i < xLabelN; ++i){
		xLabel[i] = QString::number(i + 2008);
	}
}


void Area3::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area3::resizeGL(int width, int height)
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


void Area3::paintGL()
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

void Area3::getData(double data1[])
{
}

double Area3::changeY(double y)
{
	return (cHeight * (y + MaxY / 2) / MaxY);
}

void Area3::drawData()
{	
	glColor3f(1.0,0.0,0.0);
	glPointSize(2);

	int tmp[] = {index_x, index_y};
	int len;
	if(index_x == index_y){len = 1;}
	else len = 2;

	for(int i = 0; i < len; ++i){
		//数据归一化
		double aver;
		double staDeviation = DataHelper::standardDeviation(dataArray, dataNum, draw_item[tmp[i]], aver);

		
		glColor3f(1,0,0);

		glBegin(GL_LINE_STRIP);

		for(int j = 1; j < dataNum; ++j)
		{
			glVertex2f(xPoint[(int)dataArray[j][Year] - 2008] + dataArray[j][Mon] * tinyxOffset,
				changeY((dataArray[j][draw_item[tmp[i]]] - aver) / staDeviation));

		}

		glEnd();
	}
}


void Area3::initializeAxis()
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

void Area3::drawLabel(){
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(7);
	fontnew.setBold(true);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i < xLabelN; ++i){
		renderText(xPoint[i] - 10, -15, -5, xLabel[i], fontnew);
	}
}

/*#include "area3.h"
#include <QtOpenGL/QtOpenGL>

Area3::Area3(QWidget *parent)
	: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	height = width = cHeight = cWidth = 0; 
	maxY = 650;
}

Area3::~Area3()
{

}

void Area3::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area3::resizeGL(int width, int height)
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

void Area3::paintGL()
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

void Area3::drawData()
{
	for(int i = 0; i < dataNumYear; ++i){
		glBegin(GL_LINE_STRIP);
			glVertex2f(xPoint[0],changeY(dataArray[i][2]));
		for (int j = 2 + 1; j < NumYear; ++j)
		{
			glVertex2f(xPoint[j], changeY(dataArray[i][j]));
		}
			glVertex2f(xPoint[NumYear],changeY(dataArray[i][2]));
		glEnd();
	}
}

void Area3::readData()
{

}

double Area3::changeY(double y)
{
	return (y * cHeight) / maxY;
}

void Area3::drawLabel()
{
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(10);
	fontnew.setBold(true);
	glTranslated(0.0,0.0,0.15);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i <= NumYear; ++i){
		renderText(xPoint[i] - 15, -15, -5, "data", fontnew);
		renderText(xPoint[i] - 15, cHeight - 15, -5, "data1", fontnew);
	}
	
}

void Area3::initializeAxis()
{
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(cWidth, 0);//draw x axis
	glEnd();

	//draw y axises
	double xOffset = cWidth / NumYear;

	for (int i = 0; i <= NumYear; ++i)
	{
		xPoint[i] = xOffset * i;
		glBegin(GL_LINES);
		glVertex2f(xPoint[i], 0);
		glVertex2f(xPoint[i], cHeight - DISFONT);
		glEnd();
	}
}
*/