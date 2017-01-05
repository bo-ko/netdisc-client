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
#include <QMouseEvent>
#include <QApplication>

class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private:
    bool   DlgMoveing;
    QPoint DlgMovePosition;

    ToolBt      *DlgToolBt;
    QLabel      *HeaderPhoto;
    QLabel      *WarningLabel;
    QLabel      *RegisterLabel;
    QLabel      *FindPswdLabel;
    QLineEdit   *Passwd;
    QLineEdit   *UserName;
    QCheckBox   *AutoLogin;
    QCheckBox   *RmbrPasswd;  // remember password
    QPushButton *LoginBut;
    QVBoxLayout *DlgMainLt;
    QVBoxLayout *DlgWidgetLt;
    QHBoxLayout *AutoRmber;
    QHBoxLayout *OtherLabel;

    void InitData();
    void InitUi();
    void InitConnect();
    void WarningLayout();

private slots:
    void LoginClicked();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // LOGIN_H
