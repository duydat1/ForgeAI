
#pragma once
#include <string>
// Cấu trúc lưu các thông tin mà ForgeAI phân tích được từ một file.
struct FileMetrics {

    // Đường dẫn của file được phân tích.
    std::string filePath; 

    // Tổng số dòng trong file.
    int totalLines = 0;

    // Số dòng trống trong file.
    int blankLines = 0;

    // Số dòng comment trong file.
    int commentLines = 0;

    // Tính số dòng thực sự là code.
    int codeLines() const {
        return totalLines - blankLines - commentLines;
    }
};