#include <iostream>
#include <filesystem>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>


namespace fs = std::filesystem;

/**
 * @brief 将字符串转换为时间戳
 *
 * @param timestamp_str 字符时间戳
 * @param timestamp_format 时间戳格式
 *
 * @return int 类型时间戳
 */
std::time_t convert_str_to_timet(
    const std::string &timestamp_str,
    const std::string &timestamp_format = "%Y-%m-%d %H:%M:%S"
) {
	try {
		if (timestamp_str.length() < 17) return -1;
		std::tm timestamp = {};
		std::istringstream ss(timestamp_str);
		ss >> std::get_time(&timestamp, timestamp_format.c_str());
		if (ss.fail()) return -1;
		return std::mktime(&timestamp);
	} catch (const std::exception &e) {
		return -1;
	}

}


/**
 * @brief 判断时间是不是超过 n 个小时
 *
 * @param timestamp int 时间戳
 * @param hours 超过 n 个小时
 *
 * @return 是否超过时间
 */
bool is_exceed_n_hours(
    const std::time_t &timestamp,
    const int hours = 36
) {
	if (timestamp <= 0) return false;

	std::time_t now = std::time(0);
	double diff_sec = std::difftime(now, timestamp);
	double diff_hours = diff_sec / 3600.0;
	return diff_hours > hours;
}


bool is_directory(const std::string &path) {
	return fs::exists(path) && fs::is_directory(path);
}


bool is_file(const std::string &path) {

	return fs::exists(path) && fs::is_regular_file(path);
}


/**
 * @brief 遍历删除文件，根据文件名和后缀和超时时间决定，删除超时的指定格式的文件，文件名为 `2025-05-13 15-36-45.png` 格式
 *
 * @param path 遍历路径
 * @param delete_ext 文件后缀名
 * @param timestamp_format 时间戳格式
 * @param exceed_n_hours 超时时间
 * @param stem_cut_start 截取文件名开始位置
 * @param stem_cut_len 截取文件名长度
 */
void traverse_delete_files_by_exceed_hours(
    const std::string &path,
    const std::string &delete_ext = "",
    const std::string &timestamp_format = "%Y-%m-%d %H-%M-%S",
    int exceed_n_hours = 36,
    int stem_cut_start = 0,
    int stem_cut_len = 19) {
	if (!is_directory(path))
		return;

	// 遍历一层 directory_iterator
	// 递归遍历 recursive_directory_iterator
	for (const auto &entry : fs::directory_iterator(path)) {
		try {
			auto path = entry.path();
			std::string full_path = path.string();

			// 不是文件就忽略
			if (!is_file(full_path))
				continue;

			std::string filename = path.filename().string();
			// 2025-05-13 15-36-45.png

			size_t dot_pos = filename.rfind('.');
			// 没有扩展名就忽略
			if (dot_pos == std::string::npos)
				continue;

			std::string stem = filename.substr(0, dot_pos);
			int _stem_cut_len = stem.size() - stem_cut_start;
			// 2025-05-13 15-36-45 ...
			if (_stem_cut_len < stem_cut_len)
				continue;
			std::string sub_stem = stem.substr(stem_cut_start, stem_cut_len);
			// 2025-05-13 15-36-45
			std::string ext = filename.substr(dot_pos); // 包含点
			// .png

			// 如果不是指定格式就忽略
			if ((delete_ext != "") && !(ext == delete_ext))
				continue;

			std::time_t timestamp = convert_str_to_timet(sub_stem, timestamp_format);
			bool is_exceeded = is_exceed_n_hours(timestamp, exceed_n_hours);
			if (is_exceeded)
				fs::remove_all(path);
		} catch (const std::exception &e) {
			std::cerr << "traverse_delete_files_by_exceed_hours error: " << e.what() << std::endl;
		}
	}
}

/**
 * @brief 遍历删除文件夹，根据文件名和超时时间决定，删除超时的文件夹，文件夹名为 `2025-05-13 15-36-45` 格式
 *
 * @param path 遍历路径
 * @param timestamp_format 时间戳格式
 * @param exceed_n_hours 超时时间
 * @param stem_cut_start 截取文件名开始位置
 * @param stem_cut_len 截取文件名长度
 */
void traverse_delete_dirs_by_exceed_hours(
    const std::string &path,
    const std::string &timestamp_format = "%Y-%m-%d %H-%M-%S",
    int exceed_n_hours = 36,
    int stem_cut_start = 0,
    int stem_cut_len = 19) {
	if (!is_directory(path))
		return;

	// 遍历一层 directory_iterator
	// 递归遍历 recursive_directory_iterator
	for (const auto &entry : fs::directory_iterator(path)) {
		try {
			auto path = entry.path();
			std::string full_path = path.string();

			// 不是文件夹就忽略
			if (!is_directory(full_path))
				continue;

			std::string filename = path.filename().string();
			// 2025-05-13 15-36-45 ...
			int _stem_cut_len = filename.size() - stem_cut_start;
			if (_stem_cut_len < stem_cut_len)
				continue;
			std::string sub_stem = filename.substr(stem_cut_start, stem_cut_len);
			// 2025-05-13 15-36-45

			std::time_t timestamp = convert_str_to_timet(sub_stem, timestamp_format);
			bool is_exceeded = is_exceed_n_hours(timestamp, exceed_n_hours);
			if (is_exceeded)
				fs::remove_all(path);
		} catch (const std::exception &e) {
			std::cerr << "traverse_delete_dirs_by_exceed_hours error: " << e.what() << std::endl;
		}
	}
}


int main() {
	std::string path = "C:\\Users\\algorithm2\\Downloads\\check_images";
	traverse_delete_files_by_exceed_hours(path, ".png");
	traverse_delete_dirs_by_exceed_hours(path);
	return 0;
}
