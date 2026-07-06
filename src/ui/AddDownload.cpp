#include "AddDownload.hpp"
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include <QPushButton>

AddDownloadDialog::AddDownloadDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Add New Download");
    resize(250, 150);
    QLabel* url = new QLabel("&URL:", this);
    QLineEdit* url_line = new QLineEdit(this);
    url->setBuddy(url_line);
    QLabel* save_path = new QLabel("&Save:", this);
    QLineEdit* save_path_line = new QLineEdit(this);
    save_path->setBuddy(save_path_line);
    QVBoxLayout* bl = new QVBoxLayout(this);
    bl->addWidget(url);
    bl->addWidget(url_line);
    bl->addWidget(save_path);
    bl->addWidget(save_path_line);
    QHBoxLayout* buttons_box = new QHBoxLayout(this);
    QPushButton* cancel_button = new QPushButton("&Cancel", this);
    buttons_box->addWidget(cancel_button);
    QPushButton* accept_button = new QPushButton("&Accept", this);
    buttons_box->addWidget(accept_button);
    bl->addLayout(buttons_box);
    connect(cancel_button, &QPushButton::clicked, this, &QDialog::accept);
    connect(accept_button, &QPushButton::clicked, this, &QDialog::reject);
}
