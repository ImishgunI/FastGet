#include "MainWindow.hpp"
#include <QMenuBar>

//    +---------------------------------------------------------------+
//    | File                    Settings                              |
//    +---------------------------------------------------------------+
//    | + Add | Start | Pause | Remove                                |
//    +---------------------------------------------------------------+
//    | File            Progress   Speed      Status       Size       |
//    |---------------------------------------------------------------|
//    | ubuntu.iso      37%        15 MB/s    Downloading  4.8 GB     |
//    | arch.iso        100%       -          Completed    1.2 GB     |
//    | movie.mkv       Paused     -          Paused       2.0 GB     |
//    |---------------------------------------------------------------|
//    | Active: 1    Waiting: 2                                Ready  |
//    +---------------------------------------------------------------+


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { setupUI(); }

void MainWindow::setupUI() { createMenu(); }

void MainWindow::createMenu() {
    QAction* quit = new QAction("&Quit", this);
    _m = menuBar()->addMenu("&File");
    _m->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    _m = menuBar()->addMenu("&Settings");
}
