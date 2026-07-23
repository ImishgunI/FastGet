#pragma once

#include "DownloadTask.hpp"
#include "../network/DownloadWorker.hpp"

#include <memory>
#include <qobject.h>
#include <vector>
#include <QUrl>
#include <QString>

class DownloadManager : public QObject {
Q_OBJECT
public:
    explicit DownloadManager(QObject* parent = nullptr);
    ~DownloadManager() override = default;

    DownloadTask& addTask(const QUrl& url, const QString& savePath);
    void startTask(int index);
    void removeTask(int index);
    void eraseVector(int index);
    void onTaskProgressChanged(DownloadTask* task);
signals:
    void taskUpdated(DownloadTask& task);

private:
    std::vector<std::unique_ptr<DownloadTask>> tasks;
    std::vector<std::unique_ptr<DownloadWorker>> activeWorkers;
};
