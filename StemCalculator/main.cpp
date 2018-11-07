#include "UserInterface/gui_menu.h"
#include "UserInterface/gui_drawing.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "start of the stem calculator app" << std::endl;
    QApplication a(argc, argv);
    GUI_Menu menuScreen;
    menuScreen.show();
    GUI_Drawing drawingMenu(&menuScreen);
    drawingMenu.show();


    return a.exec();
}
