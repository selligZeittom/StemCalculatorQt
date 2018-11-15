#ifndef GUI_DATABASE_H
#define GUI_DATABASE_H

#include <QObject>
#include <QWidget>

class ScreenManager;

class GUI_Database : public QWidget
{
    Q_OBJECT

public:
    explicit GUI_Database();
    virtual ~GUI_Database();
    void initRelations(ScreenManager* screenManager);

private:
    //the screen manager
    ScreenManager* theScreenManager;
};

#endif // GUI_DATABASE_H
