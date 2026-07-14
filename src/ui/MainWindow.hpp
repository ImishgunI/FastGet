#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QString>
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

private:
  QAction* add;
  QAction* start;
  QAction* pause;
  QAction* remove;
  DownloadManager* manager;
};
