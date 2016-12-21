#include "circularphoto.h"

CircularPhoto::CircularPhoto(QLabel *parent, QImage image_usr, QSize image_size)
    : QLabel(parent), img_usr(image_usr), img_size(image_size)
{

}
// 设置图片
void CircularPhoto::set_image(QImage &photo)
{

}

// 图片处理成圆形
QImage CircularPhoto::getRoundQImage(const QImage& img,QSize size)
{
    if (img.isNull())
    {
        return QImage();
    }

    QImage resultImage(size,QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&resultImage);

    painter.setRenderHints(QPainter::SmoothPixmapTransform);//消锯齿
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent); // 透明
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    QImage mask(":/images/mask96px.png");
    painter.drawImage(NULL_NUM, NULL_NUM, mask);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
    painter.drawImage(NULL_NUM, NULL_NUM, img.scaled(size));
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);

    painter.end();

    return resultImage;
}

// 画图事件函数
void CircularPhoto::PaintEvent(QPaintEvent* p_event)
{
    Q_UNUSED(p_event);

    QPainter p;
    p.drawImage(NULL_NUM, NULL_NUM, getRoundQImage(img_usr, img_size));
}
