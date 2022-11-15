#include "qrcodegen.h"
#include "qrcode.h"
#include <QtXml>
#include <QTextStream>
#include <QGraphicsSvgItem>

using std::uint8_t;
using qrcode::QrCode;
using qrcode::QrSegment;
using qrcode::BitBuffer;

//générer un qrcode
QGraphicsScene * qrcodegen::genQRCode(std::string infoQRCode ){
    std::string filename="qrcode.svg";

    //enregistre le qrcode dans un fichier en utilisant les données passées infoQRCode
    qrcodegen::writeXMLFile(filename.data(), infoQRCode);

    //récupère le qrcode du fichier pour l'afficher
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSvgItem *item = new QGraphicsSvgItem(filename.data());
    scene->addItem(item);
    return scene;
}

void qrcodegen::writeXMLFile(std::string filename, std::string infoQRCode){
    QFile xmlFile(filename.data());
    if (!xmlFile.open(QFile::WriteOnly | QFile::Text ))
    {
        qDebug() << "Already opened or there is another issue";
        xmlFile.close();
    }
    QTextStream xmlContent(&xmlFile);

    std::string qrcodText;//, infoQRCode;
    //création du QRCode
    qrcodText = qrcodegen::getQRCode(infoQRCode);
    //qrcodText.data();

    xmlContent << qrcodText.data();//document.toString();
}



// return single QR Code.
std::string  qrcodegen::getQRCode(std::string infoQRCode) {
    const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;  // Error correction level du qrcode
    const QrCode qr = QrCode::encodeText(infoQRCode.data(), errCorLvl);
    return  qrcodegen::toSvgString(qr, 4) ;
}



/*---- Utilities ----*/

// Returns a string of SVG code for an image depicting the given QR Code, with the given number
// of border modules. The string always uses Unix newlines (\n), regardless of the platform.
std::string qrcodegen::toSvgString(const QrCode &qr, int border) {
    if (border < 0)
        throw std::domain_error("Border must be non-negative");
    if (border > INT_MAX / 2 || border * 2 > INT_MAX - qr.getSize())
        throw std::overflow_error("Border too large");

    std::ostringstream sb;
    sb << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    sb << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    sb << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 ";
    sb << (qr.getSize() + border * 2) << " " << (qr.getSize() + border * 2) << "\" stroke=\"none\">\n";
    sb << "\t<rect width=\"100%\" height=\"100%\" fill=\"#FFFFFF\"/>\n";
    sb << "\t<path d=\"";
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                if (x != 0 || y != 0)
                    sb << " ";
                sb << "M" << (x + border) << "," << (y + border) << "h1v1h-1z";
            }
        }
    }
    sb << "\" fill=\"#000000\"/>\n";
    sb << "</svg>\n";
    return sb.str();
}


//Afficher QR
void qrcodegen::showQRCode(QGraphicsView * qr_item, std::string infoQRCode)
{
QGraphicsScene *scene = new QGraphicsScene();

//génération QR Code
scene=qrcodegen::genQRCode(infoQRCode);

//Affichage QR Code
qr_item->setScene(scene);
qr_item->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
qr_item->show();
}
