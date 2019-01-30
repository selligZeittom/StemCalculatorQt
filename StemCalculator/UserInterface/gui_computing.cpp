#include "gui_computing.h"
#include "screenmanager.h"

GUI_Computing::GUI_Computing(QWidget* parent)
{
    this->theScreenManager = NULL;

    btnStylesheet = "QPushButton { background-color : white; border: 1px solid gray; border-radius: 10px; color : black;  font: bold 14px; }";
    labelStylesheet = "QLabel { background-color: white; border: 1px solid gray; border-radius: 5px; color : black; font: 12px; }";
    lineEditStylesheet = "QLineEdit { color: blue; background-color: white; selection-color: yellow; selection-background-color: blue;border: 1px solid gray; border-radius: 5px; font: 12px}";}

GUI_Computing::~GUI_Computing()
{

}

void GUI_Computing::initRelations(ScreenManager *screenManager)
{
    this->theDBmanager = &(DatabaseManager::getInstance());

    //set the screenManager
    this->theScreenManager = screenManager;

    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(theScreenManager->xOffset, theScreenManager->yOffset, theScreenManager->APP_WIDTH, theScreenManager->APP_HEIGHT);
    this->setVisible(true);
    this->hide();

    //create 4 new buttons
    QPushButton* tempBtn;
    for(int i = 0; i < N_BTN; i++)
    {
        tempBtn = new QPushButton(this);
        //tempBtn->setStyleSheet(btnStylesheet);
        tempBtn->show();
        tempBtn->setGeometry(theScreenManager->APP_WIDTH-250, theScreenManager->APP_HEIGHT-75*(i+1), 200, 50);
        btnVector.push_back(tempBtn);
    }
    tempBtn = NULL;

    //text of the buttons
    btnVector.at(ID_returnBtn)->setText("Return to menu");
    connect(btnVector.at(ID_returnBtn), SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
    btnVector.at(ID_computeBtn)->setText("Compute Results");
    connect(btnVector.at(ID_computeBtn), SIGNAL(clicked(bool)), this, SLOT(computeBtnClicked()));
    btnVector.at(ID_loadBtn)->setText("Load from DB");
    connect(btnVector.at(ID_loadBtn), SIGNAL(clicked(bool)), this, SLOT(loadBtnClicked()));
    btnVector.at(ID_storeBtn)->setText("Store to DB");
    connect(btnVector.at(ID_storeBtn), SIGNAL(clicked(bool)), this, SLOT(loadBtnClicked()));

    //create all the label and lineedit
    QLabel* tempLabel;
    QLineEdit* tempLE;
    for(int i = 0; i < N_LABEL; i++)
    {
        tempLabel = new QLabel(this);
        tempLE = new QLineEdit(this);
        tempLabel->setStyleSheet(labelStylesheet);
        tempLE->setStyleSheet(lineEditStylesheet);
        tempLabel->show();
        tempLE->show();
        tempLabel->setAlignment(Qt::AlignCenter);
        tempLE->setAlignment(Qt::AlignCenter);
        labelVector.push_back(tempLabel);
        lineEditVector.push_back(tempLE);
    }
    tempLabel = NULL;
    tempLE = NULL;

    //initialize the 4 label on the right side of the screen
    int l = 0;
    for(; l < 4; l++)
    {
        labelVector.at(l)->setGeometry(25, theScreenManager->APP_HEIGHT-75*(4-l), 150, 50);
        lineEditVector.at(l)->setGeometry(200, theScreenManager->APP_HEIGHT-75*(4-l), 200, 50);

    }

    for(; l < 8; l++)
    {
        labelVector.at(l)->setGeometry(450, theScreenManager->APP_HEIGHT-75*(8-l), 200, 50);
        lineEditVector.at(l)->setGeometry(675, theScreenManager->APP_HEIGHT-75*(8-l), 200, 50);
    }

    for(; l < N_LABEL; l++)
    {
        labelVector.at(l)->setGeometry(925, theScreenManager->APP_HEIGHT-75*(12-l), 150, 50);
        lineEditVector.at(l)->setGeometry(1100, theScreenManager->APP_HEIGHT-75*(12-l), 200, 50);
    }

    //set the text of all the label
    labelVector.at(ID_spacerLabel)->setText("Spacer [mm]");
    labelVector.at(ID_IdLabel)->setText("Name");
    labelVector.at(ID_headsetHeightLabel)->setText("Headset height [mm]");
    labelVector.at(ID_headAngleLabel)->setText("Head angle [deg]");
    labelVector.at(ID_stackLabel)->setText("Stack [mm]");
    labelVector.at(ID_reachLabel)->setText("Reach [mm]");
    labelVector.at(ID_hxLabel)->setText("Handlebar X coordinate[mm]");
    labelVector.at(ID_hyLabel)->setText("Handlebar Y coordinate[mm]");
    labelVector.at(ID_stemHeightLabel)->setText("Stem height [mm]");

}

void GUI_Computing::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}

void GUI_Computing::computeBtnClicked()
{
    qDebug() << "[guicomputing] : compute clicked";
}

void GUI_Computing::loadBtnClicked()
{
    qDebug() << "[guicomputing] : load clicked";
}

void GUI_Computing::storeBtnClicked()
{
    qDebug() << "[guicomputing] : store clicked";
}
