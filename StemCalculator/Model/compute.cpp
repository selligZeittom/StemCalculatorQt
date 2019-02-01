#include "compute.h"

/*
 * return the scalar product of 2 vectors
 */
double Compute::getScalarProduct(QVector2D v1, QVector2D v2)
{
    return (v1.x() * v2.x() + v1.y() * v2.y());
}

/*
 * get the angle between 2 vectors in !!! RAD !!!
 */
double Compute::getAngle(QVector2D v1, QVector2D v2)
{
    if(v1.length() == 0 || v2.length() == 0)
    {
        return 0;
    }
    return acos((getScalarProduct(v1, v2)/(v1.length()*v2.length())));
}

/*
 * used to get the characteristics of the stem
 *
 *
 *
 *                                                  ___________________________________________________________
 *                                                 |                    |                         /            \
 *                                                 |          |         |                        /       |      \
 *                                                 |        _ . _       |                       /      _ . _     \
 *                                                 |          |         |                       \        |       /
 *                                                 |       (sx, sy)     |                        \   (hx, hy)   /
 *                                                 |____________________|_________________________\____________/
 *                                                  |                  |   ^
 *                                                  |                  |   |
 *                                                  |_______  |  ______|   |
 * _________________________________________________|_____  _ . _  ____|___|_
 *                                                            |        |   ^
 *                                                    (reach, stack)   |   | spacer + headset
 *                                                                     |
 *                                                                     |
 * _____________________________________________                       |
 *                                              /                      |
 *                                             /                       |
 *                                            /                        |
 *                                           /                         |
 *                                          /                          |
 *                                         /                           |
 *                                        /                            |
 *                                       /                             |
 *                                      /                              |
 *                                     /                               |
 *                                    /                                |
 *                                   /                                 |
 *                                  /                                  |
 *                                 /                 __________________|
 *                                /                 /
 *                               /                 /
 *                              /                 /
 *
 *
 *
 */
QVector<double> Compute::getStem(QVector<double> specs)
{
    //result vector
    QVector<double> res;

    //first adapt from degrees to radians
    specs.at(angle) = specs.at(angle) / 180 *M_PI;

    //divide the stem height by 2
    specs.at(stemHeight)/= 2;

    //get the x pos of the stem
    double stemX = specs.at(reach) - (cos(specs.at(angle)) * specs.at(headsetAndSpacer) +
                                      cos(specs.at(angle)) * specs.at(stemHeight));

    //get the y pos of the stem
    doubel stemY = specs.at(stack) + (sin(specs.at(angle)) * specs.at(headsetAndSpacer) +
                                      sin(specs.at(angle)) * specs.at(stemHeight));

    //create 2 points, one on the frame, on the top of direction, and the other one on the stem
    QPoint originPoint(specs.at(reach), specs.at(stack));
    QPoint stemPoint(stemX, stemY);
    QVector2D frameToStem(originPoint, stemPoint);

    //get the deltas in X and Y
    double deltaX = specs.at(hx) - stemX;
    double deltaY = specs.at(hy) - stemY;

    //specs are not realizable
    if(deltaX < 35)
    {
        res.at(lengthStem) = -1;
        res.at(angleStem) = 90;
        return res;
    }
    else
    {
        //create a point that is placed on the center of the handlebar
        QPoint handlebarPoint(specs.at(hx), specs.at(hy));
        QVector2D stemToHandlebar(stemPoint, handlebarPoint);
        .....
    }

