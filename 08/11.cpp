#include <iostream>

using namespace std;

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age){
        this->name = name;
        this->age = age;
    }

    void showPerson() {
        cout << "名字:" << this->name << endl;
        cout << "年龄:" << this->age << endl;
    }

private:
    T1 name;
    T2 age;
};

//函数强制规定类型,调用时也要强制规定类型
void printPerson1(Person<string, int> &p){
    p.showPerson();
}

void test01() {
    //调用时也要强制规定类型
    Person<string, int> p = Person<string, int>("孙悟空", 500);
    printPerson1(p);
    //名字:孙悟空
    //年龄:500
}

//将函数参数类型爷设为template,调用时不用强制类型
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> &p){
    p.showPerson();
}

void test02() {
    Person p = Person("猪八戒", 200);
    printPerson2(p);
    //名字:孙悟空
    //年龄:500
}

//将参数类型直接设置为template也可以
template<typename T>
void printPerson3(T &p){
    p.showPerson();
}

void test03() {
    Person p = Person("沙和尚", 100);
    printPerson3(p);
    //名字:孙悟空
    //年龄:500
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}