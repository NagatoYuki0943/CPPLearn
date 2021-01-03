#include <iostream>

using namespace std;

/**
 * c++通过提供特殊的对象指针,this指针,来区分自己
 * this指针指向被调用的成员函数所属的对象
 * this指针是隐含每一个非静态成员函数内的一种指针
 * this指针不需要定义,直接使用即可
 *
 * this指针的本质是指针常量,指针的指向是不可以修改的
 *
 * this用途:
 *      解决名称冲突:当形参和成员变量同名时,使用this->指针区分
 *      返回对象本身:当类的非静态成员函数返回对象本身,可以使用 return *this  (解引用)
 *
 * @return
 */
class Person {
public:
    Person(int age) : age(age) {    //this->age(age) 不能这样使用 但是可以age(age)
        //age=age;        //0 没有赋值成功,三个age是同一份
        //this->age=age;  //18  赋值成功
    }

    ///注意:返回本体要使用&,会返回自己
    ///如果返回值,每次返回的按本体拷贝出的新函数,age还是等于原来的值
    Person &PersonAddAge(Person &p) {
        this->age += p.age;   //传入的年龄+上自己的年龄赋值到自身年龄
        return *this; //返回object本体
    }

    //this=NULL; //this指针不可以修改指针的指向
    int age;
};

///解决名称冲突:当形参和成员变量同名时,使用this->指针区分
void test01() {
    Person p1(18);
    cout << "p1的年龄:" << p1.age << endl;
}

///返回对象本身,return * this
void test02() {
    Person p1(10);
    Person p2(5);

    //这个函数没有返回值,只能调用一次,因为没有返回,就没法在调用
    //返回*this之后才能重复调用这个函数,返回object,再用object的函数
    //返回值类型是 Person&  引用返回
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);   //链式编程思想
    cout << "p2的年龄为:" << p2.age << endl;     //5+10+10+10=35
}

int main() {
    //test01();
    test02();

    system("pause");
    return 0;
}
