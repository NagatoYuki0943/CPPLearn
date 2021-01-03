#include <iostream>

using namespace std;
/**
 * 共用体(union)是一种数据格式,它能够存储不同的数据类型,但是只能同时存储其中的一种类型
 */
union one4all {
    int int_val;
    long long_val;
    double double_val;
};

int main() {
    //可以使用one4all变量来存储int,long或double,条件是在不同的时间进行
    one4all pail;
    pail.int_val = 15;
    cout << pail.int_val << endl;
    pail.double_val = 15.4;
    cout << pail.double_val << endl;
    /**
     * 因此,pail有时可以是int变量,有时又可以是double边浪,成员名称标识了变量的容量.由于共用体每次只能存储
     * 一个值,因此它必须有足够的空间来存储最大的成员,所以,共用体的长度为其最大的变量的长度
     */
    /**
     *还有匿名共用体,其成员位于相同地址处的变量,每次只有一个成员是当前的成员
     * 由程序员来确定当前那个成员是活动的
     */
    return 0;
}