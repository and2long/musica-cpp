#include "widgets/MainWindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

void loadQSS()
{
    QFile f(":/qss/style.qss");
    if (f.open(QFile::ReadOnly))
    {
        QString str = QLatin1String(f.readAll());
        qApp->setStyleSheet(str);
        f.close();
    }
    else
    {
        qDebug() << "没有找到样式文件。";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    loadQSS();
    return a.exec();
}
