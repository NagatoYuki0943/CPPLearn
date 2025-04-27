#include <ctime>
#include <chrono>
#include <iostream>

int main() {
	std::time_t t1 = std::time(0); // 获取当前时间戳（秒）
	std::cout << t1 << " seconds since 01-Jan-1970" << std::endl;
	
	auto t2 = std::chrono::high_resolution_clock::now();

	auto ms1 = std::chrono::duration_cast<std::chrono::seconds>(t2.time_since_epoch());
	std::cout << ms1.count() << " seconds since 01-Jan-1970"  << std::endl; // 输毫秒级时间戳
	
	auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t2.time_since_epoch());
	std::cout << ms2.count() << " milliseconds since 01-Jan-1970"  << std::endl; // 输出毫秒级时间戳

	auto ms3 = std::chrono::duration_cast<std::chrono::microseconds>(t2.time_since_epoch());
	std::cout << ms3.count() << " microseconds since 01-Jan-1970"  << std::endl; // 输出微秒级时间戳
	
	auto ms4 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2.time_since_epoch());
	std::cout << ms4.count() << " nanoseconds since 01-Jan-1970"  << std::endl; // 输出纳秒级时间戳
	
	auto ms5 = std::chrono::duration_cast<std::chrono::minutes>(t2.time_since_epoch());
	std::cout << ms5.count() << " minutes since 01-Jan-1970"  << std::endl; // 输出分钟级时间戳
	
	auto ms6 = std::chrono::duration_cast<std::chrono::hours>(t2.time_since_epoch());
	std::cout << ms6.count() << " hours since 01-Jan-1970"  << std::endl; // 输出分钟级时间戳

	return 0;
}

