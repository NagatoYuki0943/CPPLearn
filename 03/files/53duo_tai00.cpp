#include <iostream>

using namespace std;
/**
 * 父类指针可以直接指向对象
 *
 * 多态是C++面向对象三大特性之一
 * 多态分两类:
 *      静态多态:函数重载和运算符重载属于静态多态,复用函数名和运算符
 *      动态多态:派生类和虚函数实现运行时多态
 * 静态多态和动态多态的区别:
 *      静态多态的函数地址早绑定 - 编译阶段确定函数地址
 *      动态多态的函数地址晚绑定 - 运行阶段确定函数地址
 * 静态多态:
 *      void speak(){}
 * 动态多态:
 *      virtual void speak(){}
 */
/**
 * 动态多态
 * 1.要有继承,父类要有虚函数(virtual),
 * 2.子类要重写父类的虚函数  (函数返回值类型,函数名称和参数列表完全相同),子类重写的virtual关键字写不写都可
 */
/**
 * 动态多态的使用,父类的指针或者引用指向子类的对象
 */
//动物类
class Animal {
public:
    //虚函数
    virtual void speak() {
        cout << "动物在说话" << endl;
    }
};

//猫类
class Cat : public Animal {
public:
    void speak() {
        cout << "小猫在说话" << endl;
    }
};

//狗类
class Dog : public Animal {
public:
    //可以加上override指明
    void speak() override{
        cout << "小狗在说话" << endl;
    }
};

//执行说话的函数
///地址早绑定,在编译阶段就确定函数地址,是Animal对象,走Animal内的函数
///如果想执行地址晚绑定,那么这个函数地址就不能提前绑定,需要在运行阶段进行绑定,地址晚绑定  在Animal中的函数前加上virtual就行
void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    Dog dog;
    //父类引用接收子类对象
    doSpeak(cat);  ///Animal & animal = cat 父类指针可以直接指向对象   一开始打印:动物在说话,加上virtual就变为:小猫在说话
    doSpeak(dog);

    Animal animal;
    animal.speak();    ///父类有了virtual,这个函数依然可以访问
    doSpeak(animal);
}

void test02() {
    ///字符串常量不属于类内,所以Animal类是空类,大小是1,加上virtual大小是4(32位),在clion里是8(64位) 是一个指针
    cout << "sizeof Animal=" << sizeof(Animal) << endl;
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}