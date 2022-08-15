cmake_minimum_required(VERSION 3.10.0)

project(musica-cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH $ENV{QT_HOME})

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia Sql)

add_executable(musica-cpp
        src/main.cpp
        src/components/playlist.cpp
        src/components/BottomBar.cpp
        src/components/ClickedLabel.cpp
        src/components/ItemSong.cpp
        src/components/LeftMenus.cpp
        src/components/NetworkImage.cpp
        src/components/VolumeButton.cpp
        src/components/VolumeSlider.cpp
        src/components/TopBar.cpp
        src/db/database.cpp
        src/pages/MainWindow.cpp
        src/pages/DownloadPage.cpp
        src/pages/FavoritePage.cpp
        src/pages/SearchPage.cpp
        src/models/Song.cpp
        src/utils/CommonUtil.cpp
        src/components/playlist.h
        src/constants.h
        src/components/BottomBar.h
        src/components/ClickedLabel.h
        src/components/ItemSong.h
        src/components/LeftMenus.h
        src/components/NetworkImage.h
        src/components/TopBar.h
        src/components/VolumeButton.h
        src/components/VolumeSlider.h
        src/db/database.h
        src/pages/MainWindow.h
        src/pages/DownloadPage.h
        src/pages/FavoritePage.h
        src/pages/SearchPage.h
        src/models/Song.h
        src/utils/CommonUtil.h
        )

target_link_libraries(musica-cpp
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::Sql
        )