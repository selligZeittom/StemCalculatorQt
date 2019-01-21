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

void DatabaseManager::writeFile()
{
    QJsonDocument jsonDoc(jsonBikeArray);
    QString filename = "database/bikes.json";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        file.resize(0);
        qDebug() << jsonDoc.toJson(QJsonDocument::Indented).data();
        stream << jsonDoc.toJson(QJsonDocument::Indented).data() << endl;
        qDebug() << "wrote the new bike";
    }
}

void DatabaseManager::addBikeToDB(QJsonObject obj)
{
    jsonBikeArray.append(obj);
    writeFile();
}

bool DatabaseManager::removeBikeFromDB(QJsonObject obj)
{
    for(int i = 0; i < jsonBikeArray.count(); i++)
    {
        if(jsonBikeArray.at(i) == obj)
        {
            jsonBikeArray.removeAt(i);
            writeFile();
            return true;
        }
    }
    return false;
}

QVector<Bike> DatabaseManager::getBikesFromDB()
{
    QVector<Bike> bikes;
    QString filename = "database/bikes.json";
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    auto jsonData = file.readAll();
    auto json = QJsonDocument::fromJson(jsonData);
    if(json.isArray())
    {
        auto array = json.array();
        for(auto value : array)
        {
            if(value.isObject())
            {
                auto object = value.toObject();
                QString name = object["name"].toString();
                int reach = object["reach"].toInt();
                int stack = object["stack"].toInt();
                int spacerHeight = object["spacerHeight"].toInt();
                int headsetHeight = object["headsetHeight"].toInt();
                double steeringAngle = object["steeringAngle"].toDouble();

                Bike b(name, stack, reach, spacerHeight, headsetHeight, steeringAngle);
                bikes.append(b);
            }
        }
    }
    return bikes;
}
