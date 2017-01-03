#include "ToolBt.h"

ToolBt::ToolBt(QWidget *parent) : QWidget(parent)
{
    LoginExitBt = new QToolButton(this);
    LoginMiniBt  = new QToolButton(this);

    LoginExitBt->setGeometry(64, 2, 24, 24);
    LoginMiniBt->setGeometry(36, 2, 24, 24);

    connect(LoginExitBt, SIGNAL(clicked()), this, SIGNAL(LgnDlgClosed()));
    connect(LoginMiniBt, SIGNAL(clicked()), this, SIGNAL(LgnDLgMinimi()));

    this->setFixedSize(93, 26);
}
