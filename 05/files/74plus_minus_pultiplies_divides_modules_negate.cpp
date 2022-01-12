#include <iostream>
#include <functional>

using namespace std;
/**
 * 内建函数对象
 * 概念：
 *  STL内建了一些函数对象
 * 分类:
 *  算术仿函数
 *  关系仿函数
 *  逻辑仿函数
 * 用法：
 *  这些仿函数所产生的对象，用法和一般函数完全相同
 *  使用内建函数对象，需要引入头文件 #include<functional>
 *
 * 算术仿函数
 * 功能描述：
 *  实现四则运算
 *  其中negate是一元运算，其他都是二元运算
 * 仿函数原型：
 *  plus<T>             //加法仿函数     plus<int> plus;
 *  minus<T>            //减法仿函数     minus<int> minus;
 *  multiplies<T>       //乘法仿函数     multiplies<int> multiplies;
 *  divides<T>          //除法仿函数     divides<int> divides;
 *  modulus<T>          //取模仿函数     modulus<int> modulus;
 *  negate<T>           //取反仿函数     negate<int> negate;
 */

void test01() {

    //plus 加法
    plus<int> plus;
    //像函数调用一样即可
    int res = plus(50, 10);
    cout << res << endl;        //60

    //minus 减法
    minus<int> minus;
    res = minus(50, 6);
    cout << res << endl;        //44

    //multiplies 乘法
    multiplies<int> multiplies;
    res = multiplies(5, 6);
    cout << res << endl;        //30

    //divides 除法
    divides<int> divides;
    res = divides(9, 5);
    cout << res << endl;        //1

    //modulus 取余
    modulus<int> modulus;
    res = modulus(50, 7);
    cout << res << endl;        //1

    //negate 一元仿函数  取反仿函数
    negate<int> negate;
    res = negate(50);
    cout << res << endl;        //-50
}

int main() {
    test01();
    return 0;
}
