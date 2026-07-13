#include "DownloadManager.hpp"

void DownloadManager::addTask(const QUrl& url, const QString& savePath) {
    tasks.emplace_back(std::make_unique<DownloadTask>(url, savePath));
}
