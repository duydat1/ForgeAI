#include "file_analyzer.h"

#include <fstream>
#include <iostream>
#include <string>

using std ::cout;

FileMetrics analyzeFile(const std::filesystem::path& filePath) { // đổi từ void sang FileMetrics để trả về các metrics của file.
    std::ifstream file(filePath); // Mở file để đọc.
    if (!file.is_open()) {
        cout << "Cannot open: " << filePath << '\n';
        return {}; // Trả về một FileMetrics rỗng nếu không thể mở file.
    }

    //// int totalLines = 0; // Biến lưu tổng số dòng của file.
    //// int blankLines = 0; // Biến lưu số dòng trống.
    //// int commentLines = 0; // Biến lưu số dòng comment.
    
    FileMetrics metrics; // đổi lưu 3 biến thành struct FileMetrics để lưu các thông tin metrics của file.
    std::string line; // Biến tạm dùng để lưu từng dòng được đọc.
    while (std::getline(file, line)) { // Đọc file từng dòng cho đến khi hết file.
        metrics.totalLines++; // Mỗi lần đọc được một dòng thì tăng tổng số dòng lên 1.
        bool isBlank = true; // Tạm thời coi dòng hiện tại là dòng trống.
        for (char character : line) { // Kiểm tra từng ký tự trong dòng.
            if (character != ' ' && character != '\t') { // Nếu gặp ký tự khác space hoặc tab thì đây ko còn là dòng trống.
                isBlank = false;
                break;
            }
        }

        if (isBlank)  metrics.blankLines++; // Nếu toàn bộ dòng chỉ chứa space/tab thì tăng blankLines.
        std::size_t firstCharacter = line.find_first_not_of(" \t"); // Tạm thời bỏ qua các khoảng trắng đầu dòng.
        
        if (firstCharacter != std::string::npos && // Nếu dòng bắt đầu bằng "//" thì coi là comment.
            line.substr(firstCharacter, 2) == "//") {
            metrics.commentLines++;
        }
    }

    file.close(); // Đóng file sau khi đọc xong.

    return metrics; // Trả về các metrics của file.
}



















































