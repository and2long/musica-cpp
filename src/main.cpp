#include "src/db/database.h"
#include "src/pages/MainWindow.h"
#include <QApplication>
#include <QFile>

void loadQSS() {
    QFile f(":/assets/qss/style.qss");
    if (f.open(QFile::ReadOnly)) {
        QString str = QLatin1String(f.readAll());
        qApp->setStyleSheet(str);
        f.close();
    } else {
        qDebug() << "没有找到样式文件。";
    }
}

int main(int argc, char *argv[]) {
    Database::init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    loadQSS();
    return QApplication::exec();
}
