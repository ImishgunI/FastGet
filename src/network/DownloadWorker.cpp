#include "../network/DownloadWorker.hpp"
#include <QNetworkReply>
#include <QDebug>
#include <qnetworkaccessmanager.h>

DownloadWorker::DownloadWorker(QObject* parent) : QObject(parent) {}

void DownloadWorker::startDownload(DownloadTask& task) {
    file = std::make_unique<QFile>((task.getSavePath()));
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug() << "Ошибка открытия файла: " << file->errorString();
    }
    QNetworkRequest request(task.getUrl());

    reply = manager.get(request);
    if (reply) {
        task.setStatus(DownloadStatus::Downloading);
    }
    connect(reply, &QNetworkReply::downloadProgress, this, [this, &task](qint64 received, qint64 total){
            task.setDownloadedBytes(received);
            task.setTotalBytes(total);
            task.setSpeed((static_cast<double>(total) / static_cast<double>(received)));
            task.setStatus(DownloadStatus::Downloading);
            emit taskProgressChanged(&task);
    });
    connect(reply, &QNetworkReply::readyRead, this, [this](){
            file->write(reply->readAll());
    });

    connect(reply, &QNetworkReply::finished, this, [this, &task](){
            file->close();
            if (reply->error() == QNetworkReply::NoError) {
                task.setStatus(DownloadStatus::Completed);
                task.setSpeed(0.0);
                task.setDownloadedBytes(0);
            } else if (reply->error() == QNetworkReply::OperationCanceledError) {
                file->remove();
                task.setStatus(DownloadStatus::Cancelled);
                task.setSpeed(0.0);
                task.setDownloadedBytes(0);
            }
            reply->deleteLater();
            reply = nullptr;
            emit taskProgressChanged(&task);
    });

    connect(reply, &QNetworkReply::errorOccurred, this, [this, &task, &request](){
            file->close();
            qDebug() << reply->errorString();
            task.setStatus(DownloadStatus::Failed);
            emit taskProgressChanged(&task);
    });
}

void DownloadWorker::cancelDownload() {
    if (!reply) {
        return;
    }
    reply->abort();
}
