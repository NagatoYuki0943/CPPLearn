#include <iostream>
#include <filesystem>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
#include <codecvt>


namespace fs = std::filesystem;

std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

std::wstring to_wide_string(const std::string& input) {
    return converter.from_bytes(input);
}


bool is_directory(const std::string &path) {
    return fs::exists(path) && fs::is_directory(path);
}


bool is_file(const std::string &path) {
    return fs::exists(path) && fs::is_regular_file(path);
}


/**
 * @brief 遍历目录
 */
void traverse_dir(
    const std::string &path
    ) {
        if (!is_directory(path))
            return;

        std::wstring path_w = to_wide_string(path);
        // 遍历一层 directory_iterator
        // 递归遍历 recursive_directory_iterator
        for (const auto& entry : fs::directory_iterator(path_w)) {
            auto path = entry.path();
            std::string full_path = path.string();

            std::string filename = path.filename().string();
            std::cout << "filename: " << filename << std::endl;
            // 2025-05-13 15-36-45.png

            if (entry.is_regular_file())
                std::cout << filename << " is a regular file" << std::endl;
            else if (entry.is_directory()) {
                std::cout << filename << " is a directory" << std::endl;
            }
            else {
                std::cout << filename << " is not a regular file or directory" << std::endl;
            }

            std::string stem = path.stem().string();
            std::cout << "stem: " << stem << std::endl;
            // 2025-05-13 15-36-45

            std::string ext = path.extension().string();
            std::cout << "ext: " << ext << std::endl;
            // .png

            // fs::remove(); // 只能删除文件和空目录
            // fs::remove_all(path); // 可以删除文件和目录及其全部内容
            std::cout << std::endl;
        }
    }


int main() {
    std::string path = "C:\\Users\\algorithm2\\Downloads\\check_images";
    traverse_dir(path);
    return 0;
}
