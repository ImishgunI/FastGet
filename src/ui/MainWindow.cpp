#include "MainWindow.hpp"
#include "AddDownload.hpp"
#include "DownloadStatusUtils.hpp"
#include <QMenuBar>
#include <QToolBar>
#include <QHeaderView>
#include <format>
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


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), manager() {
    setupUI(); 
    connect(&manager, &DownloadManager::taskUpdated, this, &MainWindow::updateRow);
}

void MainWindow::setupUI() {
    createMenu();
    createToolBar();
    createTableView();
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

void MainWindow::createTableView() {
    table = new QTableWidget(0, 5, this);
    QStringList headers = {"Name","Status", "Speed", "DownloadedBytes", "TotalBytes" };
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    table->horizontalHeader()->resizeSection(0, 75);
    table->horizontalHeader()->resizeSection(1, 75);
    table->horizontalHeader()->resizeSection(2, 75);
    table->horizontalHeader()->resizeSection(3, 140);
    table->horizontalHeader()->resizeSection(4, 100);
    table->setSortingEnabled(false);
    setCentralWidget(table);
}

void MainWindow::addAction() {
    AddDownloadDialog ad(this);
    if(ad.exec() == QDialog::Accepted) {
        auto task = manager.addTask(ad.getUrl(), ad.getSavePath());
        int row = table->rowCount();
        rows[&task] = row;
        addNewRow(task);
    }
}

void MainWindow::startAction() {
    manager.startTask(table->currentRow());
}

void MainWindow::pauseAction() {

}

void MainWindow::removeAction() {
    manager.removeTask(table->currentRow());
    manager.eraseVector(table->currentRow());
}

void MainWindow::addNewRow(const DownloadTask& task) {
    int indexRow = table->rowCount();
    table->insertRow(indexRow);
    table->setItem(indexRow, 0, new QTableWidgetItem(task.getUrl().fileName()));
    table->setItem(indexRow, 1, new QTableWidgetItem(downloadStatusToString(task.getStatus())));
    table->setItem(indexRow, 2, new QTableWidgetItem(std::format("{} KB/s", task.getSpeed()).c_str()));
    table->setItem(indexRow, 3, new QTableWidgetItem(std::format("{} B/s", task.getDownloadedBytes()).c_str()));
    table->setItem(indexRow, 4, new QTableWidgetItem(std::format("{} MB", task.getTotalBytes()).c_str()));
}

void MainWindow::updateRow(DownloadTask& task) {
    int row = rows[&task];
    table->item(row, 1)->setText(downloadStatusToString(task.getStatus()));
    table->item(row, 2)->setText(std::format("{:.2f} KB/s", task.getSpeed()).c_str());
    table->item(row, 3)->setText(std::format("{} B/s", task.getDownloadedBytes()).c_str());
    table->item(row, 4)->setText(std::format("{} MB", task.getTotalBytes()).c_str());
}
