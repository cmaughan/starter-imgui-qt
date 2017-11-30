#include "mcommon.h"
#include "stringutils.h"
#include <algorithm>
#include <codecvt>
#include <locale>

namespace StringUtils
{

std::string toLower(const std::string& str)
{
    std::string copy = str;
    std::transform(copy.begin(),copy.end(),copy.begin(),::tolower);
    return copy;
}

std::string ReplaceString(std::string subject, const std::string& search,
    const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

// String split with multiple delims
// https://stackoverflow.com/a/7408245/18942
std::vector<std::string> Split(const std::string& text, const std::string& delims)
{
    std::vector<std::string> tokens;
    std::size_t start = text.find_first_not_of(delims), end = 0;

    while ((end = text.find_first_of(delims, start)) != std::string::npos)
    {
        tokens.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(delims, end);
    }
    if (start != std::string::npos)
        tokens.push_back(text.substr(start));

    return tokens;
}

std::vector<std::string> SplitLines(const std::string& text)
{
    return Split(text, "\r\n");
}

//https://stackoverflow.com/questions/4804298/how-to-convert-wstring-into-string
std::string makeStr(const std::wstring& str)
{
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    //use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
    std::string converted_str = converter.to_bytes(str);
    return converted_str;
}

}