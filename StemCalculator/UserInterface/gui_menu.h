#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <iostream>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>

//define some dimensions
#define BTN_HEIGHT 80
#define BTN_NUMBER 3
#define BTN_WIDTH 250
#define BTN_SPACE 200
#define BTN_Y_POS 200

class ScreenManager;

class GUI_Menu : public QWidget
{
    Q_OBJECT
public:
    explicit GUI_Menu(QWidget* parent = 0);
    virtual ~GUI_Menu();
    void initRelations(ScreenManager* screenManager);

private:
    //the screen manager
    ScreenManager* theScreenManager;

    //style sheet for objects
    QString btnStylesheet;

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
