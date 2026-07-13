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

    void setStatus(DownloadStatus status);
    void setDownloadedBytes(quint64 dbytes);
    void setTotalBytes(quint64 tbytes);
    void setSpeed(double speed);

    QUrl getUrl() const;
    QString getSavePath() const;
    DownloadStatus getStatus() const;
    quint64 getDownloadedBytes() const;
    quint64 getTotalBytes() const;
    double getSpeed() const;

private:
    QUrl url;
    QString savePath;
    DownloadStatus status;
    quint64 downloadedBytes;
    quint64 totalBytes;
    double speed;
};
