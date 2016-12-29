#ifndef CIRCULARPHOTO_H
#define CIRCULARPHOTO_H

#define NULL_NUM 0
#define HD_PRTRT 86

#include <QSize>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class CircularPhoto : public QLabel
{
    Q_OBJECT

public:
    CircularPhoto(QWidget *parent = NULL_NUM, \
                  QImage image_usr = QImage("logo.png"), \
                  QSize image_size = QSize(HD_PRTRT, HD_PRTRT));
    ~CircularPhoto();
    void set_image(QImage &photo);

private:
    QImage img_usr;
    QSize  img_size;
    QImage getRoundQImage(const QImage& img, QSize size);
    void PaintEvent(QPaintEvent* p_event);
};

#endif // CIRCULARPHOTO_H
