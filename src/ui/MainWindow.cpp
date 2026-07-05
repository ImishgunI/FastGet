#include "MainWindow.hpp"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
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
    QWidget* addWindow = new QWidget();
    addWindow->setWindowTitle("Add new download");
    addWindow->resize(300, 200);
    QLabel* url = new QLabel("&URL:");
    QLineEdit* url_line = new QLineEdit;
    url->setBuddy(url_line);
    QLabel* save_path = new QLabel("&Save:");
    QLineEdit* save_path_line = new QLineEdit;
    save_path->setBuddy(save_path_line);
    QVBoxLayout* bl = new QVBoxLayout;
    bl->addWidget(url);
    bl->addWidget(url_line);
    bl->addWidget(save_path);
    bl->addWidget(save_path_line);
    addWindow->setLayout(bl);
    addWindow->show();
}

void MainWindow::startAction() {

}

void MainWindow::pauseAction() {

}

void MainWindow::removeAction() {

}
