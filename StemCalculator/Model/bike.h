#ifndef BIKE_H
#define BIKE_H

#include <QString>


class Bike
{
public:
    Bike();
    ~Bike();
    void setGeometry(QString* name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle);

private:
    QString* name;
    int stack;
    int reach;
    int spacerHeight;
    int headsetHeight;
    double steeringAngle;

};

#endif // BIKE_H
