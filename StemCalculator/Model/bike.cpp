#include "bike.h"

Bike::Bike()
{
    this->name = new QString("not defined yet");
    this->stack = 0;
    this->reach = 0;
    this->spacerHeight = 0;
    this->headsetHeight = 0;
    this->steeringAngle = 0;
}

Bike::~Bike()
{

}

void Bike::setGeometry(QString *name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle)
{
    this->name = name;
    this->stack = stack;
    this->reach = reach;
    this->spacerHeight = spacerHeight;
    this->headsetHeight = headsetHeight;
    this->steeringAngle = steeringAngle;
}
