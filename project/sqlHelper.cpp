#include "sqlHelper.h"
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QSqlError> 
#include <QSqlQuery> 
#include <qdatetime.h>
#include <QDebug>

SqlHelper::SqlHelper()
{
}

void SqlHelper::initial()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");	
	db.setDatabaseName("pro");
	db.setUserName("root");
	db.setPassword("123");
	if (!db.open())
	{
		succees = false;
	}
	else
	{
		succees = true;
	}
}

bool SqlHelper::getSuccees()
{
	return succees;
}

QSqlQuery SqlHelper::getQuery()
{
	QSqlQuery query;
	query.exec("select `Kor`,`CFRTai`,`SEAsia`, `CFRJap`,`CFRInd`, `CFRChi` from `data` ");

	return query;
}

void SqlHelper::setAllQuery()
{
	QDate time;
	QSqlQuery query;
	query.exec("Select * from data");
	while(query.next())
	{
		for(int i = 1; i < MAXDATACOL - 2; ++i){
			if(i == DateKey){
				time = query.value(i).toDate();
				dataArray[dataNum][Year] = time.year();
				dataArray[dataNum][Mon] = time.month();
			}
			else
			{
				dataArray[dataNum][i] = query.value(i).toDouble();
			}
		}
		dataNum++;
	}
}

