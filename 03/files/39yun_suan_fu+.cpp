#include <iostream>

using namespace std;
/**
 * 运算符重载:对已有的运算符重新进行定义,赋予另一种功能,以适应不同的数据类型
 * 对于内置的数据类型,编译器知道如何进行运算,内置数据类型的数据类型是不能改变的
 * 重载方式:成员函数,全局函数
 * 不要滥用运算符重载
 *
 * +,++,==,!=可以使用全局函数和成员函数,<<只能使用全局函数,=只能使用成员函数,()在类内使用
 */
/**
 *  +号运算符重载   operator+
 *  1.通过成员函数重载
 *  2.通过全局函数重载    两种方法不能同时存在
 *
 *  运算符重载也可以发生函数重载
 *  支持成员函数和全局函数写法
 */

class Person {
public:
    int m_A;
    int m_B;
    /**
     * 1.通过成员函数重载
     * 本质 Person p3=p1.operator+(p2)
     */

    /*Person operator+ (Person &p){
        Person tmp;
        tmp.m_A=this->m_A+p.m_A;
        tmp.m_B=this->m_B+p.m_B;
        return tmp;
    }*/
};

///2.通过全局函数重载
Person operator+ (Person &p1, Person &p2) {
    Person tmp;
    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;
    return tmp;
}

///运算符重载也可以发生函数重载,类型不同
Person operator+ (Person &p1, int a) {
    Person tmp;
    tmp.m_A = p1.m_A + a;
    tmp.m_B = p1.m_B + a;
    return tmp;
}

void test01() {
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 20;
    p2.m_B = 20;
    /**
     * 1.通过成员函数重载
     * 本质 Person p3=p1.operator+(p2)
     * 2.通过全局函数重载
     * 本质 Person p3=operator+(p1,p2)
     */

    Person p3 = p1 + p2;   //加法的写法
    cout << "p3.m_A=" << p3.m_A << endl;  //10+20=30
    cout << "p3.m_B=" << p3.m_B << endl;  //10+20=30

    ///运算符重载也可以发生函数重载,类型不同
    int a = 5;
    Person p4 = p3 + a;
    cout << "p3.m_A=" << p4.m_A << endl;  //30+5=35
    cout << "p3.m_B=" << p4.m_B << endl;  //30+5=35
}

int main() {
    test01();


    //字符串可以相加
    string a = "aaa";
    string b = "bbb";
    string c = a + b;  //可以相加,相减,相乘,相除,取余不可以
    //string d=a-b;
    //string e=a*b;
    //string f=a/b;
    //string g=a&b;
    //cout << c << endl;  //aaabbb
    system("pause");
    return 0;
}
