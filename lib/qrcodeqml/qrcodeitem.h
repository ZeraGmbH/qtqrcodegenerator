#ifndef QRCODEITEM_H
#define QRCODEITEM_H

#include <QQuickPaintedItem>

class QRCodeItem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit QRCodeItem(QQuickItem *parent = nullptr);
    Q_PROPERTY(QString qrCodeText READ getQrCodeText WRITE setGetQrCodeText NOTIFY qrCodeTextChanged FINAL)
    const QString &getQrCodeText() const;
    void setGetQrCodeText(const QString &text);
signals:
    void qrCodeTextChanged();
private:
    void paint(QPainter *painter) override;
    static int getClipSquareLen(const QPainter *painter);
    static QRect calcPaintingRect(const QRect &boundingRect, int squareLen);

    QString m_qrCodeString;
};

#endif // QRCODEITEM_H
