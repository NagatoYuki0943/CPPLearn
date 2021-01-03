#include <iostream>

using namespace std;

/**
 * 重载自增++运算符,实现自己的整形数据
 * <<重载的类输入的是值,不能是引用
 * 前置递增返回引用,后置递增返回值
 * 支持成员函数和全局函数写法
 */
class MyInteger {
    //使用友元全局函数
    friend ostream &operator<<(ostream &cout, MyInteger m);

public:
    MyInteger() {
        m_Num = 0;
    }

    ///重载前置递增++运算符
    MyInteger &operator++() { //不需要参数,类型是MyInteger&,引用是为了一直对一个数进行相加
        //先进行++运算,在返回
        m_Num++;
        return *this;  //返回自身
    }

    ///重载后置递增++运算符
    //MyInteger operator++(){   //直接这样写会报错,会认为和上面的函数重复了
    MyInteger operator++(int) {  ///里面写上int,编译器会知道这是后置递增,int代表占位参数,可以用于区分前置和后置
        //后置递增返回的是值,不是引用,返回引用的话会返回局部object tmp
        //先记录当时结果
        MyInteger tmp = *this;
        //后递增
        m_Num++;
        //最后将记录结果返回
        return tmp;
    }

private:
    int m_Num;
};

//全局函数重载
ostream &operator<<(ostream &cout, MyInteger m) { //后面的m不要引用,不然可能找不到局部
    cout << m.m_Num;
    return cout;
}

void test01() {
    MyInteger myint;
    cout << ++(++myint) << endl; //2
    cout << myint << endl;       //2
}

void test02() {
    MyInteger myint;
    cout << myint++ << endl;  //0
    cout << myint << endl;    //1
}

int main() {
    test01();
    //test02();

    system("pause");
    return 0;
}
