#ifndef PARA_H
#define PARA_H
#include <map>
#include <QString>
#include <QVector>
using std::map;
using std::pair;
struct Emotion
{
	int emotion;
	QString describe;
	QString state;
};

const int NUM = 6;
const int MAXDATA = 5000;
const int MAXDATACOL = 23;//date����ֳ������

// database information
const int ID = 0;
const int DateKey = 1;
const int KorKey = 2;
const int CFRTaiKey = 3; 
const int SEAsiaKey = 4;
const int CFRJanKey = 5;
const int CFRIndKey = 6;
const int CFRChiKey = 7;
const int CHiDomKey = 8;
const int CoalPriKey = 9;
const int TankPriKey = 10;//�״����޼�
const int OriPriKey = 11;//ԭ�ͼ۸�
const int ImPriKey = 12;
const int ImVolKey = 13;
const int OutPriKey = 14;
const int OutVolKey =15;
const int PMIKey = 16;
const int PPIKey = 17;
const int ProKey = 18;
const int AppconKey = 19;//���������

const int EmotionKey = 20;
const int DescribeKey = 21;
const int StateKey = 22;

const int Year = 0;
const int Mon = 1;

const int NumYear = 7;//for area2 and area3

const int INITIALYEAR = 2008;

extern double labelData[3];//����label����
extern double dataArray[MAXDATA][MAXDATACOL];
extern int DISFONT;//font size
extern int dataNum;

extern int index_x;
extern int index_y;

extern map<QString,Emotion *> emotion_map;
extern int draw_item[];//area3 �� area4��Ҫ��������
extern int press_button1;
extern QString fileName;
#endif