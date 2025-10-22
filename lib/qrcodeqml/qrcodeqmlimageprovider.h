#ifndef QRCODEQMLIMAGEPROVIDER_H
#define QRCODEQMLIMAGEPROVIDER_H

#include <QQuickImageProvider>

class QRCodeQmlImageProvider : public QQuickImageProvider
{
public:
    QRCodeQmlImageProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
};

#endif // QRCODEQMLIMAGEPROVIDER_H
