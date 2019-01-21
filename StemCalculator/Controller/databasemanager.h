#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QDebug>

#include "Model/bike.h"

class DatabaseManager
{
public:
    static DatabaseManager& getInstance();
    void addBikeToDB(QJsonObject obj);

private:
    DatabaseManager();
    ~DatabaseManager();
    QJsonArray jsonBikeArray;

    //the one and only one dvb manager
    static DatabaseManager theDatabaseManager;
};

#endif // DATABASEMANAGER_H
