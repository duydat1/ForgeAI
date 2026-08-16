
#include <iostream>
#include <filesystem>
#include <string>

#include "file_analyzer.h"
#include "project_metrics.h"


using std ::cout;

void analyze(const std::string& projectPath) {
    cout << "Scanning project...\n\n"; // In thông báo cho biết ForgeAI bắt đầu quét project.
    ProjectMetrics projectMetrics; // Biến này dùng để lưu các metrics tổng hợp của project.
    
    for (const auto& entry :  // Duyệt qua projectPath và tất cả các thư mục con bên trong nó.
        std::filesystem::recursive_directory_iterator(projectPath)) {

        if (entry.is_regular_file()) { // Kiểm tra phần tử hiện tại có phải là một file hay không.
            std::string extension = entry.path().extension().string(); // Lấy phần mở rộng của file, ví dụ ".cpp", ".h", ".hpp".

            if (extension == ".cpp" || extension == ".h" || extension == ".hpp") {
                cout << entry.path() << '\n'; // In tên file đang được phân tích.
                FileMetrics metrics = analyzeFile(entry.path());

                // In thông tin của file hiện tại.
                cout << "  Total lines:   " << metrics.totalLines << '\n';
                cout << "  Blank lines:   " << metrics.blankLines << '\n';
                cout << "  Comment lines: " << metrics.commentLines << '\n';

                projectMetrics.sourceFileCount++; // Có thêm một source file vào tổng số file của project.
                projectMetrics.totalLines += metrics.totalLines; // Cộng số dòng của file hiện tại vào tổng số dòng của project.
                projectMetrics.blankLines += metrics.blankLines; // Cộng số dòng trống của file hiện tại vào tổng số dòng trống của project.
                projectMetrics.commentLines += metrics.commentLines; // Cộng số dòng comment của file hiện tại vào tổng số dòng comment của project.
            }
        }
    }
    cout << "\nProject Statistics\n";
    cout << "------------------\n";

    // In tổng số source file.
    cout << "Source files:   " << projectMetrics.sourceFileCount << '\n';

    // In tổng số dòng của project.
    cout << "Total lines:    " << projectMetrics.totalLines << '\n';

    // In tổng số dòng trống.
    cout << "Blank lines:    " << projectMetrics.blankLines << '\n';

    // In tổng số dòng comment.
    cout << "Comment lines:  " << projectMetrics.commentLines << '\n';
}