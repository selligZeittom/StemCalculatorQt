#include "gui_database.h"
#include "screenmanager.h"

GUI_Database::GUI_Database()
{
    this->theScreenManager = NULL;
}

GUI_Database::~GUI_Database()
{

}

void GUI_Database::initRelations(ScreenManager *screenManager)
{
    //set the screenManager
    this->theScreenManager = screenManager;
}
