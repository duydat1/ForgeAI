#pragma once

#include <filesystem>

#include "file_metrics.h" 

// Phân tích file và trả về các metrics của file đó.
FileMetrics analyzeFile(const std::filesystem::path& filePath);