#ifndef GUI_DATABASE_H
#define GUI_DATABASE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

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

    //style sheet for objects
    QString btnStylesheet;

    //graphical objects
    QPushButton* menuButton;
};

#endif // GUI_DATABASE_H
