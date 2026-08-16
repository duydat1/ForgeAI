#include <iostream>
#include <string>



void analyze(const std::string& projectPath);

int main(int argc, char* argv[]) {
    std::cout << "ForgeAI\n";
    std::cout << "=======\n\n";

    if (argc < 2) {
        std::cout << "Usage: forgeai <project_path>\n";
        return 1;
    }

    std::cout << "Target:\n";
    std::cout << argv[1] << "\n\n"; // argv[1] chính là đường dẫn nhập vào.



    analyze(argv[1]);

    return 0;
}