#include "guiMenu.h"

GUI::GUI(QWidget *parent)
{
    //get the dimension of the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    this->height = screenGeometry.height()-35;
    this->width = screenGeometry.width();

    this->setWindowTitle("Stem Calculator V1.0");
    this->setVisible(true);
    this->showMaximized(); //full screen

    //to delete later...
    initRelations();
}

GUI::~GUI()
{

}

void GUI::initRelations()
{

    //init the buttons
    this->dbManagementButton = new QPushButton(this);
    dbManagementButton->setGeometry(BTN_OFFSET_X, height-BTN_OFFSET_y, BTN_WIDTH, BTN_HEIGHT);
    dbManagementButton->setStyleSheet("QPushButton { background-color : grey; border: 1px solid gray; border-radius: 10px; color : black; }");
    dbManagementButton->setText("Database");
    dbManagementButton->show();

    this->drawingScreenButton = new QPushButton(this);
    drawingScreenButton->setGeometry((width/2 - BTN_WIDTH/2), height-BTN_OFFSET_y, BTN_WIDTH, BTN_HEIGHT);
    drawingScreenButton->setStyleSheet("QPushButton { background-color : grey; border: 1px solid gray; border-radius: 10px; color : black; }");
    drawingScreenButton->setText("Drawing");
    drawingScreenButton->show();

    this->computingScreenButton = new QPushButton(this);
    computingScreenButton->setGeometry(width-BTN_OFFSET_X-BTN_WIDTH, height-BTN_OFFSET_y, BTN_WIDTH, BTN_HEIGHT);
    computingScreenButton->setStyleSheet("QPushButton { background-color : grey; border: 1px solid gray; border-radius: 10px; color : black; }");
    computingScreenButton->setText("Database");
    computingScreenButton->show();

    //connect the signals and slots
    connect(this->dbManagementButton, SIGNAL(clicked(bool)), this, SLOT(dbManagementButtonClicked()));
    connect(this->drawingScreenButton, SIGNAL(clicked(bool)), this, SLOT(drawingScreenButtonClicked()));
    connect(this->computingScreenButton, SIGNAL(clicked(bool)), this, SLOT(computingScreenButtonClicked()));
}

void GUI::dbManagementButtonClicked()
{
    std::cout<<"[GUI] : database management button clicked" << std::endl;
}

void GUI::drawingScreenButtonClicked()
{
    std::cout<<"[GUI] : drawing screen button clicked" << std::endl;
}

void GUI::computingScreenButtonClicked()
{
    std::cout<<"[GUI] : computing screen button clicked" << std::endl;
}
