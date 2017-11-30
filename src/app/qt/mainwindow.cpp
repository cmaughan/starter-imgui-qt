#include <QWidget>

#include "mcommon.h"
#include "mainwindow.h"

#include "window_qt.h"
#include "display_qt.h"

using namespace StarterKit;

MainWindow::MainWindow()
    : m_controller(this, std::static_pointer_cast<Display>(std::make_shared<QtDisplay>()))
{
    auto* pWindow = new QtWindow(m_controller, this);

    setContentsMargins(2, 2, 2, 2);
    setCentralWidget(pWindow);
}

void MainWindow::RequestRedraw()
{
    centralWidget()->update();
}
