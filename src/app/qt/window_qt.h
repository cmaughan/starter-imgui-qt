#pragma once

#include <QWidget>
#include <QTimer>
#include <memory>

namespace StarterKit
{

class Controller;
class QtDisplay;
class QtWindow : public QWidget
{
public:
    QtWindow(Controller& controller, QWidget* pParent);
    virtual ~QtWindow();

    void paintEvent(QPaintEvent* pPaint) override;

private slots:
    void OnTimer();

private:
    Controller& m_controller;
    QTimer m_refreshTimer;
};

}