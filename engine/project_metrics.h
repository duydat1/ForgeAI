
#pragma once

// Cấu trúc lưu các thông tin tổng hợp của toàn bộ project.
struct ProjectMetrics {
    // Tổng số source file.
    int sourceFileCount = 0;

    // Tổng số dòng của project.
    int totalLines = 0; 

    // Tổng số dòng trống.
    int blankLines = 0;

    // Tổng số dòng comment.
    int commentLines = 0;

    // Tính tổng số dòng thực sự là code của project.
    int codeLines() const {
        return totalLines - blankLines - commentLines;
    }
};