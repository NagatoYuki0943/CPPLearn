#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


/**
 * @brief 获取两个集合的交集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 交集结果 (2, 3)
 */
template <typename T>
std::set<T> set_intersection(const std::set<T> &a, const std::set<T> &b) {
	std::set<T> result_set;
	std::set_intersection(a.begin(), a.end(),
	                      b.begin(), b.end(),
	                      std::inserter(result_set, result_set.begin()));
	return result_set;
}

/**
 * @brief 获取两个集合的并集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 并集结果 (1, 2, 3, 4)
 */
template <typename T>
std::set<T> set_union(const std::set<T> &a, const std::set<T> &b) {
	std::set<T> result_set;
	std::set_union(a.begin(), a.end(),
	               b.begin(), b.end(),
	               std::inserter(result_set, result_set.begin()));
	return result_set;
}

/**
 * @brief 获取两个集合的差集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 差集结果 (1)
 */
template <typename T>
std::set<T> set_difference(const std::set<T> &a, const std::set<T> &b) {
	std::set<T> result_set;
	std::set_difference(a.begin(), a.end(),
	                    b.begin(), b.end(),
	                    std::inserter(result_set, result_set.begin()));
	return result_set;
}

void test1(std::set<int> a, std::set<int> b) {
	std::set<int> c;

	std::cout << "a = (";
	for (auto i : a)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;

	std::cout << "b = (";
	for (auto i : b)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;

	c = set_intersection(a, b);
	std::cout << "set_intersection result = (";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;

	c = set_union(a, b);
	std::cout << "set_union result = (";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;

	c = set_difference(a, b);
	std::cout << "a, b set_difference result = (";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;

	c = set_difference(b, a);
	std::cout << "b, a set_difference result = (";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << ")" << std::endl;
}

/**
 * @brief 获取两个集合的交集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 交集结果 (2, 3)
 */
template <typename T>
std::vector<T> vector_intersection(const std::vector<T> &a, const std::vector<T> &b) {
	std::vector<T> result_set;
	std::set_intersection(a.begin(), a.end(),
	                      b.begin(), b.end(),
	                      std::inserter(result_set, result_set.begin()));
	return result_set;
}

/**
 * @brief 获取两个集合的并集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 并集结果 (1, 2, 3, 4)
 */
template <typename T>
std::vector<T> vector_union(const std::vector<T> &a, const std::vector<T> &b) {
	std::vector<T> result_set;
	std::set_union(a.begin(), a.end(),
	               b.begin(), b.end(),
	               std::inserter(result_set, result_set.begin()));
	return result_set;
}

/**
 * @brief 获取两个集合的差集
 *
 * @param a 集合 a(1, 2, 3)
 * @param b 集合 b(2, 3, 4)
 *
 * @return 差集结果 (1)
 */
template <typename T>
std::vector<T> vector_difference(const std::vector<T> &a, const std::vector<T> &b) {
	std::vector<T> result_set;
	std::set_difference(a.begin(), a.end(),
	                    b.begin(), b.end(),
	                    std::inserter(result_set, result_set.begin()));
	return result_set;
}

void test2(std::vector<int> a, std::vector<int> b) {
	std::vector<int> c;

	std::cout << "a = [";
	for (auto i : a)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;

	std::cout << "b = [";
	for (auto i : b)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;

	c = vector_intersection(a, b);
	std::cout << "vector_intersection result = [";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;

	c = vector_union(a, b);
	std::cout << "vector_union result = [";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;

	c = vector_difference(a, b);
	std::cout << "a, b vector_difference result = [";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;

	c = vector_difference(b, a);
	std::cout << "b, a vector_difference result = [";
	for (auto i : c)
		std::cout << i << ", ";
	std::cout << "]" << std::endl;
}

int main() {
	std::set<int> a = {1, 2, 3};
	std::set<int> b = {2, 3, 4};
	test1(a, b);
	std::cout << std::endl;
	// a = [1, 2, 3, ]
	// b = [2, 3, 4, ]
	// set_intersection result = [2, 3, ]
	// set_union result = [1, 2, 3, 4, ]
	// a, b set_difference result = [1, ]
	// b, a set_difference result = [4, ]

	a = {};
	b = {2, 3, 4};
	test1(a, b);
	std::cout << std::endl;
	// a = []
	// b = [2, 3, 4, ]
	// set_intersection result = []
	// set_union result = [2, 3, 4, ]
	// a, b set_difference result = []
	// b, a set_difference result = [2, 3, 4, ]

	a = {2, 3, 4};
	b = {};
	test1(a, b);
	std::cout << std::endl;
	// a = [2, 3, 4, ]
	// b = []
	// set_intersection result = []
	// set_union result = [2, 3, 4, ]
	// a, b set_difference result = [2, 3, 4, ]
	// b, a set_difference result = []

	a = {};
	b = {};
	test1(a, b);
	std::cout << std::endl;
	// a = []
	// b = []
	// set_intersection result = []
	// set_union result = []
	// a, b set_difference result = []
	// b, a set_difference result = []

	std::cout << std::endl;
	std::vector<int> c = {1, 2, 3};
	std::vector<int> d = {2, 3, 4};
	test2(c, d);
	std::cout << std::endl;
	// a = [1, 2, 3, ]
	// b = [2, 3, 4, ]
	// vector_intersection result = [2, 3, ]
	// vector_union result = [1, 2, 3, 4, ]
	// a, b vector_difference result = [1, ]
	// b, a vector_difference result = [4, ]
	
	return 0;
}
