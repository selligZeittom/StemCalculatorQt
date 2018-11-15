#ifndef GUIDRAWING_H
#define GUIDRAWING_H

#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>

#include "gui_menu.h"

//define some dimensions for buttons
#define BTN1_WIDTH 200
#define BTN1_HEIGHT 60
#define BTN1_OFFSET_X 200
#define BTN1_OFFSET_Y 200

//define some dimensions for buttons
#define LABEL_WIDTH 200
#define LABEL_HEIGHT 60
#define LABEL_OFFSET_X1 50
#define LABEL_OFFSET_X2 (screenWidth - LABEL_WIDTH/2)
#define LABEL_OFFSET_Y 200

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
    //the screen manager
    ScreenManager* theScreenManager;

    //style sheet for objects
    QString btnStylesheet;
    QString labelStylesheet;
    QString lineEditStylesheet;

    //graphical objects
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



};

#endif // GUIDRAWING_H
