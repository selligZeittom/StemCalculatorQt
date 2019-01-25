#include "gui_database.h"
#include "screenmanager.h"

GUI_Database::GUI_Database()
{
    this->theScreenManager = NULL;
    this->listWidget = NULL;
    this->theDBmanager = &(DatabaseManager::getInstance());

    btnStylesheet = "QPushButton { background-color : white; border: 1px solid gray; border-radius: 10px; color : black;  font: bold 14px; }";
    labelStylesheet = "QLabel { background-color: white; border: 1px solid gray; border-radius: 5px; color : black; font: 12px; }";
    lineEditStylesheet = "QLineEdit { color: blue; background-color: white; selection-color: yellow; selection-background-color: blue;border: 1px solid gray; border-radius: 5px; font: 12px}";

}

GUI_Database::~GUI_Database()
{

}

void GUI_Database::initRelations(ScreenManager *screenManager)
{
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
    btnVector.at(ID_addBtn)->setText("add bike to database");
    connect(btnVector.at(ID_addBtn), SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    btnVector.at(ID_removeBtn)->setText("Remove bike from database");
    connect(btnVector.at(ID_removeBtn), SIGNAL(clicked(bool)), this, SLOT(removeBtnClicked()));
    btnVector.at(ID_refreshBtn)->setText("Refresh database");
    connect(btnVector.at(ID_refreshBtn), SIGNAL(clicked(bool)), this, SLOT(refreshBtnClicked()));

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
        labelVector.at(l)->setGeometry(50, theScreenManager->APP_HEIGHT-75*(4-l), 200, 50);
        lineEditVector.at(l)->setGeometry(300, theScreenManager->APP_HEIGHT-75*(4-l), 200, 50);

    }

    for(; l < N_LABEL; l++)
    {
        labelVector.at(l)->setGeometry(650, theScreenManager->APP_HEIGHT-75*(8-l), 200, 50);
        lineEditVector.at(l)->setGeometry(900, theScreenManager->APP_HEIGHT-75*(8-l), 200, 50);
    }

    //set the text of all the label
    labelVector.at(ID_spacerLabel)->setText("Spacer [mm]");
    labelVector.at(ID_IdLabel)->setText("Name");
    labelVector.at(ID_headsetHeightLabel)->setText("Headset height [mm]");
    labelVector.at(ID_headAngleLabel)->setText("Head angle [deg]");
    labelVector.at(ID_stackLabel)->setText("Stack [mm]");
    labelVector.at(ID_reachLabel)->setText("Reach [mm]");


    this->listWidget = new QListWidget(this);
    listWidget->setGeometry(50, 50, theScreenManager->APP_WIDTH -100, theScreenManager->APP_HEIGHT-400);
    listWidget->show();
}

void GUI_Database::menuButtonClicked()
{
    theScreenManager->btnPressed(BTN_ID_MENU);
}

void GUI_Database::refreshBtnClicked()
{
    qDebug() << "[DBgui] : refresh btn clicked";
    bikesFromDB = theDBmanager->getBikesFromDB();
    listUpdate();
}

void GUI_Database::addBtnClicked()
{
    qDebug() << "[DBgui] : add btn clicked";
    QString n = lineEditVector.at(ID_IdLineEdit)->text();
    int s = lineEditVector.at(ID_stackLineEdit)->text().toInt();
    int r = lineEditVector.at(ID_reachLineEdit)->text().toInt();
    int sh = lineEditVector.at(ID_spacerLineEdit)->text().toInt();
    int hh = lineEditVector.at(ID_headsetHeightLineEdit)->text().toInt();
    double sa = lineEditVector.at(ID_headAngleLineEdit)->text().toDouble();
    Bike b2add(n, s, r, sh, hh, sa);
    bikesFromDB.append(b2add);
    theDBmanager->addBikeToDB(b2add.getJsonFromBike());
    listUpdate();
}

void GUI_Database::removeBtnClicked()
{
    qDebug() << "[DBgui] : remove btn clicked";
}

void GUI_Database::listUpdate()
{
    listWidget->clear();
    for(int i = 0; i < bikesFromDB.count(); i++)
    {
        QString bikeConfig = bikesFromDB.at(i).getString();
        listWidget->addItem(bikeConfig);
    }
}
