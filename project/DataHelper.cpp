#include "DataHelper.h"
#include <math.h>

double DataHelper::average(const double dataArray[][MAXDATACOL], int num, int col)
{
	double x = 0;
	for(int i = 0; i < num; i++)
	{
		x += dataArray[i][col];
	}
	return x / num;
}

//get the average by para 4
double DataHelper::standardDeviation(const double dataArray[][MAXDATACOL], int num, int col, double & aver)
{
	aver = DataHelper::average(dataArray, num, col);
	double res = 0;
	for(int i = 0; i < num; ++i)
	{
		res += (dataArray[i][col] - aver) * (dataArray[i][col] - aver);
	}
	return sqrt(res / num);
}


double DataHelper::relation(const double dataArray[][MAXDATACOL], int num, int col_a, int col_b)
{
	double r = 0;
	double x_a = average(dataArray, num, col_a);
	double x_b = average(dataArray, num, col_b);

	double a , b, c, tmp1, tmp2;
	a = b = c = 0;
	for(int i = 0; i < num; ++i)
	{
		tmp1 = dataArray[i][col_a] - x_a;
		tmp2 = dataArray[i][col_b] - x_b;
		a += tmp1 * tmp2;
		b += tmp1 * tmp1;
		c += tmp2 * tmp2;
	}
	r = a / (sqrt(b) * sqrt(c));
	return r;
}