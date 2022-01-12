#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void test1(){
    plus<int> plus;
    cout << plus(1, 2) << endl;

    minus<int> minus;
    cout << minus(1, 2) << endl;

    multiplies<int> multiplies;
    cout << multiplies(1, 2) << endl;

    divides<int> divides;
    cout << divides(1, 2) << endl;

    //取余
    modulus<int> modulus;
    cout << modulus(1, 2) << endl;  // 1

    //取反
    negate<int> negate;
    cout << negate(1) << endl;         // -1
}

/**
 *  bool equal_to<T>                  //等于
 *  bool not_equal_to<T>              //不等于
 *  bool greater<T>                   //大于        greater<int>()
 *  bool greater_equal<T>             //大于等于
 *  bool less<T>                      //小于
 *  bool less_equal<T>                //小于等于
 */
void test2(){
    vector<int> v{10, 30, 40, 20, 50};
    //从到小排序,默认从小到大,用自己的仿函数也要加()
    sort(v.begin(), v.end(), greater<int>());
    for(int i: v){
        cout << i << " ";
    }
    //50 40 30 20 10
    cout << endl;
}

/**
 * 逻辑仿函数
 *  实现逻辑运算
 * 函数原型：
 *  bool logical_and<T>              //逻辑与
 *  bool logical_or<T>               //逻辑或
 *  bool logical_not<T>              //逻辑非    logical_not<bool>()
 */
void test3(){
    vector<bool> v1{true, false, true, false, false, true};
    //1 0 1 0 0 1

    vector<bool> v2;
    v2.resize(v1.size()-1);
    //传输,源.begin(),源.end() ==> 目的.begin()    取反操作 logical_not<bool>()
    transform(v1.begin(), v2.begin()-1, v2.begin(),logical_not<bool>());
    for(bool i: v2){
        cout << i << " ";   //0 1 0 1 1
    }
}

int main(){
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    return 0;
}