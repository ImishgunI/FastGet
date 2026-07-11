#pragma once

#include <cstdint>
#include <QUrl>
#include <QString>
#include <QtTypes>

enum class DownloadStatus : uint8_t {
    Queued,
    Downloading,
    Paused,
    Completed,
    Failed,
    Cancelled
};

class DownloadTask {
public:
    DownloadTask(const QUrl& url, const QString& savePath);
    ~DownloadTask() = default;

private:
    QUrl url;
    QString savePath;
    DownloadStatus status;
    quint64 downloadedBytes;
    quint64 totalBytes;
    double speed;
};
