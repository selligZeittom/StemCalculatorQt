#include <QApplication>
#include <XF/xf.h>
#include <iostream>

#include "factory.h"


int main(int argc, char *argv[])
{
    std::cout << "start of the stem calculator app" << std::endl;
    Factory f;
    f.create();
    f.build();
    return XF::getInstance().exec();
    f.destroy();
}
