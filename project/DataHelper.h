#pragma once
#include "para.h"
class DataHelper
{
public :
	static double average(const double dataArray[][MAXDATACOL], int num, int col);
	static double standardDeviation(const double dataArray[][MAXDATACOL], int num, int col, double &aver);
	static double relation(const double dataArray[][MAXDATACOL], int num, int col_a, int col_b);
};