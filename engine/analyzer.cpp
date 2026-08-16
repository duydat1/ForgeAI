#include <iostream>
#include <filesystem>
#include <string>

#include "file_analyzer.h"

void analyze(const std::string& projectPath) {
    std::cout << "Scanning project...\n\n"; // In thông báo cho biết ForgeAI bắt đầu quét project.
    int sourceFileCount = 0; // Biến này dùng để đếm tổng số file C++ mà ForgeAI tìm thấy.
    
    for (const auto& entry :  // Duyệt qua projectPath và tất cả các thư mục con bên trong nó.
        std::filesystem::recursive_directory_iterator(projectPath)) {

        if (entry.is_regular_file()) { // Kiểm tra phần tử hiện tại có phải là một file hay không.
            std::string extension = entry.path().extension().string(); // Lấy phần mở rộng của file, ví dụ ".cpp", ".h", ".hpp".

            if (extension == ".cpp" || extension == ".h" || extension == ".hpp") {
                std::cout << entry.path() << '\n'; // In tên file đang được phân tích.
                analyzeFile(entry.path()); // Phân tích nội dung của file hiện tại.
                sourceFileCount++; // Tăng số lượng source file lên 1.
            }
        }
    }

    // In tổng số source file sau khi quét xong.
    std::cout << "\nTotal C++ source files: " << sourceFileCount << '\n';
}