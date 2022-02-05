#include "NetworkImage.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QEventLoop>

NetworkImage::NetworkImage(QWidget *parent) : QLabel{parent}
{

}

void NetworkImage::setImageUrl(const QString &szUrl)
{
    QUrl url(szUrl);
    QNetworkAccessManager manager;
    QEventLoop loop;

    qDebug() << "Reading picture form " << url;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    pixmap = pixmap.scaled(width(), height(), Qt::KeepAspectRatio);
    setPixmap(pixmap);
    reply->deleteLater();
}
