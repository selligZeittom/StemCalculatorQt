#ifndef GUI_DATABASE_H
#define GUI_DATABASE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include "Controller/databasemanager.h"

#define N_BTN 4
#define N_LABEL 6

class ScreenManager;

class GUI_Database : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Database();
    virtual ~GUI_Database();
    void initRelations(ScreenManager* screenManager);

public slots:
    void menuButtonClicked();
    void refreshBtnClicked();
    void addBtnClicked();
    void removeBtnClicked();

private:
    //update the list on the screen
    void listUpdate();

    //the screen manager
    ScreenManager* theScreenManager;

    //the db manager
    DatabaseManager* theDBmanager;

    //vector of bikes stored inside the DB
    QVector<Bike> bikesFromDB;

    //style sheet for objects
    QString btnStylesheet;
    QString labelStylesheet;
    QString lineEditStylesheet;

    //graphical objects
    QListWidget* listWidget;

    QVector<QPushButton*> btnVector;
    QVector<QLabel*> labelVector;
    QVector<QLineEdit*> lineEditVector;

    enum btnId
    {
        ID_returnBtn = 0,
        ID_addBtn = 1,
        ID_removeBtn = 2,
        ID_refreshBtn = 3
    };

    enum labelId
    {
        ID_IdLabel,
        ID_reachLabel,
        ID_stackLabel,
        ID_headAngleLabel,
        ID_spacerLabel,
        ID_headsetHeightLabel
    };

    enum lineEditId
    {
        ID_IdLineEdit,
        ID_reachLineEdit,
        ID_stackLineEdit,
        ID_headAngleLineEdit,
        ID_spacerLineEdit,
        ID_headsetHeightLineEdit
    };
};

#endif // GUI_DATABASE_H
