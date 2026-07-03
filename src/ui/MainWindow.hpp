#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  void setupUI();
  void createMenu();

private:
  QMenu *_m;
  QAction *_a1;
};
