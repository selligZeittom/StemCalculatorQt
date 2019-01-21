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
#define N_LABEL 7

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

private:
    //the screen manager
    ScreenManager* theScreenManager;

    //the db manager
    DatabaseManager* theDBmanager;

    //style sheet for objects
    QString btnStylesheet;
    QString labelStylesheet;
    QString lineEditStylesheet;

    //graphical objects
    QPushButton* menuBtn;
    QPushButton* addToDbBtn;
    QPushButton* removeFromDbBtn;
    QPushButton* getFromDbBtn;
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
        ID_spacerLabel = 0,
        ID_IdLabel = 1,
        ID_stemHeightLabel = 2,
        ID_headsetHeightLabel = 3,
        ID_headAngleLabel = 4,
        ID_stackLabel = 5,
        ID_reachLabel = 6
    };

    enum lineEditId
    {
        ID_stemHeightLineEdit = 0,
        ID_headsetHeightLineEdit = 1,
        ID_headAngleLineEdit = 2,
        ID_stackLineEdit = 3,
        ID_reachLineEdit = 4,
        ID_IdLineEdit = 5,
        ID_spacerLineEdit = 6
    };
};

#endif // GUI_DATABASE_H
