#include "factory.h"
#include "UserInterface/gui_menu.h"
#include "UserInterface/gui_drawing.h"
#include "UserInterface/screenmanager.h"
#include "UserInterface/gui_computing.h"
#include "UserInterface/gui_database.h"
#include "Controller/databasemanager.h"
#include "XF/xf.h"

Factory::Factory()
{
    XF::getInstance();

    theScreenManager = NULL;
    theMenuWindow = NULL;
    theComputingWindow = NULL;
    theDrawingWindow = NULL;
    theDatabaseWindow = NULL;
    theDatabaseManager = NULL;
}

Factory::~Factory()
{

}

void Factory::create()
{
    theScreenManager = new ScreenManager();
    theMenuWindow = new GUI_Menu();
    theComputingWindow = new GUI_Computing();
    theDrawingWindow = new GUI_Drawing();
    theDatabaseWindow = new GUI_Database();
    theDatabaseManager = &(DatabaseManager::getInstance());
}

void Factory::build()
{
    theMenuWindow->initRelations(theScreenManager);
    theComputingWindow->initRelations(theScreenManager);
    theDatabaseWindow->initRelations(theScreenManager);
    theDrawingWindow->initRelations(theScreenManager);

    theScreenManager->initRelations(theDrawingWindow, theMenuWindow, theComputingWindow, theDatabaseWindow);
}

void Factory::destroy()
{
    if(theComputingWindow)
    {
        delete theComputingWindow;
        theComputingWindow = NULL;
    }
    if(theMenuWindow)
    {
        delete theMenuWindow;
        theMenuWindow = NULL;
    }
    if(theDatabaseWindow)
    {
        delete theDatabaseWindow;
        theDatabaseWindow = NULL;
    }
    if(theDrawingWindow)
    {
        delete theDrawingWindow;
        theDrawingWindow = NULL;
    }
    if(theScreenManager)
    {
        delete theScreenManager;
        theScreenManager = NULL;
    }
}
