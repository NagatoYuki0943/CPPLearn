#include <iostream>
#include <filesystem>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
#include <codecvt>


namespace fs = std::filesystem;


std::wstring to_wide_string(const std::string& input) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(input);
}


bool is_directory(const std::string &path) {
	return fs::exists(path) && fs::is_directory(path);
}


bool is_file(const std::string &path) {
	
	return fs::exists(path) && fs::is_regular_file(path);
}


/**
 * @brief 遍历删除文件，根据文件名和后缀决定，删除指定格式的文件
 *
 * @param path 遍历路径
 * @param delete_ext 文件后缀名
 */
void traverse_delete_files(
	const std::string &path,
	const std::string &delete_ext = ""
	) {
		std::wstring path_w = to_wide_string(path);
		// 遍历一层 directory_iterator
		// 递归遍历 recursive_directory_iterator
		for (const auto& entry : fs::directory_iterator(path_w)) {
			auto path = entry.path();
			std::string full_path = path.string();
			
			// 不是文件就忽略
			if (!is_file(full_path))
				continue;
			
			std::string filename = path.filename().string();
			std::cout << filename << std::endl;
			// 2025-05-13 15-36-45.png
			
			size_t dot_pos = filename.rfind('.');
			// 没有扩展名就忽略
			if (dot_pos == std::string::npos)
				continue;
			
			std::string base = filename.substr(0, dot_pos);
			std::cout << base << std::endl;
			// 2025-05-13 15-36-45
			std::string ext = filename.substr(dot_pos); // 包含点
			std::cout << ext << std::endl;
			// .png
			
			// 如果不是指定格式就忽略
			if ((delete_ext != "") && !(ext == delete_ext))
				continue;
			
			// fs::remove(); // 只能删除文件和空目录
			fs::remove_all(path); // 可以删除文件和目录及其全部内容
		}
	}


/**
 * @brief 遍历删除文件夹
 *
 * @param path 遍历路径
 */
void traverse_delete_dirs(
	const std::string &path
	) {
		std::wstring path_w = to_wide_string(path);
		// 遍历一层 directory_iterator
		// 递归遍历 recursive_directory_iterator
		for (const auto& entry : fs::directory_iterator(path_w)) {
			auto path = entry.path();
			std::string full_path = path.string();
			
			// 不是文件夹就忽略
			if (!is_directory(full_path))
				continue;
			
			std::string filename = path.filename().string();
			std::cout << filename << std::endl;
			// 2025-05-13 15-36-45

			// fs::remove(); // 只能删除文件和空目录
			fs::remove_all(path); // 可以删除文件和目录及其全部内容
		}
	}


int main() {
	std::string path = "C:\\Users\\algorithm2\\Downloads\\check_images";
	traverse_delete_files(path, ".png");
	traverse_delete_dirs(path);
	return 0;
}
