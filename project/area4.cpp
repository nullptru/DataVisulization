#include "area4.h"
#include <QtOpenGL/QtOpenGL>

Area4::Area4(QWidget *parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	height = width = cHeight = cWidth = 0; 
	leftButtonPressed = false;
	off_w = off_h = 0;
	label[0] = "Korea";
	label[1] = "CFR TaiWan";
	label[2] = "SE Asia";
	label[3] = "CFR India";
	label[4] = "CFR China";
	label[5] = "China Domestic";
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
	sSize = (cWidth >= cHeight) ? cHeight : cWidth;//画布大小

	off_w = (width - (sSize + DISFONT)) / 2 + DISFONT;
	off_h = (height - (sSize + DISFONT)) / 2 + DISFONT;

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, height, 0, -10, 10.0);
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
	glColor3f(1, 0.4, 0.6);

	if(!leftButtonPressed){
		for(int i = 0; i < NUMLINE; ++i){
			//数据归一化
			double aver1;
			double staDeviation1 = DataHelper::standardDeviation(dataArray, dataNum, draw_item[i], aver1);
			for(int j = i; j < NUMLINE; ++j)
			{
				//数据归一化
				double aver2;
				double staDeviation2 = DataHelper::standardDeviation(dataArray, dataNum, draw_item[j], aver2);

				glLoadIdentity();
				glTranslatef(off_w + Point[i], off_h + Point[j], -5);//重置观察矩阵

				//draw data
				glPointSize(2);
				glBegin(GL_POINTS);
				for(int k = 0; k < dataNum; ++k){
					glVertex2f(changeXY((dataArray[k][draw_item[i]] - aver1) / staDeviation1),
						changeXY((dataArray[k][draw_item[j]] - aver2) / staDeviation2));
				}
				glEnd();
			}
		}
	}
	else
	{
		glLoadIdentity();
		glTranslatef(off_w, off_h, -5);//重置观察矩阵

		//数据归一化
		double aver1;
		double staDeviation1 = DataHelper::standardDeviation(dataArray, dataNum, draw_item[index_x], aver1);

		double aver2;
		double staDeviation2 = DataHelper::standardDeviation(dataArray, dataNum, draw_item[index_y], aver2);
		//draw data
		glPointSize(2);
		glBegin(GL_POINTS);
		for(int k = 0; k < dataNum; ++k){
			glVertex2f(changeXY((dataArray[k][draw_item[index_x]] - aver1) / staDeviation1),
				changeXY((dataArray[k][draw_item[index_y]] - aver2) / staDeviation2));
		}
		glEnd();
	}
}

double Area4::changeXY(double tmp)
{
	return  (!leftButtonPressed) ? (Offset - 1) * (tmp + 7 / 2) / 7 : sSize * (tmp + 7 / 2) / 7;
}

void Area4::drawLabel()
{
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(8);
	fontnew.setBold(true);
	glColor3f(0.0,0.5,0.5);
	
	if(!leftButtonPressed){
		for(int i = 0; i < NUMLINE; i += 2){
			renderText(Point[i], -15, -5, label[i], fontnew);
		}
		for(int i = 1; i < NUMLINE; i += 2){
			renderText(-off_w, Point[i] + 30, -5, label[i], fontnew);
		}
	}
	else
	{
		renderText(Point[NUMLINE / 2], -15, -5, label[index_x], fontnew);
		renderText(-off_w, Point[NUMLINE / 2], -5, label[index_y], fontnew);
	}
}


void Area4::initializeAxis()
{
	glTranslatef(off_w, off_h, -5.0);//move (0 , 0) to (disfont, disfont)
	qglColor(Qt::black);
	Offset = sSize / NUMLINE;

	//draw x axises
	for (int i = 0; i <= NUMLINE; ++i)
	{
		Point[i] = Offset * i;
	}
	
	//draw relation color
	for (int i = 0; i < NUMLINE; ++i){
		for(int j = 0; j < NUMLINE; ++j)
		{
			double random = DataHelper::relation(dataArray, dataNum, draw_item[i], draw_item[j]);
			if (random<0.25){
				color[i][j].r = 180.0/255;
				color[i][j].g = 140.0/255;
				color[i][j].b = 251.0/255;
			}
			else if (random>0.25 && random<0.6){
				color[i][j].r = 159.0/255;
				color[i][j].g = 150.0/255;
				color[i][j].b = 38.0/255;
			}
			else if (random>0.6 && random<0.75){
				color[i][j].r = 6.0/255;
				color[i][j].g = 46.0/255;
				color[i][j].b = 183.0/255;
			}
			else{

				color[i][j].r = 191.0/255;
				color[i][j].g = 6.0/255;
				color[i][j].b = 34.0/255;

			}
			/*color[i][j].r = random;
			color[i][j].g = random;
			color[i][j].b = random;*/
		}
	}

	if(!leftButtonPressed){
		for(int i = 0; i < NUMLINE; ++i){//第i列
			for(int j = 0; j < NUMLINE; ++j){//第j行
				if(j < i)
					drawSingleSquare(Offset * i, j * Offset, Offset - 1, color[i][j]);
				//画网格
				glPointSize(1);
				glColor3f(0,0,0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(Offset * i, j * Offset);
				glVertex2f(Offset * i + Offset - 1, j * Offset);
				glVertex2f(Offset * i + Offset - 1, j * Offset + Offset - 1);
				glVertex2f(Offset * i, j * Offset + Offset - 1);
				glEnd();
			}
		}
	}
	else
	{
		drawSingleSquare(0, 0, Offset * NUMLINE, color[index_x][index_y]);
	}
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
		double x = event->x() - off_w;
		double y = event->y() - off_h;
		if(x < sSize && x > 0
			&& y < sSize && y > 0){
			if(!leftButtonPressed){
				index_x = x / Offset;
				index_y = y / Offset;
			}
			leftButtonPressed = !leftButtonPressed;
			updateGL();
		}
	}
}