#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>

class ScreenManager;
class GUI_Menu;
class GUI_Computing;
class GUI_Drawing;
class GUI_Database;
class DatabaseManager;

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
    DatabaseManager* theDatabaseManager;

};

#endif // FACTORY_H
