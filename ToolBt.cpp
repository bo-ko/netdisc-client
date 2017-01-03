#include "ToolBt.h"

ToolBt::ToolBt(QWidget *parent) : QWidget(parent)
{
    ExitBt = new QToolButton(this);
    MiniBt  = new QToolButton(this);

    ExitBt->setGeometry(64, 2, 24, 24);
    MiniBt->setGeometry(36, 2, 24, 24);

    connect(ExitBt, SIGNAL(clicked()), this, SIGNAL(Closed()));
    connect(MiniBt, SIGNAL(clicked()), this, SIGNAL(Minimi()));

    this->setFixedSize(93, 26);
}
