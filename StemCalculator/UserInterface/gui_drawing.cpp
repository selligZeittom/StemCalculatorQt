#include "gui_drawing.h"
#include "screenmanager.h"

GUI_Drawing::GUI_Drawing(QWidget *parent)
{
    this->theScreenManager = NULL;

    //btnStylesheet = "QPushButton{ background-color :  #F9C67E; border: 1px solid gray; border-radius: 5px; color : black; font: 12px; }";
    labelStylesheet = "QLabel { background-color: white; border: 1px solid gray; border-radius: 5px; color : black; font: 12px; }";
    lineEditStylesheet = "QLineEdit { color: blue; background-color: white; selection-color: yellow; selection-background-color: blue;border: 1px solid gray; border-radius: 5px; font: 12px}";
    sliderStylesheet = "QSlider {}";
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
        btnVector.at(i)->setGeometry(theScreenManager->APP_WIDTH-(BTN1_WIDTH+BTN1_OFFSET_X_RIGHT), theScreenManager->APP_HEIGHT-yOffset*(i+1), BTN1_WIDTH, COMPONENT_HEIGHT);
    }
    tempBtn = NULL;

    //correct the last button + the text
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
    int l = 0;
    for(; l < 4; l++)
    {
        labelVector.at(l)->setGeometry((theScreenManager->APP_WIDTH/2 - LABEL_WIDTH/2), theScreenManager->APP_HEIGHT-yOffset*(l+4), LABEL_WIDTH, COMPONENT_HEIGHT);
    }

    //initialize the 7 label on the left side of the screen
    for(; l < 11; l++)
    {
        labelVector.at(l)->setGeometry(LABEL_X_OFFSET, theScreenManager->APP_HEIGHT-yOffset*(l-3), LABEL_WIDTH, COMPONENT_HEIGHT);
    }

    //set the text of all the label
    labelVector.at(ID_spacerLabel)->setText("Spacer [mm]");
    labelVector.at(ID_lengthLabel)->setText("Length[mm]");
    labelVector.at(ID_angleLabel)->setText("Angle [deg]");
    labelVector.at(ID_IdLabel)->setText("Name");
    labelVector.at(ID_stemHeightLabel)->setText("Stem height [mm]");
    labelVector.at(ID_hyLabel)->setText("Handlebar Y [mm]");
    labelVector.at(ID_hxLabel)->setText("Handlebar X [mm]");
    labelVector.at(ID_headsetHeightLabel)->setText("Headset height [mm]");
    labelVector.at(ID_headAngleLabel)->setText("Head angle [deg]");
    labelVector.at(ID_stackLabel)->setText("Stack [mm]");
    labelVector.at(ID_reachLabel)->setText("Reach [mm]");

    //create 8 new edit line
    QLineEdit* tempLineEdit;
    for(int j = 0; j < N_LINEDIT; j++)
    {
        tempLineEdit = new QLineEdit(this);
        tempLineEdit->setStyleSheet(lineEditStylesheet);
        tempLineEdit->setAlignment(Qt::AlignCenter);
        tempLineEdit->show();
        tempLineEdit->setGeometry(LINE_EDIT_X_OFFSET_LEFT, theScreenManager->APP_HEIGHT-yOffset*(j+1), LINE_EDIT_WIDTH_LEFT, COMPONENT_HEIGHT);
        lineEditVector.push_back(tempLineEdit);
    }
    tempLineEdit = NULL;
    //then set the last one
    lineEditVector.at(ID_IdLineEdit)->setGeometry((theScreenManager->APP_WIDTH/2 + BTN1_WIDTH/2 + X_OFFSET_RIGHT) , theScreenManager->APP_HEIGHT-yOffset*(7), LINE_EDIT_WIDTH_RIGHT, COMPONENT_HEIGHT);

    //create 4 slider
    QSlider* tempSlider;
    for(int k = 0; k < N_SLIDER; k++)
    {
        tempSlider = new QSlider(Qt::Horizontal, this);
        tempSlider->setStyleSheet(sliderStylesheet);
        tempSlider->show();
        tempSlider->setGeometry((theScreenManager->APP_WIDTH/2 + BTN1_WIDTH/2 + X_OFFSET_RIGHT) , theScreenManager->APP_HEIGHT-(yOffset*(k+4)-5), SLIDER_WIDTH, SLIDER_HEIGHT);
        sliderVector.push_back(tempSlider);
    }
    tempSlider = NULL;
    sliderVector.at(ID_zoomSlider)->setGeometry(20, 20, SLIDER_ZOOM_WIDTH, SLIDER_HEIGHT);


    //connect the buttons
    connect(this->btnVector.at(ID_returnBtn), SIGNAL(clicked(bool)), this, SLOT(menuButtonClicked()));
    connect(this->btnVector.at(ID_loadBtn), SIGNAL(clicked(bool)), this, SLOT(loadBtnClicked()));
    connect(this->btnVector.at(ID_saveBtn), SIGNAL(clicked(bool)), this, SLOT(saveBtnClicked()));

    //connect sliders
    for(int i = 0;i<N_SLIDER; i++)
    {
        connect(this->sliderVector.at(i), SIGNAL(sliderReleased()), this, SLOT(oneSliderMoved()));
    }

    //connect line edit
    for (int i = 0; i < N_LINEDIT;i++)
    {
        connect(this->lineEditVector.at(i), SIGNAL(editingFinished()), this, SLOT(oneLineEditUpdated()));
    }
}

void GUI_Drawing::menuButtonClicked()
{
    std::cout<<"[GUI_Drawing] : menu button clicked" << std::endl;
    theScreenManager->btnPressed(BTN_ID_MENU);
}

void GUI_Drawing::loadBtnClicked()
{
    std::cout<<"[GUI_Drawing] : load button clicked" << std::endl;

}

void GUI_Drawing::saveBtnClicked()
{
    std::cout<<"[GUI_Drawing] : save button clicked" << std::endl;

}

void GUI_Drawing::oneSliderMoved()
{
    std::cout<<"[GUI_Drawing] : one slider has been released" << std::endl;

}

void GUI_Drawing::oneLineEditUpdated()
{
    std::cout<<"[GUI_Drawing] : one edit line has been updated" << std::endl;

}

