
#include <fstream>
#include <iostream>
#include <string>

#include "file_analyzer.h"


using std ::cout;

FileMetrics analyzeFile(const std::filesystem::path& filePath) { // đổi từ void sang FileMetrics để trả về các metrics của file.
    std::ifstream file(filePath); // Mở file để đọc.
    if (!file.is_open()) {
        cout << "Cannot open: " << filePath << '\n';
        return {}; // Trả về một FileMetrics rỗng nếu không thể mở file.
    }
    FileMetrics metrics; // Tạo object để lưu toàn bộ metrics của file hiện tại.
    metrics.filePath = filePath.string(); // Lưu đường dẫn file vào metrics để sau này biết dữ liệu thuộc file nào.
    // filePath là std::filesystem::path, cần chuyển sang std::string để lưu vào metrics.filePath (chuyển đường dẫn thành chuỗi)

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



















































