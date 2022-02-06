QT       += core gui
QT       += multimedia
QT       += sql

QMAKE_INFO_PLIST += $${TARGET}/default.plist

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BottomBar.cpp \
    ClickedLabel.cpp \
    DownloadPage.cpp \
    FavoritePage.cpp \
    ItemSong.cpp \
    LeftMenus.cpp \
    MainWindow.cpp \
    NetworkImage.cpp \
    SearchPage.cpp \
    Song.cpp \
    Toast.cpp \
    TopBar.cpp \
    main.cpp \
    tools/CommonUtils.cpp

HEADERS += \
    BottomBar.h \
    ClickedLabel.h \
    DownloadPage.h \
    FavoritePage.h \
    ItemSong.h \
    LeftMenus.h \
    MainWindow.h \
    NetworkImage.h \
    SearchPage.h \
    Song.h \
    Toast.h \
    TopBar.h \
    connection.h \
    constants.h \
    tools/CommonUtils.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

DISTFILES += \
    default.plist \
    style.qss
