#ifndef LOGIN_H
#define LOGIN_H

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>


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
    QToolButton *LoginExitBt; // close
    QToolButton *LoginHidBt;  // minimize
    QLabel      *RegisterLabel;
    QLabel      *FindPswdLabel;
    void InitLgnDlgUI();
    void WarningLayout();


private slots:
    void LoginClicked();

};

#endif // LOGIN_H
