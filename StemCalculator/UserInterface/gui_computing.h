#ifndef GUI_COMPUTING_H
#define GUI_COMPUTING_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include "Controller/databasemanager.h"

#define N_BTN 4
#define N_LABEL 11

class ScreenManager;

class GUI_Computing : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Computing(QWidget* parent = 0);
    virtual ~GUI_Computing();
    void initRelations(ScreenManager* screenManager);

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
    QVector<QPushButton*> btnVector;
    QVector<QLabel*> labelVector;
    QVector<QLineEdit*> lineEditVector;

    enum btnId
    {
        ID_returnBtn,
        ID_computeBtn,
        ID_loadBtn,
        ID_storeBtn
    };

    enum labelId
    {
        ID_IdLabel,
        ID_reachLabel,
        ID_stackLabel,
        ID_headAngleLabel,
        ID_spacerLabel,
        ID_headsetHeightLabel,
        ID_hxLabel,
        ID_hyLabel,
        ID_stemHeightLabel,
        ID_stemLengthLabel,
        ID_stemAngleLabel
    };

    enum lineEditId
    {
        ID_IdLineEdit,
        ID_reachLineEdit,
        ID_stackLineEdit,
        ID_headAngleLineEdit,
        ID_spacerLineEdit,
        ID_headsetHeightLineEdit,
        ID_hxLineEdit,
        ID_hyLineEdit,
        ID_stemHeightLineEdit,
        ID_stemLengthLineEdit,
        ID_stemAngleLineEdit
    };

public slots:
    void menuButtonClicked();
    void computeBtnClicked();
    void loadBtnClicked();
    void storeBtnClicked();
};

#endif // GUI_COMPUTING_H
