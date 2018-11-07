#include "gui_drawing.h"

GUI_Drawing::GUI_Drawing(GUI_Menu *parent)
{
    this->screenHeight= parent->getScreenHeight();
    this->screenWidth = parent->getScreenWidth();

    btnStylesheet = "QPushButton { background-color : grey; border: 1px solid gray; border-radius: 10px; color : black; }";

    this->setVisible(true);
    this->setGeometry(0,35, screenWidth, screenHeight-y_OFFSET); //full screen

    //to delete later
    initRelations();
}

GUI_Drawing::~GUI_Drawing()
{

}

void GUI_Drawing::initRelations()
{
    this->updateResultButton = new QPushButton(this);
    updateResultButton->setGeometry(BTN1_OFFSET_X, screenHeight-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    updateResultButton->setStyleSheet(btnStylesheet);
    updateResultButton->setText("update results");
    updateResultButton->show();

    this->saveGeometryButton = new QPushButton(this);
    saveGeometryButton->setGeometry((screenWidth/2 - BTN1_WIDTH/2), screenHeight-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    saveGeometryButton->setStyleSheet(btnStylesheet);
    saveGeometryButton->setText("save geometry");
    saveGeometryButton->show();

    this->loadGeometryButton = new QPushButton(this);
    loadGeometryButton->setGeometry(screenWidth-BTN1_OFFSET_X-BTN1_WIDTH, screenHeight-BTN1_OFFSET_Y, BTN1_WIDTH, BTN1_HEIGHT);
    loadGeometryButton->setStyleSheet(btnStylesheet);
    loadGeometryButton->setText("load geometry");
    loadGeometryButton->show();
}

