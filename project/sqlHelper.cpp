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
	db.setDatabaseName("project");
	db.setUserName("root");
	db.setPassword("123456");
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
	QString key;
	query.exec("Select * from data");
	while(query.next())
	{
		key = ""; 
		for(int i = 1; i < MAXDATACOL - 2; ++i){
			if(i == DateKey){
				time = query.value(i).toDate();
				dataArray[dataNum][Year] = time.year();
				dataArray[dataNum][Mon] = time.month();
				QString tmp = (time.month() > 10) ? (QString::number(time.month())) :
					("0" + QString::number(time.month()));
				key = QString::number(time.year()) + tmp;
			}
			else if (i >= MAXDATACOL - 3)
			{ 
				Emotion *emotion = new Emotion();
				emotion->emotion = query.value(i).toInt();
				emotion->describe = query.value(i + 1).toString();
				emotion->state = query.value(i + 2).toString();
				emotion_map.insert(pair<QString, Emotion*>(key, emotion));
				break;
			}
			else
			{
				dataArray[dataNum][i] = query.value(i).toDouble();
			}
		}
		dataNum++;
	}
}

