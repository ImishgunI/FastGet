#include "AddDownload.hpp"
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>

AddDownloadDialog::AddDownloadDialog(QWidget* parent) : QDialog(parent) {
    QWidget* addWindow = new QWidget();
    addWindow->setWindowTitle("Add new download");
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
