#pragma once

#include <QMainWindow>
#include <QApplication>
#include <qaction.h>

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  void setupUI();
  void createMenu();
  void createToolBar();
  static void addAction();
  static void startAction();
  static void pauseAction();
  static void removeAction();

private:
  QAction* add;
  QAction* start;
  QAction* pause;
  QAction* remove;
};
