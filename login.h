#ifndef LOGIN_H
#define LOGIN_H

#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class Login : public QDialog
{
public:
    Login();
    ~Login();

private:
    QLineEdit   *Passw;
    QLineEdit   *UserName;
    QPushButton *LoginBut;
    QPushButton *CancelBut;
    QLabel      *HeaderPhoto;

private slots:
    void on_cancel_but_clicked();
};

#endif // LOGIN_H
