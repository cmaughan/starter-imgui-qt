#include <QApplication>
#include <QTimer>
#include <QMainwindow.h>

#include "mcommon.h"

#include "mainwindow.h"
#include "common_qt.h"
#include "display_qt.h"

#include "controller.h"
#include "display.h"

using namespace StarterKit;

int main(int argc, char** argv)
{

    QApplication app(argc, argv);

    MainWindow mainWin;
    mainWin.resize(DPI::ScalePixels(250, 200));
    mainWin.show();

    return app.exec();
}
