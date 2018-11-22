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
#include <QVector>

#include "gui_menu.h"

//define some dimensions for buttons
#define BTN1_WIDTH 150
#define BTN1_HEIGHT 50
#define BTN1_OFFSET_X_RIGHT 50

//define some dimensions for labels
#define LABEL_WIDTH 200
#define LABEL_HEIGHT 50
#define LABEL_X_OFFSET 20

//define some dimensions for line edit
#define LINEEDIT_WIDTH 50
#define LINEEDIT_HEIGHT 50
#define LINEEDIT_X_OFFSET (LABEL_X_OFFSET+LABEL_WIDTH+30)

//define some dimensions for the graphicalView
#define OFFSET_VIEW 5

//define numbers of items
#define N_BTN 4
#define N_LABEL 15
#define N_SLIDER 4
#define N_LINEDIT 7

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

    //4 vector of graphical objects
    QVector<QPushButton*> btnVector;
    QVector<QLabel*> labelVector;
    QVector<QLineEdit*> lineEditVector;
    QVector<QSlider*> sliderVector;

    enum btnId
    {
        ID_updateBtn = 0,
        ID_loadBtn = 1,
        ID_saveBtn = 2,
        ID_returnBtn = 3
    };

    enum labelId
    {
        ID_spacerLabel = 0,
        ID_lengthLabel = 1,
        ID_angleLabel = 2,
        ID_IdLabel = 3,
        ID_stemHeightLabel = 4,
        ID_hyLabel = 5,
        ID_hxLabel = 6,
        ID_headsetHeightLabel = 7,
        ID_headAngleLabel = 8,
        ID_stackLabel = 9,
        ID_reachLabel = 10
    };

    enum lineEditId
    {
        ID_stemHeightLineEdit = 1,
        ID_hyLineEdit = 2,
        ID_hxLineEdit = 3,
        ID_headsetHeightLineEdit = 4,
        ID_headAngleLineEdit = 5,
        ID_stackLineEdit = 6,
        ID_reachLineEdit = 7
    };



};

#endif // GUIDRAWING_H
