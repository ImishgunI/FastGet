#include "ui/MainWindow.hpp"
#include <QAction>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow window{};
    window.setWindowTitle("FastGet");
    window.resize(1920, 1080);
    window.show();
    return app.exec();
}
