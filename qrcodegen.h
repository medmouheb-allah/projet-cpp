#ifndef QRCODEGEN_H
#define QRCODEGEN_H

#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <qrcode.h>
#include <QGraphicsScene>
#include <QGraphicsView>

//using std::uint8_t;
using qrcode::QrCode;
using qrcode::QrSegment;

class qrcodegen
{

public :
    qrcodegen();
    ~qrcodegen();

    static QGraphicsScene *  genQRCode(std::string infoQRCode);
    static void writeXMLFile(std::string filename, std::string infoQRCode);
    static std::string getQRCode(std::string infoQRCode);
    static std::string toSvgString(const QrCode &qr, int border);
    static std::string getfileName();
    static void showQRCode(QGraphicsView * qr_item, std::string infoQRCode);
};



#endif // QRCODEGEN_H
