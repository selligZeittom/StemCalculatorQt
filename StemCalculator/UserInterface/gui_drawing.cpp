#include "gui_drawing.h"
#include "screenmanager.h"

GUI_Drawing::GUI_Drawing(QWidget *parent)
{
    this->theScreenManager = NULL;
    this->menuButton = NULL;

    btnStylesheet = "QPushButton { background-color : grey; border: 1px solid gray; border-radius: 10px; color : black; font: bold 14px; }";
}

GUI_Drawing::~GUI_Drawing()
{

}

void GUI_Drawing::initRelations(ScreenManager* screenManager)
{
    //set the screen manager
    this->theScreenManager = screenManager;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(screenManager->xOffset,screenManager->yOffset, screenManager->APP_WIDTH, screenManager->APP_HEIGHT);
    this->setVisible(true);
    this->hide();

    this->updateResultButton = new QPushButton(this);
    updateResultButton->setGeometry(BTN1_OFFSET_X, theScreenManager->APP_HEIGHT-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    updateResultButton->setStyleSheet(btnStylesheet);
    updateResultButton->setText("update results");
    updateResultButton->show();

    this->saveGeometryButton = new QPushButton(this);
    saveGeometryButton->setGeometry((theScreenManager->APP_WIDTH/2 - BTN1_WIDTH/2), theScreenManager->APP_HEIGHT-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    saveGeometryButton->setStyleSheet(btnStylesheet);
    saveGeometryButton->setText("save geometry");
    saveGeometryButton->show();

    this->loadGeometryButton = new QPushButton(this);
    loadGeometryButton->setGeometry(theScreenManager->APP_WIDTH-BTN1_OFFSET_X-BTN1_WIDTH, theScreenManager->APP_HEIGHT-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    loadGeometryButton->setStyleSheet(btnStylesheet);
    loadGeometryButton->setText("load geometry");
    loadGeometryButton->show();

    this->menuButton = new QPushButton(this);
    menuButton->setGeometry(50, 50, 100, 40);
    menuButton->setText("back to menu");
    menuButton->show();

    connect(this->menuButton, SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
}

void GUI_Drawing::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}

