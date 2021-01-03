#include <iostream>

using namespace std;
/**
 * 类模板与继承
 *
 * 当类模板碰到继承时,要注意以下几点
 *      1.当子类继承的父类是一个类模板时,子类在声明的时候,要指定父类中的T的类型
 *      2.如果不指定,编译器无法给子类分配内存
 *      3.如果想灵活指定出父类中T的类型,子类也需变为模板类
 */
template<class T>
class Base{
    T m;
};

//1.当子类继承的父类是一个类模板时,子类在声明的时候,要指定父类中的T的类型  <int>
class Son1 : public Base<int>{

};

void test01(){
    Son1 s1;
}

//3.如果想灵活指定出父类中T的类型,子类也需变为模板类
template<class T1,class T2>
class Son2 : public Base<T2>{
public:
    Son2(){
        cout << "T1的类型为: " << typeid(T1).name() << endl;    //T1的类型为: i
        cout << "T2的类型为: " << typeid(T2).name() << endl;    //T2的类型为: c
    }
    T1 obj;
};

void test02(){
    Son2<int,char> s2;  //<int,char> ==> template<class T1,class T2>

}


int main() {
    test01();
    test02();
    return 0;
}
