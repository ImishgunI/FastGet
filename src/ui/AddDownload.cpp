#include "AddDownload.hpp"
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QUrl>

AddDownloadDialog::AddDownloadDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Add New Download");
    resize(400, 150);

    QLabel* url = new QLabel("&URL:", this);
    url_line = new QLineEdit(this);
    url->setBuddy(url_line);

    QVBoxLayout* bl = new QVBoxLayout(this);
    bl->addWidget(url);
    bl->addWidget(url_line);

    QLabel* save_path = new QLabel("&Save:", this);
    bl->addWidget(save_path);
    save_path_line = new QLineEdit(this);
    save_path->setBuddy(save_path_line);

    QPushButton* browse = new QPushButton("&Browse", this);
    QHBoxLayout* save_box = new QHBoxLayout();
    save_box->addWidget(save_path_line);
    save_box->addWidget(browse);
    bl->addLayout(save_box);

    QHBoxLayout* buttons_box = new QHBoxLayout();
    QPushButton* cancel_button = new QPushButton("&Cancel", this);
    buttons_box->addWidget(cancel_button);
    QPushButton* accept_button = new QPushButton("&Accept", this);
    buttons_box->addWidget(accept_button);

    bl->addLayout(buttons_box);
    connect(cancel_button, &QPushButton::clicked, this, &QDialog::reject);
    connect(accept_button, &QPushButton::clicked, this, &QDialog::accept);
    connect(browse, &QPushButton::clicked, this, &AddDownloadDialog::browseSaveDir);
}

void AddDownloadDialog::browseSaveDir() {
    auto downloads = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    auto path = QFileDialog::getExistingDirectory(this, tr("Save File"), downloads);
    if (!path.isEmpty()) {
        save_path_line->setText(path + "/" + fileNameFromUrl());
    }
}

QString AddDownloadDialog::fileNameFromUrl() {
    QUrl url_path(url_line->text());
    return url_path.fileName();
}

QString AddDownloadDialog::getUrl() const {
    return url_line->text();
}

QString AddDownloadDialog::getSavePath() const {
    return save_path_line->text();
}
