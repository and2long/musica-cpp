#include "MainWindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // 加载qss样式
    QFile f(":/style.qss");
    if (f.open(QFile::ReadOnly)){
        QString str = QLatin1String(f.readAll());
        qApp->setStyleSheet(str);
        f.close();
    }
    else {
        qDebug() <<  "没有找到样式文件。";
    }
    return a.exec();
}
