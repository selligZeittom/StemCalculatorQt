#ifndef BIKE_H
#define BIKE_H

#include <QString>
#include <QJsonObject>
#include <QListWidgetItem>


class Bike : public QListWidgetItem
{
public:
    Bike();
    Bike(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle);
    ~Bike();
    void setGeometry(QString name, int stack, int reach, int spacerHeight, int headsetHeight, double steeringAngle);
    QJsonObject getJsonFromBike();
    QString getString() const;

private:
    QString name;
    int stack;
    int reach;
    int spacerHeight;
    int headsetHeight;
    double steeringAngle;

};

#endif // BIKE_H
