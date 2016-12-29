#include "login_dlg.h"
#include "circularphoto.h"

LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(300, 282);
    this->setWindowFlags(Qt::FramelessWindowHint);

    /* new widgets */
    MainLayout = new QVBoxLayout(this);
    Passwd = new QLineEdit();
    UserName = new QLineEdit();
    LoginBut = new QPushButton(tr("Login"));
    HeaderPhoto = new CircularPhoto();
    WarningLabel = new QLabel(tr("<font color=red>Qt!</font>"));

    ChekAutoRmbr = new QHBoxLayout();
    AutoLogin = new QCheckBox(tr("AutoLogin"));
    RmbrPasswd = new QCheckBox(tr("Remember"));
    ChekAutoRmbr->addWidget(AutoLogin);
    ChekAutoRmbr->addStretch();
    ChekAutoRmbr->addWidget(RmbrPasswd);
    /* login button clicked signal */
    connect(LoginBut, SIGNAL(clicked()), this, SLOT(LoginClicked()));

    LoginExitBt = new QPushButton("x");
    LoginHidBt  = new QPushButton("-");
    LogDlgLayout = new QHBoxLayout();
    LogDlgLayout->addStretch();
    LogDlgLayout->addWidget(LoginHidBt, 0, Qt::AlignRight);
    LogDlgLayout->addWidget(LoginExitBt, 0,Qt::AlignRight);
    /* cloce app */
    connect(LoginExitBt, SIGNAL(clicked()), this, SLOT(close()));

    /* main layout */
    MainLayout->addLayout(LogDlgLayout);
    MainLayout->addStretch();
    MainLayout->addWidget(HeaderPhoto, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    MainLayout->addStretch();
    MainLayout->addWidget(WarningLabel, 0,  Qt::AlignHCenter);
    MainLayout->addStretch();
    MainLayout->addWidget(UserName);
    MainLayout->addStretch();
    MainLayout->addWidget(Passwd);
    MainLayout->addStretch();
    MainLayout->addLayout(ChekAutoRmbr);
    MainLayout->addStretch();
    MainLayout->addWidget(LoginBut);
    MainLayout->addStretch();

    WarningLabel->hide();
}


LoginDlg::~LoginDlg()
{

}


void LoginDlg::LoginClicked()
{
    accept();
}
