#ifndef GUIDRAWING_H
#define GUIDRAWING_H

#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QGraphicsView>
#include <QSlider>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>

#include "gui_menu.h"

//define some dimensions for buttons
#define BTN1_WIDTH 150
#define BTN1_HEIGHT 50
#define BTN1_OFFSET_X_RIGHT 50
#define BTN1_OFFSET_Y 15

//define some dimensions for labels
#define LABEL_WIDTH 150
#define LABEL_HEIGHT 50
#define LABEL_Y_OFFSET 20

//define some dimensions for the graphicalView
#define OFFSET_VIEW 5

class ScreenManager;

class GUI_Drawing : public QWidget
{
    Q_OBJECT
public:
    explicit GUI_Drawing(QWidget* parent = 0);
    virtual ~GUI_Drawing();
    void initRelations(ScreenManager* screenManager);

public slots:
    void menuButtonClicked();


private:
    //offset between components
    int yOffset;

    //the screen manager
    ScreenManager* theScreenManager;

    //style sheet for objects
    QString btnStylesheet;
    QString labelStylesheet;
    QString lineEditStylesheet;

    //graphical objects
    QGraphicsView* drawingView;
    QGraphicsScene* scnView;
    QPushButton* updateResultButton;
    QPushButton* saveGeometryButton;
    QPushButton* loadGeometryButton;
    QPushButton* menuButton;
    QLabel* reachLabel;
    QLabel* stackLabel;
    QLabel* headAngleLabel;
    QLabel* headsetHeightLabel;
    QLabel* stemHeightLabel;
    QLabel* bikeNameLabel;
    QLabel* handlebarXLabel;
    QLabel* handlebarYLabel;
    QLabel* angleLabel;
    QLabel* lengthLabel;
    QLabel* spacerLabel;
    QLabel* displayAngleLabel;
    QLabel* displayLengthLabel;
    QLineEdit* reachLineEdit;
    QLineEdit* stackLineEdit;
    QLineEdit* headAngleLineEdit;
    QLineEdit* headsetHeightLineEdit;
    QLineEdit* stemHeightLineEdit;
    QLineEdit* bikeNameLineEdit;
    QLineEdit* handlebarXLineEdit;
    QLineEdit* handlebarYLineEdit;
    QSlider* angleSlider;
    QSlider* lengthSlider;
    QSlider* spacerHeightSlider;
    QSlider* zoomSlider;



};

#endif // GUIDRAWING_H
