#pragma once

#include <QMainWindow>
#include <memory>
#include "controller.h"

namespace StarterKit
{
class Controller;
}

class MainWindow : public QMainWindow,
    public StarterKit::IControllerOwner
{
public:
    Q_OBJECT

public:
    MainWindow();

    // Controller owner
    virtual void RequestRedraw() override;

private:
    StarterKit::Controller m_controller;
};
