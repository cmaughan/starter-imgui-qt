#pragma once

#if !(TARGET_MAC)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <file/mfilesystem.h>
namespace fs = mfilesystem;
#endif

namespace FileUtils
{
std::string ReadFile(const fs::path& fileName);
bool WriteFile(const fs::path& fileName, const void* pData, size_t size);
fs::path RelativeTo(fs::path from, fs::path to);
fs::path GetDocumentsPath();
std::vector<fs::path> GatherFiles(const fs::path& root, bool includeChildren = true);
}

