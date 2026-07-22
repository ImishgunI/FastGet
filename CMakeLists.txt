cmake_minimum_required(VERSION 3.20)
project(DownloadManager VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

qt_add_executable(DownloadManager
    src/main.cpp
    src/ui/MainWindow.cpp
    src/ui/MainWindow.hpp
    src/ui/AddDownload.cpp
    src/ui/AddDownload.hpp
    src/ui/DownloadStatusUtils.hpp
    src/ui/DownloadStatusUtils.cpp
    src/core/DownloadTask.hpp
    src/core/DownloadTask.cpp
    src/core/DownloadManager.hpp
    src/core/DownloadManager.cpp
    src/network/DownloadWorker.cpp
    src/network/DownloadWorker.hpp
)

target_link_libraries(
    DownloadManager
    PRIVATE
        Qt6::Widgets
        Qt6::Network
)


