#include "gui_drawing.h"
#include "screenmanager.h"

GUI_Drawing::GUI_Drawing(QWidget *parent)
{
    this->theScreenManager = NULL;

    this->drawingView = NULL;
    this->scnView = NULL;
    this->updateResultButton = NULL;
    this->saveGeometryButton = NULL;
    this->loadGeometryButton = NULL;
    this->menuButton = NULL;
    this->reachLabel = NULL;
    this->stackLabel = NULL;
    this->headAngleLabel = NULL;
    this->headsetHeightLabel = NULL;
    this->stemHeightLabel = NULL;
    this->bikeNameLabel = NULL;
    this->handlebarXLabel = NULL;
    this->handlebarYLabel = NULL;
    this->angleLabel = NULL;
    this->lengthLabel = NULL;
    this->displayAngleLabel = NULL;
    this->displayLengthLabel = NULL;
    this->reachLineEdit = NULL;
    this->stackLineEdit = NULL;
    this->headAngleLineEdit = NULL;
    this->headsetHeightLineEdit = NULL;
    this->stemHeightLineEdit = NULL;
    this->bikeNameLineEdit = NULL;
    this->handlebarXLineEdit = NULL;
    this->handlebarYLineEdit = NULL;
    this->angleSlider = NULL;
    this->lengthSlider = NULL;
    this->spacerHeightSlider = NULL;
    this->zoomSlider = NULL;

    btnStylesheet = "QPushButton { background-color : white; border: 1px solid gray; border-radius: 5px; color : black; font: bold 12px; }";
    labelStylesheet = "QLabel { background-color: white; border: 1px solid gray; border-radius: 5px; color : black; font: bold 12px; }";
}

GUI_Drawing::~GUI_Drawing()
{

}

void GUI_Drawing::initRelations(ScreenManager* screenManager)
{
    //set the screen manager
    this->theScreenManager = screenManager;

    //get the space between components
    this->yOffset = (theScreenManager->APP_HEIGHT/2)/8;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(screenManager->xOffset,screenManager->yOffset, screenManager->APP_WIDTH, screenManager->APP_HEIGHT);
    this->setVisible(true);
    this->hide();

    this->drawingView = new QGraphicsView(this);
    drawingView->setGeometry(OFFSET_VIEW, OFFSET_VIEW, theScreenManager->APP_WIDTH-2*OFFSET_VIEW, theScreenManager->APP_HEIGHT/2);
    this->scnView = new QGraphicsScene(drawingView);
    drawingView->setScene(scnView);
    drawingView->show();

    this->updateResultButton = new QPushButton(this);
    updateResultButton->setGeometry((theScreenManager->APP_WIDTH/2 - BTN1_WIDTH/2), theScreenManager->APP_HEIGHT-yOffset*4, BTN1_WIDTH, BTN1_HEIGHT);
    updateResultButton->setStyleSheet(btnStylesheet);
    updateResultButton->setText("update results");
    updateResultButton->show();

    this->saveGeometryButton = new QPushButton(this);
    saveGeometryButton->setGeometry((theScreenManager->APP_WIDTH/2 - BTN1_WIDTH/2), theScreenManager->APP_HEIGHT-(yOffset*5 + BTN1_HEIGHT), BTN1_WIDTH, BTN1_HEIGHT);
    saveGeometryButton->setStyleSheet(btnStylesheet);
    saveGeometryButton->setText("save geometry");
    saveGeometryButton->show();

    this->loadGeometryButton = new QPushButton(this);
    loadGeometryButton->setGeometry((theScreenManager->APP_WIDTH/2 - BTN1_WIDTH/2), theScreenManager->APP_HEIGHT-(yOffset*6 + 2*BTN1_HEIGHT), BTN1_WIDTH, BTN1_HEIGHT);
    loadGeometryButton->setStyleSheet(btnStylesheet);
    loadGeometryButton->setText("load geometry");
    loadGeometryButton->show();

    this->menuButton = new QPushButton(this);
    menuButton->setGeometry(theScreenManager->APP_WIDTH-(BTN1_WIDTH+BTN1_OFFSET_X_RIGHT), theScreenManager->APP_HEIGHT-yOffset*4, BTN1_WIDTH, BTN1_HEIGHT);
    menuButton->setStyleSheet(btnStylesheet);
    menuButton->setText("back to menu");
    menuButton->show();

    this->bikeNameLabel = new QLabel(this);
    bikeNameLabel->setGeometry((theScreenManager->APP_WIDTH/2 - LABEL_WIDTH/2),theScreenManager->APP_HEIGHT/2+yOffset,  LABEL_WIDTH, LABEL_HEIGHT);
    bikeNameLabel->setText("Bike's name");
    bikeNameLabel->setStyleSheet(labelStylesheet);
    bikeNameLabel->show();

    //connect the buttons
    connect(this->menuButton, SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
}

void GUI_Drawing::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}

