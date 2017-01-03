#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QSize>
#include <QImage>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "ToolBt.h"

class MainInterface : public QWidget
{
    Q_OBJECT

public:
    MainInterface(QWidget *parent = 0);
    ~MainInterface();

private:
    ToolBt *MainToolBt;
    QVBoxLayout *MainLt;

};

#endif // MAININTERFACE_H
