#include <QApplication.h>
#include "mcommon.h"
#include "display_qt.h"

// This is an ImGui specific renderer for .  Simple interface for drawing chars, rects, lines.
// Implement a new display for a different rendering type - e.g. terminal or windows Gui.jj
namespace StarterKit
{

QtDisplay::QtDisplay()
{
    qApp->setFont(QFont("Consolas", 9));
}

QtDisplay::~QtDisplay()
{
}

float QtDisplay::GetFontSize() const
{
    QFontMetrics met(qApp->font());
    return met.height();
}

glm::vec2 QtDisplay::GetTextSize(const char* pBegin, const char* pEnd) const
{
    QFontMetrics met(qApp->font());
    if (pEnd == nullptr)
    {
        pEnd = pBegin + strlen((const char*)pBegin);
    }
    auto rc = met.size(Qt::TextSingleLine, QString::fromUtf8((char*)pBegin, pEnd- pBegin));
    return glm::vec2(rc.width(), rc.height());
}

void QtDisplay::DrawChars(const glm::vec2& pos, uint32_t col, const char* text_begin, const char* text_end) const
{
    if (text_end == nullptr)
    {
        text_end = text_begin + strlen((const char*)text_begin);
    }
    QPoint p0 = toQPoint(pos);
    uint32_t color = (qAlpha(col) << 24) | (qRed(col)) | (qGreen(col) << 8) | (qBlue(col) << 16);
    m_pPainter->setPen(QColor::fromRgba(color));
    p0.setY(p0.y() + GetFontSize());
    m_pPainter->drawText(p0, QString::fromUtf8((char*)text_begin, text_end - text_begin));
}

void QtDisplay::DrawLine(const glm::vec2& start, const glm::vec2& end, uint32_t color, float width) const
{
    QPoint p0 = toQPoint(start);
    QPoint p1 = toQPoint(end);
    m_pPainter->setPen(QPen(QBrush(QColor::fromRgba(color)), width));
    m_pPainter->drawLine(p0, p1);
}

void QtDisplay::DrawRectFilled(const glm::vec2& a, const glm::vec2& b, uint32_t color) const
{
    QPoint start = toQPoint(a);
    QPoint end = toQPoint(b);
    m_pPainter->fillRect(QRect(start, end), QColor::fromRgba(color));
}

} // 
