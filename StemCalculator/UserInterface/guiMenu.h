#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>

//define some dimensions
#define BTN_WIDTH 200
#define BTN_HEIGHT 60
#define BTN_OFFSET_X 200
#define BTN_OFFSET_y 200
class GUI : public QWidget
{
    Q_OBJECT
public:
    explicit GUI(QWidget* parent = 0);
    virtual ~GUI();
    void initRelations();


private:
    //screen size attributes
    int width;
    int height;

    //buttons
    QPushButton* dbManagementButton;
    QPushButton* drawingScreenButton;
    QPushButton* computingScreenButton;

public slots:
    void dbManagementButtonClicked();
    void drawingScreenButtonClicked();
    void computingScreenButtonClicked();
};

#endif // GUI_H
