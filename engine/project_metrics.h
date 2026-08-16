
#pragma once

// Cấu trúc lưu các thông tin tổng hợp của toàn bộ project.
struct ProjectMetrics {
    // Tổng số source file được tìm thấy.
    int sourceFileCount = 0;

    // Tổng số dòng của tất cả source file.
    int totalLines = 0;

    // Tổng số dòng trống.
    int blankLines = 0;

    // Tổng số dòng comment.
    int commentLines = 0;
};