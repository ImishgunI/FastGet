#include "DownloadStatusUtils.hpp"

QString downloadStatusToString(DownloadStatus status) {
    switch(status) {
        case DownloadStatus::Queued:
            return "Queued";
        case DownloadStatus::Cancelled:
            return "Cancelled";
        case DownloadStatus::Downloading:
            return "Downloading";
        case DownloadStatus::Completed:
            return "Completed";
        case DownloadStatus::Failed:
            return "Failed";
        case DownloadStatus::Paused:
            return "Paused";
        default:
            return "Uknown status";
    }
    return "";
}
