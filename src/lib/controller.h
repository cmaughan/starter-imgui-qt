#pragma once
#include <memory>

struct Rect4f;

namespace StarterKit
{
class Display;

struct IControllerOwner
{
    virtual void RequestRedraw() = 0;
};

class Controller
{
public:
    Controller(IControllerOwner* pOwner, std::shared_ptr<Display> spDisplay)
        : m_spDisplay(spDisplay)
    {}

    void Render(const Rect4f& rc);
    Display* GetDisplay() const { return m_spDisplay.get(); }

private:
    std::shared_ptr<Display> m_spDisplay;
};

}