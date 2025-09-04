#include <iostream>
#include <string>
#include <bitset>

int main() {
	// https://oi-wiki.org/lang/csl/bitset/

	std::bitset<8> bit1;
	// std::bitset<8> bit1 = {};
	std::cout << bit1 << std::endl;
	// 00000000

	std::bitset<8> bit2 = 7;
	// std::bitset<8> bit2 = {7};
	// std::bitset<8> bit2(7);
	// auto bit2 = std::bitset<8>(7);
	std::cout << bit2 << std::endl;
	// 00000111

	// std::bitset<8> bit3("11111111");
	auto bit3 = std::bitset<8>("11111111");
	std::cout << bit3 << std::endl;
	// 11111111
	std::cout << std::endl << std::endl;


	// operator []: 访问其特定的一位。
	bit1 = {};
	bit1[0] = 1;
	bit1[2] = 1;
	bit1[4] = 1;
	bit1[6] = 1;
	std::cout << bit1 << std::endl;
	// 01010101
	std::cout << std::endl << std::endl;


	// operator ==/operator !=: 比较两个 bitset 内容是否完全一样。
	std::cout << (bit1 == bit2) << std::endl; // 0
	std::cout << (bit1 == bit1) << std::endl; // 1
	std::cout << (bit2 == bit2) << std::endl; // 1
	std::cout << std::endl << std::endl;

	// operator &/operator &=/operator |/operator |=/operator ^/operator ^=/operator ~: 进行按位与/或/异或/取反操作。
	// 注意：bitset 只能与 bitset 进行位运算，若要和整型进行位运算，要先将整型转换为 bitset。
	bit1 = std::bitset<8>("10101010");
	bit2 = std::bitset<8>("01010101");
	std::cout << "bit1 = " << bit1 << std::endl; // 10101010
	std::cout << "bit2 = " << bit2 << std::endl; // 01010101
	std::cout << "bit1&bit2 = " << (bit1 & bit2) << std::endl; // 00000000
	std::cout << "bit1&bit2 = " << (bit1 | bit2) << std::endl; // 11111111
	std::cout << "bit1&bit2 = " << (bit1 ^ bit2) << std::endl; // 11111111
	std::cout << std::endl << std::endl;


	// operator <</operator >>/operator <<=/operator >>=: 进行二进制左移/右移。
	std::cout << "bit1 = " << bit1 << std::endl; // 10101010
	std::cout << "bit1 << 1 = " << (bit1 << 1) << std::endl; // 01010100
	std::cout << "bit1 << 2 = " << (bit1 << 2) << std::endl; // 10101000
	std::cout << "bit1 >> 1 = " << (bit1 >> 1) << std::endl; // 01010101
	std::cout << "bit1 >> 2 = " << (bit1 >> 2) << std::endl; // 00101010
	std::cout << std::endl << std::endl;


	// 成员函数
	bit1 = std::bitset<8>("10101010");
	std::cout << bit1 << std::endl;
	// 10101010

	// size(): 返回 bitset 的大小。
	std::cout << bit1.size() << std::endl;
	// 8

	// count(): 返回 true 的数量。
	std::cout << bit1.count() << std::endl;
	// 4

	// test(pos): 它和 vector 中的 at() 的作用是一样的，和 [] 运算符的区别就是越界检查。
	std::cout << bit1.test(0) << std::endl;
	// 0

	// all(): 若所有位都是 true 则返回 true，否则返回 false。
	std::cout << bit1.all() << std::endl;
	// 0

	// any(): 若存在某一位是 true 则返回 true，否则返回 false。
	std::cout << bit1.any() << std::endl;
	// 1

	// none(): 若所有位都是 false 则返回 true，否则返回 false。
	std::cout << bit1.none() << std::endl;
	// 0

	// set(): 将整个 bitset 设置成 true。
	bit1.set();
	std::cout << bit1 << std::endl;
	// 11111111

	// set(pos, val = true): 将某一位设置成 true/false。
	bit1.set(0, false);
	std::cout << bit1 << std::endl;
	// 11111110

	// reset(): 将整个 bitset 设置成 false。
	bit1.reset();
	std::cout << bit1 << std::endl;
	// 00000000

	// reset(pos): 将某一位设置成 false。相当于 set(pos, false)。
	bit1 = std::bitset<8>("10101010");
	bit1.reset(1);
	std::cout << bit1 << std::endl;
	// 10101000

	// flip(): 翻转每一位。
	bit1 = 0;
	std::cout << bit1 << std::endl; // 00000000
	std::cout << bit1.flip() << std::endl; // 11111111

	// flip(pos): 翻转某一位。
	bit1 = 0;
	std::cout << bit1 << std::endl; // 00000000
	std::cout << bit1.flip(0) << std::endl; // 00000001

	// to_string(): 返回转换成的字符串表达。
	bit1 = std::bitset<8>("10101010");
	std::cout << bit1.to_string() << std::endl;
	// 10101010

	// to_ulong(): 返回转换成的 unsigned long 表达（long 在 NT 及 32 位 POSIX 系统下与 int 一样，在 64 位 POSIX 下与 long long 一样）。
	std::cout << bit1.to_ulong() << std::endl;
	// 170

	// to_ullong():（C++11 起）返回转换成的 unsigned long long 表达。
	std::cout << bit1.to_ullong() << std::endl;
	// 170

	// bitset 不能使用 for (item_declaration : range_initializer) statement 语法

	return 0;
}
