#include "login_dlg.h"
#include "circularphoto.h"

LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(300, 260);

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

    /* main layout */
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
}

LoginDlg::~LoginDlg()
{
    delete Passwd;
    delete UserName;
    delete LoginBut;
    delete HeaderPhoto;
    delete MainLayout;
    delete WarningLabel;
    delete ChekAutoRmbr;
    delete AutoLogin;
    delete RmbrPasswd;
}
