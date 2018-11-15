#include "gui_computing.h"
#include "screenmanager.h"

GUI_Computing::GUI_Computing(QWidget* parent)
{
    this->theScreenManager = NULL;
}

GUI_Computing::~GUI_Computing()
{

}

void GUI_Computing::initRelations(ScreenManager *screenManager)
{

    //set the screenManager
    this->theScreenManager = screenManager;
}
