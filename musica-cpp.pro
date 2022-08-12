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
    src/components/playlist.cpp \
    src/main.cpp \
    src/components/BottomBar.cpp \
    src/components/ClickedLabel.cpp \
    src/components/ItemSong.cpp \
    src/components/LeftMenus.cpp \
    src/components/NetworkImage.cpp \
    src/components/VolumeButton.cpp \
    src/components/VolumeSlider.cpp \
    src/components/TopBar.cpp \
    src/db/database.cpp \
    src/pages/MainWindow.cpp \
    src/pages/DownloadPage.cpp \
    src/pages/FavoritePage.cpp \
    src/pages/SearchPage.cpp \
    src/models/Song.cpp \
    src/utils/CommonUtil.cpp

HEADERS += \
    src/components/playlist.h \
    src/constants.h \
    src/components/BottomBar.h \
    src/components/ClickedLabel.h \
    src/components/ItemSong.h \
    src/components/LeftMenus.h \
    src/components/NetworkImage.h \
    src/components/TopBar.h \
    src/components/VolumeButton.h \
    src/components/VolumeSlider.h \
    src/db/database.h \
    src/pages/MainWindow.h \
    src/pages/DownloadPage.h \
    src/pages/FavoritePage.h \
    src/pages/SearchPage.h \
    src/models/Song.h \
    src/utils/CommonUtil.h

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
