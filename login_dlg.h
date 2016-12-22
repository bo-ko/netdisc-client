#ifndef LOGIN_H
#define LOGIN_H

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private:
    QLineEdit   *Passwd;
    QLineEdit   *UserName;
    QPushButton *LoginBut;
    QLabel      *HeaderPhoto;
    QVBoxLayout *MainLayout;
    QCheckBox   *AutoLogin;
    QCheckBox   *RmbrPasswd;  // remember password
    QHBoxLayout *ChekAutoRmbr;
    QLabel      *WarningLabel;

private slots:

};

#endif // LOGIN_H
