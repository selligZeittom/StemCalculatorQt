#include "databasemanager.h"

DatabaseManager DatabaseManager::theDatabaseManager;

DatabaseManager &DatabaseManager::getInstance()
{
    return theDatabaseManager;
}

DatabaseManager::DatabaseManager()
{

}

DatabaseManager::~DatabaseManager()
{

}

void DatabaseManager::addBikeToDB(QJsonObject obj)
{
    jsonBikeArray.append(obj);

    QJsonDocument jsonDoc(jsonBikeArray);

    QString filename = "database/bikes.json";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << jsonDoc.toJson(QJsonDocument::Indented).data() << endl;
        qDebug() << "wrote the new bike";
    }

}
