#include "screenmanager.h"
#include "gui_menu.h"
#include "gui_drawing.h"

ScreenManager::ScreenManager()
{
    //get the dimension of the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->screenHeight = screenGeometry.height();
    this->screenWidth = screenGeometry.width();
    this->xOffset = (screenWidth - APP_WIDTH) / 2;
    this->yOffset = (screenHeight - APP_HEIGHT) / 2;
}

ScreenManager::~ScreenManager()
{

}

void ScreenManager::initRelations(GUI_Drawing *drawingGui, GUI_Menu *menuGui)
{
    this->theDrawingWindow = drawingGui;
    this->theMenuWindow = menuGui;
}
