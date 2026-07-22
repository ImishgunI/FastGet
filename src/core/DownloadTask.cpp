#include "DownloadTask.hpp"

DownloadTask::DownloadTask(const QUrl& url, const QString& savePath)
    : url(url), savePath(savePath),
    status(DownloadStatus::Queued),
    downloadedBytes(0),
    totalBytes(0),
    speed(0.0) {}

void DownloadTask::setStatus(DownloadStatus status) {
    this->status = status;
}

void DownloadTask::setDownloadedBytes(quint64 dbytes) {
    downloadedBytes = dbytes;
}

void DownloadTask::setTotalBytes(quint64 tbytes) {
    totalBytes = tbytes;
}

void DownloadTask::setSpeed(double speed) {
    this->speed = speed;
}

const QUrl& DownloadTask::getUrl() const {
    return url;
}

const QString& DownloadTask::getSavePath() const {
    return savePath;
}

DownloadStatus DownloadTask::getStatus() const {
    return status;
}

quint64 DownloadTask::getDownloadedBytes() const {
    return downloadedBytes;
}

quint64 DownloadTask::getTotalBytes() const {
    return totalBytes / 1000000;
}

double DownloadTask::getSpeed() const {
    return speed;
}
