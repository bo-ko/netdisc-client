#ifndef TOOLBT_H
#define TOOLBT_H

#include <QWidget>
#include <QToolButton>

class ToolBt : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBt(QWidget *parent = 0);

    QToolButton *LoginExitBt; // close
    QToolButton *LoginMiniBt;  // minimize

signals:
    void LgnDLgMinimi();
    void LgnDlgClosed();

public slots:
};

#endif // TOOLBT_H
