#include "DownloadManager.hpp"
#include <memory>

DownloadManager::DownloadManager(QObject* parent) : QObject(parent) {}

DownloadTask& DownloadManager::addTask(const QUrl& url, const QString& savePath) {
    tasks.emplace_back(std::make_unique<DownloadTask>(url, savePath));
    auto worker = std::make_unique<DownloadWorker>();
    connect(worker.get(), &DownloadWorker::taskProgressChanged, this, &DownloadManager::onTaskProgressChanged);
    activeWorkers.emplace_back(std::move(worker));
    return *tasks.back();
}

void DownloadManager::startTask(int index) {
    activeWorkers[index]->startDownload(*tasks[index]);
}

void DownloadManager::removeTask(int index) {
    if (index >= activeWorkers.size() || index < 0) {
        return;
    }
    activeWorkers[index]->cancelDownload();
}

void DownloadManager::eraseVector(int index) {
    tasks.erase(tasks.begin() + index);
    activeWorkers.erase(activeWorkers.begin() + index);
}

void DownloadManager::onTaskProgressChanged(DownloadTask* task) {
    emit taskUpdated(*task);
}
