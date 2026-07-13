#pragma once

#include "DownloadTask.hpp"

#include <memory>
#include <vector>
#include <QUrl>
#include <QString>

class DownloadManager {
public:
    void addTask(const QUrl& url, const QString& savePath);

private:
    std::vector<std::unique_ptr<DownloadTask>> tasks;
};
