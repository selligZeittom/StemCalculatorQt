#include "Controller/databasemanager.h"
#include "Model/bike.h"
#include <QDebug>
#include <QJsonObject>
#include "Model/compute.h"


int main(int argc, char *argv[])
{
    qDebug() << "start of tests";
    /*
    DatabaseManager* dbManager = &(DatabaseManager::getInstance());
    Bike b1("vertex", 450, 520, 5, 8, 69.5);
    Bike b2("element", 460, 515, 5, 8, 69);
    QJsonObject bo1 = b1.getJsonFromBike();
    QJsonObject bo2 = b2.getJsonFromBike();
    dbManager->addBikeToDB(bo1);
    dbManager->addBikeToDB(bo2);
    dbManager->removeBikeFromDB(bo1);
    */

    QVector2D v1(0, 1);
    QVector2D v2(1,0);
    qDebug() << Compute::getScalarProduct(v1, v2) << "   " << Compute::getAngle(v1, v2)*180/M_PI;

}

