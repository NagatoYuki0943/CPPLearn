#include <iostream>

using namespace std;

/**
 *c++编译器至少给一个类添加4个函数
 *  1.默认构造函数(无参,函数体为空)
 *  2.默认析构函数(无参,函数体为空)
 *  3.默认拷贝构造函数,对属性值进行拷贝
 *  4.赋值运算符 operator=,对属性进行值拷贝   = 是赋值,不是拷贝
 *
 *  编译器默认提供的 = 赋值是浅拷贝,但是如果有数据在堆区,会出问题,要进行深拷贝
 *  如果类中有属性指向堆区,做赋值操作时也会出现深浅拷贝问题
 *
 *  注意:不能使用全局函数,operator=必须是非静态函数,全局区是静态的  =只能使用成员函数
 */
class Person {
public:
    Person(int age) {
        m_Age = new int(age);//开辟到堆区
    }

    int *m_Age;

    ~Person() {
        if (m_Age != NULL)
            delete m_Age;
        m_Age = NULL;
    }

    //重载赋值运算符
    //要返回引用,不然返回的不是自己的对象
    Person &operator=(Person &p) {  //注意引用传值,不然p1的值会出问题
        //编译器提供浅拷贝,如下
        //m_Age=p.m_Age;
        ///应该先判断是否有数据在堆区,如果有,先释放干净,然后再深拷贝
        if (m_Age != NULL) {   //这是清空自己的,是 等号左边的对象
            delete m_Age;
            m_Age = NULL;
        }
        //深拷贝
        m_Age = new int(*p.m_Age);
        return *this; //返回自己的对象
    }
};

//不能使用全局函数,operator=必须是非静态函数,全局区是静态的
//Person& operator=(Person &p1, Person &p2){ }


void test01() {
    Person p1(18);
    Person p2(20);
    Person p3(30);
    //p2=p1;  //默认浅拷贝,会导致p2的年龄也是18,要修改成深拷贝
    p3 = p2 = p1; ///默认报错,因为operator默认无返回值,返回值是Person&,要是引用才没错
    cout << "p1的年龄:" << *p1.m_Age << endl; //解引用,m_Age是指针
    cout << "p2的年龄:" << *p2.m_Age << endl; //解引用,m_Age是指针
    cout << "p3的年龄:" << *p3.m_Age << endl; //解引用,m_Age是指针

}

int main() {
    test01();
    int a = 10, b = 20, c = 30;
    c = b = a;
    cout << "a=" << a << endl; //10
    cout << "b=" << b << endl; //b=a=10
    cout << "c=" << c << endl; //c=b=10

    system("pause");
    return 0;
}