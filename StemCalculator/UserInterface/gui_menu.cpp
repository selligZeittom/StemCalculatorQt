#include "gui_menu.h"
#include "screenmanager.h"

GUI_Menu::GUI_Menu(QWidget *parent)
{
    this->theScreenManager = NULL;

    btnStylesheet = "QPushButton { background-color : white; border: 1px solid gray; border-radius: 10px; color : black;  font: bold 14px; }";
}

GUI_Menu::~GUI_Menu()
{

}

void GUI_Menu::initRelations(ScreenManager *screenManager)
{

    //set the screenManager
    this->theScreenManager = screenManager;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(theScreenManager->xOffset, theScreenManager->yOffset, theScreenManager->APP_WIDTH, theScreenManager->APP_HEIGHT);
    this->setVisible(true);

    //init the buttons
    this->dbManagementButton = new QPushButton(this);
    dbManagementButton->setGeometry(BTN_SPACE, theScreenManager->APP_HEIGHT-BTN_Y_POS, BTN_WIDTH, BTN_HEIGHT);
    dbManagementButton->setStyleSheet(btnStylesheet);
    dbManagementButton->setText("Database");
    dbManagementButton->show();

    this->drawingScreenButton = new QPushButton(this);
    drawingScreenButton->setGeometry(theScreenManager->APP_WIDTH/2-BTN_WIDTH/2, theScreenManager->APP_HEIGHT-BTN_Y_POS, BTN_WIDTH, BTN_HEIGHT);
    drawingScreenButton->setStyleSheet(btnStylesheet);
    drawingScreenButton->setText("Drawing");
    drawingScreenButton->show();

    this->computingScreenButton = new QPushButton(this);
    computingScreenButton->setGeometry(theScreenManager->APP_WIDTH-BTN_WIDTH-BTN_SPACE, theScreenManager->APP_HEIGHT-BTN_Y_POS, BTN_WIDTH, BTN_HEIGHT);
    computingScreenButton->setStyleSheet(btnStylesheet);
    computingScreenButton->setText("Computing");
    computingScreenButton->show();

    //connect the signals and slots
    connect(this->dbManagementButton, SIGNAL(clicked(bool)), this, SLOT(dbManagementButtonClicked()));
    connect(this->drawingScreenButton, SIGNAL(clicked(bool)), this, SLOT(drawingScreenButtonClicked()));
    connect(this->computingScreenButton, SIGNAL(clicked(bool)), this, SLOT(computingScreenButtonClicked()));
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
