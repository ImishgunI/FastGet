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
)

target_link_libraries(
    DownloadManager
    PRIVATE
        Qt6::Widgets
        Qt6::Network
)


