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
    main.cpp \
    widgets/MainWindow.cpp \
    widgets/BottomBar.cpp \
    widgets/ClickedLabel.cpp \
    widgets/DownloadPage.cpp \
    widgets/FavoritePage.cpp \
    widgets/ItemSong.cpp \
    widgets/LeftMenus.cpp \
    widgets/NetworkImage.cpp \
    widgets/SearchPage.cpp \
    widgets/Song.cpp \
    widgets/TopBar.cpp \
    utils/CommonUtil.cpp \
    widgets/VolumeButton.cpp

HEADERS += \
    connection.h \
    constants.h \
    widgets/MainWindow.h \
    widgets/BottomBar.h \
    widgets/ClickedLabel.h \
    widgets/DownloadPage.h \
    widgets/FavoritePage.h \
    widgets/ItemSong.h \
    widgets/LeftMenus.h \
    widgets/NetworkImage.h \
    widgets/SearchPage.h \
    widgets/Song.h \
    widgets/TopBar.h \
    utils/CommonUtil.h \
    widgets/VolumeButton.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

DISTFILES += \
    README.md \
    default.plist \
    style.qss
