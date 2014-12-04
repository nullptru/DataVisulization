#ifndef PARA_H
#define PARA_H

const int NUM = 6;
const int MAXDATA = 5000;
const int MAXDATACOL = 19;//date被拆分成年和月
// database information
const int ID = 0;
const int DateKey = 1;
const int KorKey = 2;
const int CFRTaiKey = 3;
const int SEAsiaKey = 4;
const int CFRIndKey = 5;
const int CFRChiKey = 6;
const int CHiDomKey = 7;
const int CoalPriKey = 8;
const int TankPriKey = 9;//甲醇出罐价
const int OriPriKey = 10;//原油价格
const int ImPriKey = 11;
const int ImVolKey = 12;
const int OutPriKey = 13;
const int OutVolKey =14;
const int PMIKey = 15;
const int PPIKey = 16;
const int ProKey = 17;
const int AppconKey = 18;//表观消费量

const int Year = 0;
const int Mon = 1;

extern double labelData[3];//三个label变量
extern double dataArray[MAXDATA][MAXDATACOL];
extern int DISFONT;//font size
extern int dataNum;

#endif