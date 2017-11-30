#pragma once
#include <string>
#include "display.h"
#include <imgui.h>

namespace StarterKit
{

inline glm::vec2 toVec2(const ImVec2& im) { return glm::vec2(im.x, im.y); }
inline ImVec2 toImVec2(const glm::vec2& im) { return ImVec2(im.x, im.y); }

class ImGuiDisplay : public Display
{
public:
    ImGuiDisplay();
    ~ImGuiDisplay();

    virtual glm::vec2 GetTextSize(const char* pBegin, const char* pEnd = nullptr) const override;
    virtual float GetFontSize() const override;
    virtual void DrawLine(const glm::vec2& start, const glm::vec2& end, uint32_t color = 0xFFFFFFFF, float width = 1.0f) const override;
    virtual void DrawChars(const glm::vec2& pos, uint32_t col, const char* text_begin, const char* text_end = nullptr) const override;
    virtual void DrawRectFilled(const glm::vec2& a, const glm::vec2& b, uint32_t col = 0xFFFFFFFF) const override;
private:
};

} // StarterKit
