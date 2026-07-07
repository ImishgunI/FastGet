#pragma once

#include <QDialog>
#include <QString>
#include <QLineEdit>

class AddDownloadDialog : public QDialog {
public:
    explicit AddDownloadDialog(QWidget *parent = nullptr);
    ~AddDownloadDialog() override = default;

    QString url() const;
    QString savePath() const;

private:
    void browseSaveDir();
    QString fileNameFromUrl();

private:
    QLineEdit* url_line;
    QLineEdit* save_path_line;
};
