#pragma once

// Cấu trúc lưu các thông tin mà ForgeAI phân tích được từ một file.
struct FileMetrics {
    // Tổng số dòng trong file.
    int totalLines = 0;

    // Số dòng trống trong file.
    int blankLines = 0;

    // Số dòng comment trong file.
    int commentLines = 0;
};