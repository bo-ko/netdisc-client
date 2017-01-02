#ifndef LOGIN_H
#define LOGIN_H

#include "ToolBt.h"

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private:
    int _width;
    QLineEdit   *Passwd;
    QLineEdit   *UserName;
    QPushButton *LoginBut;
    QLabel      *HeaderPhoto;
    QCheckBox   *AutoLogin;
    QCheckBox   *RmbrPasswd;  // remember password
    QLabel      *WarningLabel;
    QLabel      *RegisterLabel;
    QLabel      *FindPswdLabel;
    QVBoxLayout *DlgMainLt;
    QVBoxLayout *DlgWidgetLt;
    QHBoxLayout *AutoRmber;
    QHBoxLayout *OtherLabel;
    ToolBt *DlgToolBt;
    void InitLgnDlgUI();
    void WarningLayout();


private slots:
    void LoginClicked();

};

#endif // LOGIN_H
