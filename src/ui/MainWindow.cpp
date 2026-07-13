#include "MainWindow.hpp"
#include "AddDownload.hpp"
#include <QMenuBar>
#include <QToolBar>
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

void MainWindow::setupUI() { 
    createMenu();
    createToolBar();
}

void MainWindow::createMenu() {
    QAction* quit = new QAction("&Quit", this);
    auto* file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    auto* settings = menuBar()->addMenu("&Settings");
}

void MainWindow::createToolBar() {
    QToolBar* toolbar = addToolBar("main toolbar");
    add = toolbar->addAction("+ Add");
    connect(add,  &QAction::triggered, this, &MainWindow::addAction);
    start = toolbar->addAction("Start");
    connect(start, &QAction::triggered, this, &MainWindow::startAction);
    pause = toolbar->addAction("Pause");
    connect(pause, &QAction::triggered, this, &MainWindow::pauseAction);
    remove = toolbar->addAction("Remove");
    connect(remove, &QAction::triggered, this, &MainWindow::removeAction);
}

void MainWindow::addAction() {
    AddDownloadDialog ad(this);
    if(ad.exec() == QDialog::Accepted) {
        manager->addTask(ad.getUrl(), ad.getSavePath());
    }
}

void MainWindow::startAction() {

}

void MainWindow::pauseAction() {

}

void MainWindow::removeAction() {

}
