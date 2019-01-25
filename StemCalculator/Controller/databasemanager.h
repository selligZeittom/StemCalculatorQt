#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QDebug>
#include <QString>

#include "Model/bike.h"

class DatabaseManager
{
public:
    static DatabaseManager& getInstance();
    void addBikeToDB(QJsonObject obj);
    bool removeBikeFromDB(QJsonObject obj);
    QVector<Bike> getBikesFromDB();

private:
    DatabaseManager();
    ~DatabaseManager();
    void writeFile();
    QJsonArray jsonBikeArray;

    //is it the first time that we are checking into db ?
    bool readForTheFirstTime;

    //the one and only one dvb manager
    static DatabaseManager theDatabaseManager;
};

#endif // DATABASEMANAGER_H
