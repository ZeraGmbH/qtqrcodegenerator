#include "qrcodeitem.h"
#include "QrCodeGenerator.h"
#include <QPainter>

QRCodeItem::QRCodeItem(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
}

const QString &QRCodeItem::getQrCodeText() const
{
    return m_qrCodeString;
}

void QRCodeItem::setGetQrCodeText(const QString &text)
{
    if(text != m_qrCodeString) {
        m_qrCodeString = text;
        emit qrCodeTextChanged();
        update();
    }
}

void QRCodeItem::paint(QPainter *painter)
{
    int len = getClipSquareLen(painter);
    len = std::min(len, int(std::numeric_limits<quint16>::max()));

    QrCodeGenerator qrGen;
    QImage image = qrGen.generateQr(m_qrCodeString, len);
    QRect boundRect = boundingRect().toRect();
    QRect imageRect = calcPaintingRect(boundRect, len);
    painter->drawImage(imageRect, image);
}

int QRCodeItem::getClipSquareLen(const QPainter *painter)
{
    QPaintDevice *paintDevice = painter->device();
    if (paintDevice) {
        const int w = paintDevice->width();
        const int h = paintDevice->height();
        return std::min(h, w);
    }
    return 1;
}

QRect QRCodeItem::calcPaintingRect(const QRect &boundingRect, int squareLen)
{
    int xOffset = 0;
    int yOffset = 0;
    int boundWidth = boundingRect.width();
    int boundHeight = boundingRect.height();
    if (boundWidth > squareLen)
        xOffset = (boundWidth - squareLen) / 2;
    if (boundHeight > squareLen)
        yOffset = (boundHeight - squareLen) / 2;
    return QRect(xOffset, yOffset, squareLen, squareLen);
}
