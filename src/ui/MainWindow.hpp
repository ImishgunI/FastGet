#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QString>
#include <QTableWidget>
#include <unordered_map>
#include "../core/DownloadManager.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  void setupUI();
  void createMenu();
  void createToolBar();
  void createTableView();
  void addAction();
  void startAction();
  void pauseAction();
  void removeAction();
  void addNewRow(const DownloadTask& task);
  void updateRow(DownloadTask& task);

private:
  QAction* add;
  QAction* start;
  QAction* pause;
  QAction* remove;
  DownloadManager manager;
  QTableWidget* table;
  std::unordered_map<DownloadTask*, int> rows;
};
