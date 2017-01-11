#include "CircularPhoto.h"

CircularPhoto::CircularPhoto(QWidget *parent, QImage image_usr, QSize image_size)
    : QLabel(parent), img_usr(image_usr), img_size(image_size)
{
    InitData();
    InitUi();
}

CircularPhoto::~CircularPhoto()
{}

void CircularPhoto::InitData()
{
    img_usr  = QImage("logo.png");
    img_size = QSize(HD_PRTRT, HD_PRTRT);
}

void CircularPhoto::InitUi()
{
    this->setPixmap(QPixmap::fromImage(getRoundQImage(img_usr, img_size)));
}

/* set image
 *
 *
 */
void CircularPhoto::set_image(QImage &photo)
{
    QImage image_usr = photo;
}

/*
 * The picture is processed into a circle
 *
 */
QImage CircularPhoto::getRoundQImage(const QImage& img,QSize size)
{
    if (img.isNull())
    {
        return QImage();
    }

    QImage resultImage(size,QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&resultImage);
    painter.setRenderHints(QPainter::SmoothPixmapTransform); // Antialiasing
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);   // Transparent
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    QImage mask("mask.png");
    painter.drawImage(NULL_NUM, NULL_NUM, mask);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
    painter.drawImage(NULL_NUM, NULL_NUM, img.scaled(size));
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.end();

    return resultImage;
}

/*
 * Paint event function
 *
 */
void CircularPhoto::PaintEvent(QPaintEvent* p_event)
{
    QPainter p(this);
    p.drawImage(NULL_NUM, NULL_NUM, getRoundQImage(img_usr, img_size));
    return QLabel::paintEvent(p_event);
}
