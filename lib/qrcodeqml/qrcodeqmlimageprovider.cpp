#include "qrcodeqmlimageprovider.h"
#include "QrCodeGenerator.h"

QRCodeQmlImageProvider::QRCodeQmlImageProvider() :
    QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage QRCodeQmlImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    int lenRequested = std::min(requestedSize.height(), requestedSize.width());
    lenRequested = std::max(lenRequested, 1000);
    lenRequested = std::min(lenRequested, int(std::numeric_limits<quint16>::max()));
    if (size)
        *size = QSize(lenRequested, lenRequested);
    QrCodeGenerator qrGen;
    return qrGen.generateQr(id, lenRequested);
}
