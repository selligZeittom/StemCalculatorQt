#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <iostream>

class GUI_Drawing;
class GUI_Menu;

class ScreenManager
{

    friend class GUI_Drawing;
    friend class GUI_Menu;

public:
    ScreenManager();
    ~ScreenManager();
    void initRelations(GUI_Drawing* drawingGui, GUI_Menu* menuGui);


private:
    GUI_Drawing* theDrawingWindow;
    GUI_Menu* theMenuWindow;

    //screen size attributes
    int screenWidth;
    int screenHeight;
    int xOffset;
    int yOffset;
    const int APP_WIDTH = 1800;
    const int APP_HEIGHT = 1000;
};

#endif // SCREENMANAGER_H
