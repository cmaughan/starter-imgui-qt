#include <QWidget>

#include "mcommon.h"
#include "window_qt.h"
#include "display_qt.h"
#include "controller.h"

namespace StarterKit
{

QtWindow::QtWindow(Controller& controller, QWidget* pParent)
    : m_controller(controller),
    QWidget(pParent)
{
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
}

QtWindow::~QtWindow()
{
}

void QtWindow::paintEvent(QPaintEvent* pPaint)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing, true);

    auto pQtDisplay = dynamic_cast<QtDisplay*>(m_controller.GetDisplay());
    pQtDisplay->SetPainter(&painter);

    m_controller.Render(Rect4f(painter.window().x(), painter.window().y(), painter.window().width(), painter.window().height()));

    pQtDisplay->SetPainter(nullptr);
}

}
