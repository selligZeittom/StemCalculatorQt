#include "screenmanager.h"
#include "gui_menu.h"
#include "gui_drawing.h"
#include "gui_computing.h"
#include "gui_database.h"

ScreenManager::ScreenManager()
{
    //get the dimension of the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->theDrawingWindow = NULL;
    this->theMenuWindow = NULL;
    this->theComputingWindow = NULL;
    this->theDatabaseWindow = NULL;

    this->screenHeight = screenGeometry.height();
    this->screenWidth = screenGeometry.width();
    this->xOffset = (screenWidth - APP_WIDTH) / 2;
    this->yOffset = (screenHeight - APP_HEIGHT) / 2;

    //set the initial state
    this->currentStateISM = ST_MENU_WINDOW;
}

ScreenManager::~ScreenManager()
{

}

void ScreenManager::initRelations(GUI_Drawing *drawingGui, GUI_Menu *menuGui, GUI_Computing *computingGui, GUI_Database *databaseGui)
{
    this->theDrawingWindow = drawingGui;
    this->theMenuWindow = menuGui;
    this->theComputingWindow = computingGui;
    this->theDatabaseWindow = databaseGui;
}

bool ScreenManager::processEvent(XFEvent *event)
{
    //used to say if the event is used or not
    bool processed = false;

    //store the current state
    STATE_SCREEN_MANAGER oldStateISM = currentStateISM;

    /*
     * /onTransition:
     */
    switch (currentStateISM)
    {
    case ST_MENU_WINDOW:
        //if the computing button is pressed
        if(event->getID() == EV_GOTO_COMPUTING)
        {

        }
        //if the drawing button is pressed
        else if(event->getID() == EV_GOTO_DRAWING)
        {

        }
        //if the database button is pressed
        else if (event->getID() == EV_GOTO_DATABASE)
        {

        }

        break;
    case ST_DRAWING_WINDOW:

        break;
    case ST_COMPUTING_WINDOW:

        break;
    case ST_DATABASE_WINDOW:

        break;
    }

    if(oldStateISM != currentStateISM)
    {
        processed = true;

        /*
         * /onEntry:
         */
        switch (currentStateISM)
        {
        case ST_MENU_WINDOW:

            break;
        case ST_DRAWING_WINDOW:

            break;
        case ST_COMPUTING_WINDOW:

            break;
        case ST_DATABASE_WINDOW:

            break;
        }

        /*
         * /onExit:
         */
        switch (oldStateISM)
        {
        case ST_MENU_WINDOW:

            break;
        case ST_DRAWING_WINDOW:

            break;
        case ST_COMPUTING_WINDOW:

            break;
        case ST_DATABASE_WINDOW:

            break;
        }
    }
}





























