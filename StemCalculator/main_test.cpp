#include "Controller/databasemanager.h"
#include "Model/bike.h"
#include <QDebug>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    qDebug() << "start of tests";
    DatabaseManager* dbManager = &(DatabaseManager::getInstance());
    Bike b1("vertex", 450, 520, 5, 8, 69.5);
    Bike b2("element", 460, 515, 5, 8, 69);
    QJsonObject bo1 = b1.getJsonFromBike();
    QJsonObject bo2 = b2.getJsonFromBike();
    dbManager->addBikeToDB(bo1);
    dbManager->addBikeToDB(bo2);
    dbManager->removeBikeFromDB(bo1);


}
