#include <iostream>

using namespace std;

/**
 * 构造函数的分类及调用
 * 两种分类方法:
 *      按参数分为:有参调用,无参(默认)调用
 *      按类型分为:普通构造,拷贝构造
 * 三种调用方式:
 *      括号法:     调用默认构造函数的时候,不要加(),不然编译器会认为是一个函数的声明
 *      显示法:
 *      隐式转换法:
 */
class Person {
public: //在public下外面才能访问

    //按照参数分类
    Person() {
        cout << "Person(){}无参构造函数调用" << endl;
    }

    Person(int a) {   //没有返回值也不写void
        age = a;
        cout << "Person(){}有参构造函数调用" << endl;
    }

    //拷贝构造函数,上面的是普通构造
    Person(const Person &p) {  //传入引用
        //将传入的class的所有属性,拷贝到这个class上
        age = p.age;
        cout << "Person(){}拷贝构造函数调用" << endl;
    }

    int age;
};

//调用
void test01() {
    /**
     * 括号法:
     */
    Person p1;     //无参构造
    Person p2(10); //有参构造
    Person p3(p1); //拷贝构造,拷贝其他的类
    Person *px = new Person();    //使用new在堆区创建数据要使用指针保存

    //注意事项1:
    //调用默认构造函数的时候,不要加()
    //因为下面这行代码,编译器会认为是一个函数的声明
    //Person p4();  //没有创建出对象

    cout << "p2的年龄为:" << p2.age << endl;  //10
    cout << "p3的年龄为:" << p2.age << endl;  //10 ,拷贝了p2的属性
    cout << endl;

    /**
     * 显示法
     */

    Person p6 = Person(10); //有参构造
    Person p7 = Person(p6); //拷贝构造
    //等号右侧是匿名对象:当当前行执行结束后,系统会立即回收到匿名对象
    cout << endl;
    //注意事项2
    //不要利用拷贝构造函数初始化匿名对象,编译器会任务Person(p7)===Person p7 ,p7前面已经定义了,会重复定义
    //Person(p7); //会出错


    /**
     * 隐式转换法
     */
    Person p8 = 10; //有参调用  相当于 Person p8=Person(10)
    Person p9 = p8; //拷贝调用  相当于 Person p9=Person(p8)



}

int main() {

    test01();


    system("pause");
    return 0;
}
