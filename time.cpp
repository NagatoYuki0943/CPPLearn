#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

void test1() {
    std::cout << "********** test1 **********" << std::endl;

    // 获取当前格林尼治时间戳（秒）
    std::time_t t1 = std::time(0);
    std::cout << t1 << " seconds since 01-Jan-1970 (UTC)" << std::endl;

    // 可以使用 int 类型保存
    int t2 = std::time(0);
    std::cout << t2 << " seconds since 01-Jan-1970 (UTC)" << std::endl;

    // 转换为东八区时间
    int t3 = t2 + 28800;
    std::cout << t3 << " seconds since 01-Jan-1970 (UTC+8)" << std::endl;

    std::cout << "********** test1 **********\n"
              << std::endl;
}

void test2() {
    std::cout << "********** test2 **********" << std::endl;

    // 返回当前时间
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    auto ms1 = std::chrono::duration_cast<std::chrono::seconds>(t1.time_since_epoch());
    std::cout << ms1.count() << " seconds since 01-Jan-1970" << std::endl; // 输秒级时间戳

    auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t1.time_since_epoch());
    std::cout << ms2.count() << " milliseconds since 01-Jan-1970" << std::endl; // 输出毫秒级时间戳

    auto ms3 = std::chrono::duration_cast<std::chrono::microseconds>(t1.time_since_epoch());
    std::cout << ms3.count() << " microseconds since 01-Jan-1970" << std::endl; // 输出微秒级时间戳

    auto ms4 = std::chrono::duration_cast<std::chrono::nanoseconds>(t1.time_since_epoch());
    std::cout << ms4.count() << " nanoseconds since 01-Jan-1970" << std::endl; // 输出纳秒级时间戳

    auto ms5 = std::chrono::duration_cast<std::chrono::minutes>(t1.time_since_epoch());
    std::cout << ms5.count() << " minutes since 01-Jan-1970" << std::endl; // 输出分钟级时间戳

    auto ms6 = std::chrono::duration_cast<std::chrono::hours>(t1.time_since_epoch());
    std::cout << ms6.count() << " hours since 01-Jan-1970" << std::endl; // 输出小时级时间戳

    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms7 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
    std::cout << "interval = " << ms7.count() << " nanoseconds" << std::endl;

    std::cout << "********** test2 **********\n"
              << std::endl;
}

/**
 * @brief 获取当前时间，返回 std::tm 结构
 *
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return std::tm
 */
std::tm get_now_time_tm(const bool use_normal_tm = true) {
    auto now = std::chrono::system_clock::now();
    // 转换为秒数时间戳
    auto t = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&t);
	if (use_normal_tm){
		local_tm.tm_year += 1900;
		local_tm.tm_mon += 1;
	}
    return local_tm;
}

/**
 * @brief 获取当前时间戳字符串
 *
 * @param format 时间戳格式
 *
 * @return 时间戳字符串
 */
std::string get_now_timestamp_str(const std::string &format = "%Y-%m-%d %H:%M:%S") {
    auto now = std::chrono::system_clock::now();
    // 转换为秒数时间戳
    auto t = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm = *std::localtime(&t);

    std::stringstream ss;
    ss << std::put_time(&local_tm, format.c_str());
    return ss.str();
}

void test3() {
    std::cout << "********** test3 **********" << std::endl;

    auto now = get_now_time_tm();
    std::cout << "now: " << now.tm_year << "-" << now.tm_mon << "-" << now.tm_mday << " " << now.tm_hour << ":" << now.tm_min << ":" << now.tm_sec << std::endl;
    // now: 2025-9-22 9:31:43
    std::cout << "now: " << get_now_timestamp_str() << std::endl;
    // now: 2025-09-22 09:31:43

    std::cout << "********** test3 **********\n"
              << std::endl;
}

/**
 * @brief 将 C-style time_t 转换为 std::chrono::system_clock::time_point
 *
 * @param t C-style time_t
 *
 * @return std::chrono::system_clock::time_point
 */
std::chrono::system_clock::time_point time_t_to_time_point(
    const std::time_t t = std::time(0)) {
    // Convert the time_t to a std::chrono::system_clock::time_point
    return std::chrono::system_clock::from_time_t(t);
}

/**
 * @brief 将 C-style time_t 转换为 std::tm
 *
 * @param t C-style time_t
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return std::tm
 */
std::tm time_t_to_tm(
    const std::time_t t = std::time(0),
    const bool use_normal_tm = true) {
    std::tm tm = *std::localtime(&t);
    if (use_normal_tm) {
        // Your original adjustments to make the year and month more intuitive
        tm.tm_year += 1900;
        tm.tm_mon += 1;
    }
    return tm;
}

/**
 * @brief 将 std::chrono::system_clock::time_point 转换为 C-style time_t
 *
 * @param time_point std::chrono::system_clock::time_point
 *
 * @return C-style time_t
 */
std::time_t time_point_to_time_t(
    const std::chrono::system_clock::time_point &time_point = std::chrono::system_clock::now()) {
    // 转换为秒数时间戳
    std::time_t t = std::chrono::system_clock::to_time_t(time_point);
    return t;
}

/**
 * @brief 将 std::chrono::system_clock::time_point 转换为 std::tm
 *
 * @param time_point std::chrono::system_clock::time_point
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return std::tm
 */
std::tm time_point_to_tm(
    const std::chrono::system_clock::time_point &time_point = std::chrono::system_clock::now(),
    const bool use_normal_tm = true) {
    // Convert the time_point to a C-style time_t
    std::time_t t = time_point_to_time_t(time_point);

    // Convert to a local std::tm struct.
    // Note: std::localtime is not thread-safe.
    std::tm tm = time_t_to_tm(t, use_normal_tm);

    return tm;
}

/**
 * @brief 将 std::tm 转换为 C-style time_t
 *
 * @param tm_in std::tm
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return C-style time_t
 */
std::time_t tm_to_time_t(
    const std::tm &tm_in,
    const bool use_normal_tm = true) {

    // Create a mutable copy because mktime can modify the struct
    std::tm temp_tm = tm_in;

    if (use_normal_tm) {
        // Adjust from intuitive format back to the C-style format required by mktime
        // (years since 1900, and month since January 0-11)
        temp_tm.tm_year -= 1900;
        temp_tm.tm_mon -= 1;
    }

    // Convert the std::tm struct to a C-style time_t
    std::time_t t = std::mktime(&temp_tm);
    return t;
}

/**
 * @brief 将 std::tm 转换为 std::chrono::system_clock::time_point
 *
 * @param tm_in std::tm
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return std::chrono::system_clock::time_point
 */
std::chrono::system_clock::time_point tm_to_time_point(
    const std::tm &tm_in,
    const bool use_normal_tm = true) {
    // Convert the std::tm struct to a C-style time_t
    std::time_t t = tm_to_time_t(tm_in, use_normal_tm);

    // Convert the time_t to a std::chrono::system_clock::time_point
    auto time_point = time_t_to_time_point(t);
    return time_point;
}

/**
 * @brief 将 std::chrono::system_clock::time_point 转换为时间戳字符串
 *
 * @param time_point std::chrono::system_clock::time_point
 * @param format 时间戳格式
 *
 * @return 时间戳字符串
 */
std::string time_point_to_timestamp_str(
    const std::chrono::system_clock::time_point &time_point = std::chrono::system_clock::now(),
    const std::string &format = "%Y-%m-%d %H:%M:%S") {
    // 转换为秒数时间戳
    std::time_t t = time_point_to_time_t(time_point);
    // 不同调整时间格式, 因为它为中间值, 所以不用调整
    std::tm temp_tm = time_t_to_tm(t, false);

    std::stringstream ss;
    ss << std::put_time(&temp_tm, format.c_str());
    return ss.str();
}

/**
 * @brief 将 std::tm 转换为时间戳字符串
 *
 * @param tm_in std::tm
 * @param format 时间戳格式
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return 时间戳字符串
 */
std::string tm_to_timestamp_str(
    const std::tm tm_in,
    const std::string &format = "%Y-%m-%d %H:%M:%S",
    const bool use_normal_tm = true) {
    // Create a mutable copy because mktime can modify the struct
    std::tm temp_tm = tm_in;

    if (use_normal_tm) {
        // Adjust from intuitive format back to the C-style format required by mktime
        // (years since 1900, and month since January 0-11)
        temp_tm.tm_year -= 1900;
        temp_tm.tm_mon -= 1;
    }

    std::stringstream ss;
    ss << std::put_time(&temp_tm, format.c_str());
    return ss.str();
}

/**
 * @brief 将 C-style time_t 转换为时间戳字符串
 *
 * @param t C-style time_t
 * @param format 时间戳格式
 *
 * @return 时间戳字符串
 */
std::string time_t_to_timestamp_str(
    const std::time_t t = std::time(0),
    const std::string &format = "%Y-%m-%d %H:%M:%S") {
    // use_normal_tm 都为 false, 2次会相互抵消
    std::tm tm = time_t_to_tm(t, false);
    std::string timestamp_str = tm_to_timestamp_str(tm, format, false);
    return timestamp_str;
}

/**
 * @brief 将时间戳字符串转换为 std::tm
 *
 * @param timestamp_str 时间戳字符串
 * @param timestamp_format 时间戳格式
 * @param use_normal_tm 是否使用正常格式时间，比如年为 2025，月份从 1 开始
 *
 * @return std::tm
 */
std::tm timestamp_str_to_tm(
    const std::string &timestamp_str,
    const std::string &timestamp_format = "%Y-%m-%d %H:%M:%S",
    const bool use_normal_tm = true) {
    if (timestamp_str.length() < 17)
        return {};

    std::tm tm = {};
    std::istringstream ss(timestamp_str);
    ss >> std::get_time(&tm, timestamp_format.c_str());

    if (ss.fail())
        return {};

    if (use_normal_tm) {
        // Adjust from C-style format required by mktime (years since 1900, and month since January 0-11)
        // to intuitive format (years since 1970, and month since January 1-12)
        tm.tm_year += 1900;
        tm.tm_mon += 1;
    }

    // tm.tm_isdst = -1; // Let mktime determine DST, important for accuracy
    return tm;
}

/**
 * @brief 将时间戳字符串转换为 std::chrono::system_clock::time_point
 *
 * @param timestamp_str 时间戳字符串
 * @param timestamp_format 时间戳格式
 *
 * @return std::chrono::system_clock::time_point
 */
std::chrono::system_clock::time_point timestamp_str_to_time_point(
    const std::string &timestamp_str,
    const std::string &timestamp_format = "%Y-%m-%d %H:%M:%S") {
    if (timestamp_str.length() < 17)
        return std::chrono::system_clock::time_point();
    // use_normal_tm 都为 false, 2次会相互抵消
    std::tm tm = timestamp_str_to_tm(timestamp_str, timestamp_format, false);
    auto time_point = tm_to_time_point(tm, false);
    return time_point;
}

/**
 * @brief 将时间戳字符串转换为 C-style time_t
 *
 * @param timestamp_str 时间戳字符串
 * @param timestamp_format 时间戳格式
 *
 * @return C-style time_t
 */
std::time_t timestamp_str_to_time_t(
    const std::string &timestamp_str,
    const std::string &timestamp_format = "%Y-%m-%d %H:%M:%S") {
    try {
        if (timestamp_str.length() < 17)
            return -1;
        // use_normal_tm 都为 false, 2次会相互抵消
        std::tm tm = timestamp_str_to_tm(timestamp_str, timestamp_format, false);
        std::time_t t = tm_to_time_t(tm, false);
        return t;
    } catch (const std::exception &e) {
        return -1;
    }
}

void test4() {
    std::cout << "********** test4 **********" << std::endl;

    auto now = std::chrono::system_clock::now();
    std::string timestamp_str = time_point_to_timestamp_str(now);
    std::cout << timestamp_str << std::endl;

    auto t = time_point_to_time_t(now);
    std::cout << t << std::endl;
    timestamp_str = time_t_to_timestamp_str(t);
    std::cout << timestamp_str << std::endl;

    auto tm = time_point_to_tm(now);
    timestamp_str = tm_to_timestamp_str(tm);
    std::cout << timestamp_str << std::endl;

    now = time_t_to_time_point(t);
    timestamp_str = time_point_to_timestamp_str(now);
    std::cout << timestamp_str << std::endl;

    tm = time_t_to_tm(t);
    timestamp_str = tm_to_timestamp_str(tm);
    std::cout << timestamp_str << std::endl;

    t = tm_to_time_t(tm);
    std::cout << t << std::endl;
    timestamp_str = time_t_to_timestamp_str(t);
    std::cout << timestamp_str << std::endl;

    now = tm_to_time_point(tm);
    timestamp_str = time_point_to_timestamp_str(now);
    std::cout << timestamp_str << std::endl;

    tm = timestamp_str_to_tm(timestamp_str);
    timestamp_str = tm_to_timestamp_str(tm);
    std::cout << timestamp_str << std::endl;

    now = timestamp_str_to_time_point(timestamp_str);
    timestamp_str = time_point_to_timestamp_str(now);
    std::cout << timestamp_str << std::endl;

    t = timestamp_str_to_time_t(timestamp_str);
    std::cout << t << std::endl;
    timestamp_str = time_t_to_timestamp_str(t);
    std::cout << timestamp_str << std::endl;

    std::cout << "********** test4 *********\n"
              << std::endl;
}


std::tm make_tm(int year, int month, int day, int hour, int minute, int second) {
    std::tm tm = {};
    tm.tm_year = year - 1900; // Year since 1900
    tm.tm_mon = month - 1;	  // Month since January (0-11)
    tm.tm_mday = day;		  // Day of the month
    tm.tm_hour = hour;		  // Hour
    tm.tm_min = minute;		  // Minute
    tm.tm_sec = second;		  // Second
    tm.tm_isdst = -1;		  // Let mktime determine DST
    return tm;
}


void test5() {
    std::cout << "********** test5 **********" << std::endl;

    // 1. Define the time components in a std::tm struct
    std::tm tm = make_tm(2025, 9, 22, 10, 30, 0);

    std::string timestamp_str = tm_to_timestamp_str(tm);
    std::cout << timestamp_str << std::endl;
    std::cout << "********** test5 **********\n"
              << std::endl;
}


int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
