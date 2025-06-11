#include <ctime>
#include <chrono>
#include <iostream>

int main() {
	std::time_t t1 = std::time(0); // 获取当前时间戳（秒）
	std::cout << t1 << " seconds since 01-Jan-1970" << std::endl;
	
	// 可以使用 int 类型保存
	int t2 = std::time(0); // 获取当前时间戳（秒）
	std::cout << t2 << " seconds since 01-Jan-1970" << std::endl;
	
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();

	auto ms1 = std::chrono::duration_cast<std::chrono::seconds>(t3.time_since_epoch());
	std::cout << ms1.count() << " seconds since 01-Jan-1970"  << std::endl; // 输秒级时间戳
	
	auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t3.time_since_epoch());
	std::cout << ms2.count() << " milliseconds since 01-Jan-1970"  << std::endl; // 输出毫秒级时间戳

	auto ms3 = std::chrono::duration_cast<std::chrono::microseconds>(t3.time_since_epoch());
	std::cout << ms3.count() << " microseconds since 01-Jan-1970"  << std::endl; // 输出微秒级时间戳
	
	auto ms4 = std::chrono::duration_cast<std::chrono::nanoseconds>(t3.time_since_epoch());
	std::cout << ms4.count() << " nanoseconds since 01-Jan-1970"  << std::endl; // 输出纳秒级时间戳
	
	auto ms5 = std::chrono::duration_cast<std::chrono::minutes>(t3.time_since_epoch());
	std::cout << ms5.count() << " minutes since 01-Jan-1970"  << std::endl; // 输出分钟级时间戳
	
	auto ms6 = std::chrono::duration_cast<std::chrono::hours>(t3.time_since_epoch());
	std::cout << ms6.count() << " hours since 01-Jan-1970"  << std::endl; // 输出小时级时间戳

	auto t4 = std::chrono::high_resolution_clock::now();
	auto ms7 = std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3);
	std::cout << "interval = " << ms7.count() << " nanoseconds"  << std::endl;
	
	return 0;
}
