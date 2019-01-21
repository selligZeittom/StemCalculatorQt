#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>

#include "Model/bike.h"

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
    void updateJsonFile(QJsonObject obj);

private:
    QVector <Bike> bikes;
};

#endif // DATABASEMANAGER_H
