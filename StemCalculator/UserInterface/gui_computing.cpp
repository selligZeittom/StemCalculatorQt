#include "gui_computing.h"
#include "screenmanager.h"

GUI_Computing::GUI_Computing(QWidget* parent)
{
    this->theScreenManager = NULL;
    this->menuButton = NULL;

    btnStylesheet = "QPushButton { background-color : white; border: 1px solid gray; border-radius: 10px; color : black;  font: bold 14px; }";
}

GUI_Computing::~GUI_Computing()
{

}

void GUI_Computing::initRelations(ScreenManager *screenManager)
{

    //set the screenManager
    this->theScreenManager = screenManager;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(theScreenManager->xOffset, theScreenManager->yOffset, theScreenManager->APP_WIDTH, theScreenManager->APP_HEIGHT);
    this->setVisible(true);
    this->hide();

    this->menuButton = new QPushButton(this);
    menuButton->setGeometry(50, 50, 100, 40);
    menuButton->setText("back to menu");
    menuButton->show();

    connect(this->menuButton, SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
}

void GUI_Computing::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}
