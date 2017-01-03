#include "MainInterface.h"

MainInterface::MainInterface(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Widget);
    this->setFixedSize(900, 650);

    MainToolBt = new ToolBt();

    connect(MainToolBt, SIGNAL(LgnDlgClosed()), this, SLOT(close()));
    connect(MainToolBt, SIGNAL(LgnDLgMinimi()), this, SLOT(showMinimized()));

    MainLt = new QVBoxLayout();

    MainLt->addWidget(MainToolBt, 0, Qt::AlignTop | Qt::AlignRight);
    MainLt->setContentsMargins(0, 0, 0, 4);

    this->setLayout(MainLt);
}

MainInterface::~MainInterface()
{

}
