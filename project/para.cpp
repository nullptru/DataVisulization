#include "para.h"
double labelData[3]={0,0,0};
double labeltemp[3]={0,0,0};
int dataNum = 0;
double dataArray[MAXDATA][MAXDATACOL];
int DISFONT = 30;

int index_x = 0;
int index_y = 0;
int draw_item[] = {KorKey, CFRTaiKey,SEAsiaKey, CFRIndKey, CFRChiKey, CHiDomKey };

int press_button1 = false;
map<QString, Emotion*> emotion_map;
QString fileName = NULL;
