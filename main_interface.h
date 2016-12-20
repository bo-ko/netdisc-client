#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QWidget>

class MainInterface : public QWidget
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = 0);
    ~MainInterface();
};

#endif // MAININTERFACE_H
