#include "gui_drawing.h"
#include "screenmanager.h"

GUI_Drawing::GUI_Drawing(QWidget *parent)
{
    this->theScreenManager = NULL;

    btnStylesheet = "QPushButton { background-color : orange; border: 1px solid gray; border-radius: 5px; color : black; font: bold 12px; }";
    labelStylesheet = "QLabel { background-color: white; border: 1px solid gray; border-radius: 5px; color : black; font: bold 12px; }";
    lineEditStylesheet = "QLineEdit { background-color: blue; border: 1px solid gray; border-radius: 5px; color : black; font: bold 12px; }";
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

    //set the appearance of the main window
    this->setWindowTitle("Stem Calculator V1.0");
    this->setGeometry(screenManager->xOffset,screenManager->yOffset, screenManager->APP_WIDTH, screenManager->APP_HEIGHT);
    this->setVisible(true);
    this->hide();

    //set the drawing view
    this->drawingView = new QGraphicsView(this);
    drawingView->setGeometry(OFFSET_VIEW, OFFSET_VIEW, theScreenManager->APP_WIDTH-2*OFFSET_VIEW, theScreenManager->APP_HEIGHT/2);
    this->scnView = new QGraphicsScene(drawingView);
    drawingView->setScene(scnView);
    drawingView->show();


    //create 4 new buttons
    QPushButton* tempBtn;
    for(int i = 0; i < N_BTN; i++)
    {
        tempBtn = new QPushButton(this);
        tempBtn->setStyleSheet(btnStylesheet);
        tempBtn->show();
        btnVector.push_back(tempBtn);
    }

    tempBtn = NULL;

    //initialize the positions of 3 buttons in a row
    for(int i = 0; i < 3; i++)
    {
        btnVector.at(i)->setGeometry((theScreenManager->APP_WIDTH/2 - BTN1_WIDTH/2), theScreenManager->APP_HEIGHT-yOffset*(i+1), BTN1_WIDTH, BTN1_HEIGHT);
    }

    //and initialize the last button + the text
    btnVector.at(ID_returnBtn)->setGeometry(theScreenManager->APP_WIDTH-(BTN1_WIDTH+BTN1_OFFSET_X_RIGHT), theScreenManager->APP_HEIGHT-(yOffset*1), BTN1_WIDTH, BTN1_HEIGHT);
    btnVector.at(ID_updateBtn)->setText("Update results");
    btnVector.at(ID_loadBtn)->setText("Load bike geometry");
    btnVector.at(ID_saveBtn)->setText("Save bike geometry");
    btnVector.at(ID_returnBtn)->setText("Return to menu");

    //create all the label
    QLabel* tempLabel;
    for(int i = 0; i < N_LABEL; i++)
    {
        tempLabel = new QLabel(this);
        tempLabel->setStyleSheet(labelStylesheet);
        tempLabel->show();
        tempLabel->setAlignment(Qt::AlignCenter);
        labelVector.push_back(tempLabel);
    }

    tempLabel = NULL;

    //initialize the 4 label on the right side of the screen
    int i = 0;
    for(; i < 4; i++)
    {
        labelVector.at(i)->setGeometry((theScreenManager->APP_WIDTH/2 - LABEL_WIDTH/2), theScreenManager->APP_HEIGHT-yOffset*(i+4), LABEL_WIDTH, LABEL_HEIGHT);
    }

    //initialize the 7 label on the left side of the screen
    for(; i < 11; i++)
    {
        labelVector.at(i)->setGeometry(LABEL_X_OFFSET, theScreenManager->APP_HEIGHT-yOffset*(i-3), LABEL_WIDTH, LABEL_HEIGHT);
    }

    //set the text of all the label
    labelVector.at(ID_spacerLabel)->setText("Spacer [mm]");
    labelVector.at(ID_lengthLabel)->setText("Length[mm]");
    labelVector.at(ID_angleLabel)->setText("Angle [deg]");
    labelVector.at(ID_IdLabel)->setText("ID");
    labelVector.at(ID_stemHeightLabel)->setText("Stem height [mm]");
    labelVector.at(ID_hyLabel)->setText("Handlebar Y [mm]");
    labelVector.at(ID_hxLabel)->setText("Handlebar X [mm]");
    labelVector.at(ID_headsetHeightLabel)->setText("Headset height [mm]");
    labelVector.at(ID_headAngleLabel)->setText("Head angle [deg]");
    labelVector.at(ID_stackLabel)->setText("Stack [mm]");
    labelVector.at(ID_reachLabel)->setText("Reach [mm]");

    //create 4 new edit line
    QLineEdit* tempLineEdit;
    for(int i = 0; i < N_LINEDIT; i++)
    {
        tempLineEdit = new QLineEdit(this);
        tempLineEdit->setStyleSheet(btnStylesheet);
        tempLineEdit->show();
        tempLineEdit->setGeometry(LINEEDIT_X_OFFSET, theScreenManager->APP_HEIGHT-yOffset*(i+1), LINEEDIT_WIDTH, LINEEDIT_HEIGHT);
        lineEditVector.push_back(tempLineEdit);
    }



    //connect the buttons
    connect(this->btnVector.at(ID_returnBtn), SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
}

void GUI_Drawing::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}

