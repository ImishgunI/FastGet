#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include "../core/DownloadTask.hpp"
#include <QFile>
#include <memory>

class DownloadWorker : public QObject {
    Q_OBJECT

    public:
        explicit DownloadWorker(QObject* parent = nullptr);
        ~DownloadWorker() override = default;

        void startDownload(DownloadTask& task);
        void cancelDownload();
    signals:
        void taskProgressChanged(DownloadTask* task);

    private:
        QNetworkAccessManager manager;
        std::unique_ptr<QFile> file;
        QNetworkReply* reply = nullptr;
};
