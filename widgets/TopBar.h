#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QLineEdit>

class TopBar : public QWidget
{
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);

private:
    QLineEdit *searchBox;

signals:
    void search(QString keyword);
public slots:
    void onSearch();

};

#endif // TOPBAR_H
