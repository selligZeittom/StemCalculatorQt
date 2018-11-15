#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <iostream>

#include "XF/ism.h"

class GUI_Drawing;
class GUI_Menu;
class GUI_Computing;
class GUI_Database;

class ScreenManager : public ISM
{

    friend class GUI_Drawing;
    friend class GUI_Menu;

public:
    ScreenManager();
    ~ScreenManager();
    void initRelations(GUI_Drawing* drawingGui, GUI_Menu* menuGui, GUI_Computing* computingGui, GUI_Database* databaseGui);

    // ISM interface
public:
    virtual bool processEvent(XFEvent *event);

private:
    GUI_Drawing* theDrawingWindow;
    GUI_Menu* theMenuWindow;
    GUI_Computing* theComputingWindow;
    GUI_Database* theDatabaseWindow;

    //screen size attributes
    int screenWidth;
    int screenHeight;
    int xOffset;
    int yOffset;
    const int APP_WIDTH = 1800;
    const int APP_HEIGHT = 1000;

    //states of the ISM
    enum STATE_SCREEN_MANAGER
    {
        ST_MENU_WINDOW,ST_COMPUTING_WINDOW,ST_DRAWING_WINDOW,ST_DATABASE_WINDOW
    };

    //events of the ISM
    enum EVENT_SCREEN_MANAGER
    {
        EV_GOTO_DRAWING, EV_GOTO_COMPUTING, EV_GOTO_DATABASE, EV_GOTO_MENU
    };

    //current state of the ISM
    STATE_SCREEN_MANAGER currentStateISM;

};

#endif // SCREENMANAGER_H
