#include "mcommon.h"
#include "display_imgui.h"

// This is an ImGui specific renderer for StarterKit.  Simple interface for drawing chars, rects, lines.
// Implement a new display for a different rendering type 
namespace StarterKit
{

ImGuiDisplay::ImGuiDisplay()
{
}

ImGuiDisplay::~ImGuiDisplay()
{
}

float ImGuiDisplay::GetFontSize() const
{
    return ImGui::GetFontSize();
}

glm::vec2 ImGuiDisplay::GetTextSize(const char* pBegin, const char* pEnd) const
{
    return toVec2(ImGui::CalcTextSize((const char*)pBegin, (const char*)pEnd));
}

void ImGuiDisplay::DrawChars(const glm::vec2& pos, uint32_t col, const char* text_begin, const char* text_end) const
{
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    if (text_end == nullptr)
    {
        text_end = text_begin + strlen((const char*)text_begin);
    }
    drawList->AddText(toImVec2(pos), col, (const char*)text_begin, (const char*)text_end);
}

void ImGuiDisplay::DrawLine(const glm::vec2& start, const glm::vec2& end, uint32_t color, float width) const
{
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    // Background rect for numbers
    drawList->AddLine(toImVec2(start), toImVec2(end), color, width);
}

void ImGuiDisplay::DrawRectFilled(const glm::vec2& a, const glm::vec2& b, uint32_t color) const
{
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    // Background rect for numbers
    drawList->AddRectFilled(toImVec2(a), toImVec2(b), color);
}


} // StarterKit
