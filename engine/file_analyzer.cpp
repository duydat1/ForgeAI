#include "file_analyzer.h"

#include <fstream>
#include <iostream>
#include <string>


void analyzeFile(const std::filesystem::path& filePath) {
    std::ifstream file(filePath); // Mở file để đọc.
    if (!file.is_open()) { // Kiểm tra xem file có mở thành công hay không.
        std::cout << "Cannot open: " << filePath << '\n';
        return;
    }
    int totalLines = 0; // Biến lưu tổng số dòng của file.
    int blankLines = 0; // Biến lưu số dòng trống.
    int commentLines = 0; // Biến lưu số dòng comment.
    std::string line; // Biến tạm dùng để lưu từng dòng được đọc.
    while (std::getline(file, line)) { // Đọc file từng dòng cho đến khi hết file.
        totalLines++; // Mỗi lần đọc được một dòng thì tăng tổng số dòng lên 1.
        bool isBlank = true; // Tạm thời coi dòng hiện tại là dòng trống.
        for (char character : line) { // Kiểm tra từng ký tự trong dòng.
            if (character != ' ' && character != '\t') { // Nếu gặp ký tự khác space hoặc tab thì đây ko còn là dòng trống.
                isBlank = false;
                break;
            }
        }

        if (isBlank)  blankLines++; // Nếu toàn bộ dòng chỉ chứa space/tab thì tăng blankLines.
        std::size_t firstCharacter = line.find_first_not_of(" \t"); // Tạm thời bỏ qua các khoảng trắng đầu dòng.
        
        if (firstCharacter != std::string::npos && // Nếu dòng bắt đầu bằng "//" thì coi là comment.
            line.substr(firstCharacter, 2) == "//") {
            commentLines++;
        }
    }

    file.close(); // Đóng file sau khi đọc xong.

    // In thống kê của file.
    std::cout << "  Total lines:   " << totalLines << '\n';
    std::cout << "  Blank lines:   " << blankLines << '\n';
    std::cout << "  Comment lines: " << commentLines << '\n';
}



















































