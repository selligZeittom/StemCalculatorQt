#include "bike.h"

Bike::Bike()
{
    this->name = "not defined yet";
    this->stack = 0;
    this->reach = 0;
    this->spacerHeight = 0;
    this->headsetHeight = 0;
    this->steeringAngle = 0;
}

Bike::Bike(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle)
{
    this->name = name;
    this->stack = stack;
    this->reach = reach;
    this->spacerHeight = spacerHeight;
    this->headsetHeight = headsetHeight;
    this->steeringAngle = steeringAngle;
}

Bike::~Bike()
{

}

void Bike::setGeometry(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle)
{
    this->name = name;
    this->stack = stack;
    this->reach = reach;
    this->spacerHeight = spacerHeight;
    this->headsetHeight = headsetHeight;
    this->steeringAngle = steeringAngle;
}

QJsonObject Bike::getJsonFromBike()
{
    QJsonObject bikeToJson;
    bikeToJson["name"] = this->name;
    bikeToJson["stack"] = this->stack;
    bikeToJson["reach"] = this->reach;
    bikeToJson["spacerHeight"] = this->spacerHeight;
    bikeToJson["headsetHeight"] = this->headsetHeight;
    bikeToJson["steeringAngle"] = this->steeringAngle;
    return bikeToJson;
}

QString Bike::getString() const
{
    QString res = "[name] : ";
    res.append(this->name);
    res.append("\t\t\t[reach] : ");
    res.append(QString::number(this->reach)).append("mm");
    res.append("\t\t[stack] : ");
    res.append(QString::number(this->stack)).append("mm");
    res.append("\t\t[steeringAngle] : ");
    res.append(QString::number(this->steeringAngle)).append("deg");
    res.append("\t\t[spacer height] : ");
    res.append(QString::number(this->spacerHeight)).append("mm");
    res.append("\t\t[headset height] : ");
    res.append(QString::number(this->headsetHeight)).append("mm");
    return res;
}
