#include "LoginDlg.h"
#include "CircularPhoto.h"

LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent)
{
    _width = this->width(); // widget width
    InitLgnDlgUI();
    WarningLayout();
}


LoginDlg::~LoginDlg()
{
}

void LoginDlg::InitLgnDlgUI()
{
    this->setFixedSize(300, 270);
    this->setWindowFlags(Qt::FramelessWindowHint);

    /* new widgets */
    DlgToolBt = new ToolBt();
    connect(DlgToolBt, SIGNAL(LgnDlgClosed()), this, SLOT(close()));
    connect(DlgToolBt, SIGNAL(LgnDLgMinimi()), this, SLOT(showMinimized()));

    Passwd = new QLineEdit();
    UserName = new QLineEdit();
    LoginBut = new QPushButton(tr("Login"));
    /* login button clicked signal */
    connect(LoginBut, SIGNAL(clicked()), this, SLOT(LoginClicked()));
    HeaderPhoto = new CircularPhoto();

    OtherLabel = new QHBoxLayout();
    RegisterLabel = new QLabel();
    RegisterLabel->setOpenExternalLinks(true);
    RegisterLabel->setText(tr("<a href=\"http://www.csdn.net/\">打开CSDN"));
    FindPswdLabel = new QLabel();
    FindPswdLabel->setOpenExternalLinks(true);
    FindPswdLabel->setText(tr("<a href=\"http://www.baidu.com/\">打开Baidu"));
    OtherLabel->addWidget(RegisterLabel);
    OtherLabel->addStretch();
    OtherLabel->addWidget(FindPswdLabel);

    WarningLabel = new QLabel(tr("<font color=red>Qt!</font>"));
    WarningLabel->hide();

    AutoRmber = new QHBoxLayout();
    AutoLogin = new QCheckBox(tr("AutoLogin"));
    RmbrPasswd = new QCheckBox(tr("Remember"));
    AutoRmber->addWidget(AutoLogin);
    AutoRmber->addStretch();
    AutoRmber->addWidget(RmbrPasswd);

    DlgMainLt = new QVBoxLayout();
    DlgWidgetLt = new QVBoxLayout();

    DlgWidgetLt->setContentsMargins(37, 0, 37, 4);

    DlgWidgetLt->addWidget(HeaderPhoto, 0, Qt::AlignTop | Qt::AlignCenter);
    DlgWidgetLt->addWidget(UserName);
    DlgWidgetLt->addWidget(Passwd);
    DlgWidgetLt->addLayout(AutoRmber);
    DlgWidgetLt->addWidget(LoginBut);
    DlgWidgetLt->addLayout(OtherLabel);


    DlgMainLt->addWidget(DlgToolBt, 0, Qt::AlignRight | Qt::AlignTop);
    DlgMainLt->addLayout(DlgWidgetLt);
    DlgMainLt->setContentsMargins(0, 0, 0, 4);

    this->setLayout(DlgMainLt);

}

void LoginDlg::WarningLayout()
{


    //this->update();
}

void LoginDlg::LoginClicked()
{
    accept();
}
