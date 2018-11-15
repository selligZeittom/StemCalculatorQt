#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

class ScreenManager;
class GUI_Menu;
class GUI_Computing;
class GUI_Drawing;
class GUI_Database;

class Factory
{
public:
    Factory();
    ~Factory();
    void create();
    void build();
    void destroy();

private:
    ScreenManager* theScreenManager;
    GUI_Menu* theMenuWindow;
    GUI_Computing* theComputingWindow;
    GUI_Drawing* theDrawingWindow;
    GUI_Database* theDatabaseWindow;

};

#endif // FACTORY_H
