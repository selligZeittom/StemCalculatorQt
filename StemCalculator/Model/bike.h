#ifndef BIKE_H
#define BIKE_H

#include <QString>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>


class Bike
{
public:
    Bike();
    Bike(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle);
    ~Bike();
    void setGeometry(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle);
    QJsonObject getJsonFromBike();

private:
    QString name;
    int stack;
    int reach;
    int spacerHeight;
    int headsetHeight;
    double steeringAngle;

};

#endif // BIKE_H
