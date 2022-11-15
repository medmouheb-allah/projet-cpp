#include "image.h"

image::image()
{
}

    void image::showImage(QGraphicsView * item_img, QByteArray img) {
    QGraphicsScene *scene = new QGraphicsScene();

    //convertion mel base64  lel image
    QByteArray base64 = img ;
    QByteArray bytes = QByteArray::fromBase64(base64);

    QPixmap pixmap;
    pixmap.loadFromData(bytes,"PNG");

    //base -> pixmap -> scene

    //Récupérer image
    scene->addPixmap(pixmap);

    //Affichage Image
    item_img->setScene(scene);
    item_img->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    item_img->show();

    }
