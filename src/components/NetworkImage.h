#ifndef NETWORKIMAGE_H
#define NETWORKIMAGE_H

#include <QWidget>
#include <QLabel>

class NetworkImage : public QLabel {
Q_OBJECT
public:
    explicit NetworkImage(QWidget *parent = nullptr);

    void setImageUrl(const QString &szUrl);

signals:
};

#endif // NETWORKIMAGE_H
