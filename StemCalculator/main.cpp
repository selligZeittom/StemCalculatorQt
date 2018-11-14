#include "UserInterface/gui_menu.h"
#include "UserInterface/gui_drawing.h"
#include "UserInterface/screenmanager.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "start of the stem calculator app" << std::endl;
    QApplication a(argc, argv);
    ScreenManager theScreenManager;
    GUI_Menu theMenuWindow;
    theMenuWindow.initRelations(&theScreenManager);
    theMenuWindow.show();
    GUI_Drawing theDrawingWindow;
    theDrawingWindow.initRelations(&theScreenManager);
    theScreenManager.initRelations(&theDrawingWindow, &theMenuWindow);


    return a.exec();
}
