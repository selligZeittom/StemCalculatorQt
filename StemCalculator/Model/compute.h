#ifndef COMPUTE_H
#define COMPUTE_H

#include <QVector2d>
#include <QPoint>
#include <QVector>
#include <math.h>

class Compute
{
public:
    Compute();
    ~Compute();
    static double getScalarProduct(QVector2D v1, QVector2D v2);
    static double getAngle(QVector2D v1, QVector2D v2);
    static QVector<double> getStem(QVector<double> specs); //used to the main computation

    //IDs for the vector
    enum stem_ID{
        lengthStem,
        angleStem
    };

    enum geometry_ID{
        hx,
        hy,
        reach,
        stack,
        angle,
        headsetAndSpacer,
        stemHeight
    };

};

#endif // COMPUTE_H
