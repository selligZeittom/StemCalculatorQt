#include "UserInterface/guiMenu.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "start of the stem calculator app" << std::endl;
    QApplication a(argc, argv);
    GUI menuScreen;
    menuScreen.show();

    return a.exec();
}
