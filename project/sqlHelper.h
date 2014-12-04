#pragma once

#include <QtSql/QtSql>
#include <QSqlQuery>
#include "para.h"

class SqlHelper
{
public:
	SqlHelper();
	void initial();
	bool getSuccees();
	QSqlQuery getQuery();
	static void setAllQuery();
	
private:
	bool succees;
	QSqlDatabase db;
	//QSqlQuery query;
};