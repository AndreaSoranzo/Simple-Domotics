#include <QApplication>
#include <QFontDatabase>
#include <QStyleFactory>

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/MainWindow.h"

struct WindowSettings {
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 900;
    const int WINDOW_MIN_WIDTH = 700;
    const int WINDOW_MIN_HEIGHT = 790;
    const char* WINDOW_TITLE = "Simple Domotics";
    const char* WINDOW_ICON = ":assets/icons/window_icon.svg";
    const char* WINDOW_DEFAULT_FONT = ":assets/fonts/Montserrat.ttf";
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    WindowSettings settings;
    app.setWindowIcon(QIcon(settings.WINDOW_ICON));
    app.setStyle(QStyleFactory::create("Fusion"));

    int fontId = QFontDatabase::addApplicationFont(settings.WINDOW_DEFAULT_FONT);
    if (fontId != -1) {
        app.setFont(QFontDatabase::applicationFontFamilies(fontId).at(0));
    } else {
        qWarning() << "error loading font";
    }

    Model model;
    MainWindow mainWindow(&app);
    Controller controller(model, mainWindow);

    mainWindow.resize(settings.WINDOW_WIDTH, settings.WINDOW_HEIGHT);
    mainWindow.setMinimumSize(settings.WINDOW_MIN_WIDTH, settings.WINDOW_MIN_HEIGHT);
    mainWindow.setWindowTitle(settings.WINDOW_TITLE);

    controller.Init();

    return app.exec();
}
