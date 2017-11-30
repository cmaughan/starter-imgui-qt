#pragma once

namespace StarterKit
{

class Display
{
public:
    virtual glm::vec2 GetTextSize(const char* pBegin, const char* pEnd = nullptr) const = 0;
    virtual float GetFontSize() const = 0;
    virtual void DrawLine(const glm::vec2& start, const glm::vec2& end, uint32_t color = 0xFFFFFFFF, float width = 1.0f) const = 0;
    virtual void DrawChars(const glm::vec2& pos, uint32_t col, const char* text_begin, const char* text_end = nullptr) const = 0;
    virtual void DrawRectFilled(const glm::vec2& a, const glm::vec2& b, uint32_t col = 0xFFFFFFFF) const = 0;
};

} // StarterKit
