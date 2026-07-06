#pragma once

#include <QDialog>

class AddDownloadDialog : public QDialog {
public:
    explicit AddDownloadDialog(QWidget *parent = nullptr);
    ~AddDownloadDialog() override = default;
};
