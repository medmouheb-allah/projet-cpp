#ifndef IMAGE_SALLE_H
#define IMAGE_SALLE_H
#include<QPixmap>
#include <QSqlQuery>
#include <QVariant>
#include <QBuffer>
#include<QGraphicsView>

class image
{
public:

    image();


    QPixmap retrievePixmap(int id);
    static void showImage(QGraphicsView * item_img, QByteArray img);
};

#endif // IMAGE_H
