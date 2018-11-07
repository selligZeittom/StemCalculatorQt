#include "gui_menu.h"

GUI_Menu::GUI_Menu(QWidget *parent)
{
    //get the dimension of the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->screenHeight = screenGeometry.height()-30;
    this->screenWidth = screenGeometry.width();

    this->btnWidth = screenWidth/BTN_NUMBER;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setVisible(true);
    this->showMaximized(); //full screen

    //to delete later...
    initRelations();
}

GUI_Menu::~GUI_Menu()
{

}

void GUI_Menu::initRelations()
{

    //init the buttons
    this->dbManagementButton = new QPushButton(this);
    dbManagementButton->setGeometry(0, screenHeight-BTN_HEIGHT, btnWidth, BTN_HEIGHT);
    dbManagementButton->setStyleSheet("QPushButton { font: bold 14px; background-color : gray; border: 2px solid black; }");
    dbManagementButton->setText("Database");
    dbManagementButton->show();

    this->drawingScreenButton = new QPushButton(this);
    drawingScreenButton->setGeometry(btnWidth, screenHeight-BTN_HEIGHT, btnWidth, BTN_HEIGHT);
    drawingScreenButton->setStyleSheet("QPushButton {font: bold 14px; background-color : gray; border: 2px solid black; color : black; }");
    drawingScreenButton->setText("Drawing");
    drawingScreenButton->show();

    this->computingScreenButton = new QPushButton(this);
    computingScreenButton->setGeometry(btnWidth*2, screenHeight-BTN_HEIGHT, btnWidth, BTN_HEIGHT);
    computingScreenButton->setStyleSheet("QPushButton { font: bold 14px; background-color : gray; border: 2px solid black; color : black; }");
    computingScreenButton->setText("Computing");
    computingScreenButton->show();

    //connect the signals and slots
    connect(this->dbManagementButton, SIGNAL(clicked(bool)), this, SLOT(dbManagementButtonClicked()));
    connect(this->drawingScreenButton, SIGNAL(clicked(bool)), this, SLOT(drawingScreenButtonClicked()));
    connect(this->computingScreenButton, SIGNAL(clicked(bool)), this, SLOT(computingScreenButtonClicked()));
}



int GUI_Menu::getScreenHeight() const
{
    return this->screenHeight;
}

int GUI_Menu::getScreenWidth() const
{
    return this->screenWidth;
}

/*********************************************************************************************************************
 * slots
 ********************************************************************************************************************/


void GUI_Menu::dbManagementButtonClicked()
{
    std::cout<<"[GUI] : database management button clicked" << std::endl;
}

void GUI_Menu::drawingScreenButtonClicked()
{
    std::cout<<"[GUI] : drawing screen button clicked" << std::endl;
}

void GUI_Menu::computingScreenButtonClicked()
{
    std::cout<<"[GUI] : computing screen button clicked" << std::endl;
}
