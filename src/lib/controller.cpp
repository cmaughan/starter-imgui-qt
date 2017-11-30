#include "mcommon.h" 
#include "controller.h"
#include "display.h"

namespace StarterKit
{

void Controller::Render(const Rect4f& rc)
{
    // TODO: App display
    GetDisplay()->DrawRectFilled(rc.TopLeft(), rc.BottomRight(), 0xFF333333);
    GetDisplay()->DrawRectFilled(rc.TopLeft(), rc.TopLeft() + glm::vec2(100, 100), 0xFFFFFFFF);
    GetDisplay()->DrawLine(rc.TopLeft() + glm::vec2(100, 100), rc.TopLeft() + glm::vec2(110, 110), 0xFFFFFF00, 2);
    GetDisplay()->DrawChars(rc.TopLeft() + glm::vec2(120, 120), 0xFFFF8866, "Hello");
}

}