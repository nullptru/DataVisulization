#include "area4.h"
#include <QtOpenGL/QtOpenGL>

Area4::Area4(QWidget *parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	draw = new int[NUMLINE];
	int tmp[] = {KorKey, CFRTaiKey,SEAsiaKey, CFRIndKey, CFRChiKey, CHiDomKey };
	for(int i = 0; i < NUMLINE; ++i)
		draw[i] = tmp[i];
	
	height = width = cHeight = cWidth = 0; 
	leftButtonPressed = false;
	index_x = index_y = 0;

}

Area4::~Area4()
{
	
}

void Area4::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area4::resizeGL(int width, int height)
{
	this->width = width;
	this->height = height;
	cWidth = width - DISFONT;
	cHeight = height - DISFONT;
	sSize = (cWidth >= cHeight) ? cHeight : cWidth;

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, 0, height, -10, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void Area4::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initializeAxis();
	//draw labels in x and y axises
	drawLabel();
	//draw data
	drawData();

	glFlush();
}

void Area4::drawData()
{
	glColor3f(1, 0, 0);

	if(!leftButtonPressed){
		for(int i = 0; i < NUMLINE; ++i){
			for(int j = 0; j < NUMLINE; ++j)
			{
				glLoadIdentity();
				glTranslatef(Point[i] + DISFONT, Point[j] + DISFONT, -5);//重置观察矩阵

				//draw data
				glPointSize(2);
				glBegin(GL_POINTS);
				for(int k = 0; k < dataNum; ++k){
					glVertex2f(changeX(dataArray[k][draw[i]]), changeY(dataArray[k][draw[j]]));
				}
				/*query.first();
				do{
					glVertex2f(changeX(query.value(i).toDouble()), changeY(query.value(j).toDouble()));
				}while(query.next());*/

				glEnd();
			}
		}
	}
	else
	{
		glLoadIdentity();
		glTranslatef(DISFONT, DISFONT, -5);//重置观察矩阵

		//draw data
		glPointSize(2);
		glBegin(GL_POINTS);
		for(int k = 0; k < dataNum; ++k){
			glVertex2f(changeX(dataArray[k][draw[index_x]]), changeY(dataArray[k][draw[index_y]]));
		}
		/*query.first();
		do{
			glVertex2f(changeX(query.value(i).toDouble()), changeY(query.value(j).toDouble()));
		}while(query.next());*/

		glEnd();
	}
}
void Area4::readData()
{

}

double Area4::changeY(double y)
{
	return  (!leftButtonPressed) ? (y * (Offset - 1)) / 650 : (y * sSize) / 650;//(y * cHeight) / maxY;
}

double Area4::changeX(double x)
{
	return (!leftButtonPressed) ? (x * (Offset - 1)) / 650 : (x * sSize) / 650;
}

void Area4::drawLabel()
{
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(10);
	fontnew.setBold(true);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i < NUMLINE; ++i){
		renderText(Point[i], -15, -5, "data", fontnew);
		renderText(-15, Point[NUMLINE - i] - 5, -5, "d", fontnew);
		renderText(-15, Point[NUMLINE - i] - 12, -5, "a", fontnew);
		renderText(-15, Point[NUMLINE - i] - 20, -5, "t", fontnew);
	}

}

void Area4::initializeAxis()
{
	glTranslatef(DISFONT, DISFONT, -5.0);//move (0 , 0) to (disfont, disfont)
	qglColor(Qt::black);
	Offset = sSize / NUMLINE;

	//draw x axises
	for (int i = 0; i <= NUMLINE; ++i)
	{
		Point[i] = Offset * i;
		//glBegin(GL_LINES);
		//glVertex2f(0, Point[i]);
		//glVertex2f(cWidth, Point[i]);
		//glEnd();
	}
	
	//draw relation color
	for (int i = 0; i < NUMLINE; ++i)
		for(int j = 0; j < NUMLINE; ++j)
		{
			double random = DataHelper::relation(dataArray, dataNum, draw[i], draw[j]);
			color[i][j].r = random;
			color[i][j].g = random;
			color[i][j].b = random;
		}
	if(!leftButtonPressed){
		for(int i = 0; i < NUMLINE; ++i){
			for(int j = 0; j < NUMLINE; ++j){
				drawSingleSquare(Offset * i, j * Offset, Offset - 1, color[i][j]);
			}
		}
	}
	else
	{
		drawSingleSquare(0, 0, Offset * NUMLINE, color[index_x][index_y]);
	}
/*

	//draw y axises

	for (int i = 0; i <= NUMLINE; ++i)
	{
		Point[i] = Offset * i;
		glBegin(GL_LINES);
		glVertex2f(Point[i], 0);
		glVertex2f(Point[i], cHeight);
		glEnd();
	}*/
}

void Area4::drawSingleSquare(int x, int y, int len, Color color)
{
	glBegin(GL_QUADS);
	glColor3f(color.r,color.g, color.b);
	glVertex2f(x , y);
	glVertex2f(x + len, y);
	glVertex2f(x + len, y + len);
	glVertex2f(x , y + len);
	glEnd();
}


void Area4::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton)
	{
		//转换坐标
		double x = event->x() - DISFONT;
		double y = (height - event->y()) - DISFONT;
		if(x < sSize && x > 0
			&& y < sSize && y > 0){
			index_x = x / Offset;
			index_y = y / Offset;
			leftButtonPressed = !leftButtonPressed;
			updateGL();
		}
	}
}