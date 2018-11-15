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

void ScreenManager::btnPressed(int btnID)
{
    //create a new event
    XFEvent* ev = new XFEvent();

    switch (btnID) {
    case BTN_ID_MENU:
        ev->setID((int) EV_GOTO_MENU);
        ev->setTarget(this);
        break;
    case BTN_ID_DRAWING:
        ev->setID((int) EV_GOTO_DRAWING);
        ev->setTarget(this);
        break;
    case BTN_ID_COMPUTING:
        ev->setID((int) EV_GOTO_COMPUTING);
        ev->setTarget(this);
        break;
    case BTN_ID_DATABASE:
        ev->setID((int) EV_GOTO_DATABASE);
        ev->setTarget(this);
        break;
    }

    //push the event into the ism
    XF::getInstance().pushEvent(ev);
}

bool ScreenManager::processEvent(XFEvent *event)
{
    //used to say if the event is used or not
    bool processed = false;

    //store the current state
    STATE_SCREEN_MANAGER oldStateISM = currentStateISM;

    /*
     * /onTransition:
     *
     */
    switch (currentStateISM)
    {
    case ST_MENU_WINDOW:
        //if the computing button is pressed
        if(event->getID() == EV_GOTO_COMPUTING)
        {
            currentStateISM = ST_COMPUTING_WINDOW;
        }
        //if the drawing button is pressed
        else if(event->getID() == EV_GOTO_DRAWING)
        {
            currentStateISM = ST_DRAWING_WINDOW;
        }
        //if the database button is pressed
        else if (event->getID() == EV_GOTO_DATABASE)
        {
            currentStateISM = ST_DATABASE_WINDOW;
        }

        break;
    case ST_DRAWING_WINDOW:
        //if the return to menu button is pressed
        if(event->getID() == EV_GOTO_MENU)
        {
            currentStateISM = ST_MENU_WINDOW;
        }
        break;
    case ST_COMPUTING_WINDOW:
        //if the return to menu button is pressed
        if(event->getID() == EV_GOTO_MENU)
        {
            currentStateISM = ST_MENU_WINDOW;
        }
        break;
    case ST_DATABASE_WINDOW:
        //if the return to menu button is pressed
        if(event->getID() == EV_GOTO_MENU)
        {
            currentStateISM = ST_MENU_WINDOW;
        }
        break;
    }

    if(oldStateISM != currentStateISM)
    {
        processed = true;

        /*
         * /onEntry:
         *
         */
        switch (currentStateISM)
        {
        case ST_MENU_WINDOW:
            theMenuWindow->show();
            break;
        case ST_DRAWING_WINDOW:
            theDrawingWindow->show();
            break;
        case ST_COMPUTING_WINDOW:
            theComputingWindow->show();
            break;
        case ST_DATABASE_WINDOW:
            theDatabaseWindow->show();
            break;
        }

        /*
         * /onExit:
         *
         */
        switch (oldStateISM)
        {
        case ST_MENU_WINDOW:
            theMenuWindow->hide();
            break;
        case ST_DRAWING_WINDOW:
            theDrawingWindow->hide();
            break;
        case ST_COMPUTING_WINDOW:
            theComputingWindow->hide();
            break;
        case ST_DATABASE_WINDOW:
            theDatabaseWindow->hide();
            break;
        }
    }

    return processed;
}





























