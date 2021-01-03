#include <iostream>
#include <string>
#include "16myArray.hpp"

using namespace std;

/**
 * 案例需求:实现一个通用的数组类,要求如下:
 *  1.可以对内置数据类型和自定义数据类型的数据进行存储
 *  2.将数组中的数据存储到堆区
 *  3.构造函数中可以传入数组的容量
 *  4.提供对应的拷贝构造函数以及 operator= 防止拷贝问题
 *  5.提供尾插法和尾删法对数组中的数据进行增加和删除
 *  6.可以通过下标的方式访问数组中的元素
 *  7.可以获取数组中当前元素个数和容量
 */
//数组打印
void printIntArray(MyArray<int> array) {
    for (int i = 0; i < array.getSize(); ++i) {
        cout << array[i] << endl;
    }
}

void test01() {
    MyArray<int> arr1(5);   //有参构造  析构函数
    MyArray<int> arr2(arr1);    //拷贝构造  析构函数
    MyArray<int> arr3(100); //有参构造  析构函数
    arr3 = arr1;    //operator=
}

void test02() {
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; ++i) {
        //利用尾插法向数组中插入元素
        arr1.Push_Back(i + 10);
    }

    //打印数组
    cout << "arr1:" << endl;
    printIntArray(arr1);    //10 11 12 13 14

    //获取容量
    cout << "arr1.Capacity = " << arr1.getCapacity() << endl;   // 5
    //获取长度
    cout << "arr1.Size = " << arr1.getSize() << endl;           // 5

    MyArray<int> arr2(arr1);
    cout << "arr2:" << endl;
    printIntArray(arr1);    //10 11 12 13 14

    //尾删
    arr2.Pop_Back();
    //获取容量
    cout << "arr2.Capacity = " << arr2.getCapacity() << endl;   // 5    容量不变
    //获取长度
    cout << "arr2.Size = " << arr2.getSize() << endl;           // 4    长度-1
}

//测试自定义的数据类型
class Person {
public:
    //用了构造函数会失败,在堆区数据创建的时候需要数据,所以要创建一个空的构造函数
    Person(){}
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//打印Person
void printPersonArray(MyArray<Person> &arr) {
    cout << "printPersonArray" << endl;
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << "name : " << arr[i].m_Name << " age:" << arr[i].m_Age << endl;
    }
}

void test03() {
    MyArray<Person> arr(10);
    Person p1("孙悟空",999);
    Person p2("韩信",10);
    Person p3("唐僧",20);
    Person p4("猪八戒",50);
    Person p5("矢泽妮可",16);


    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    printPersonArray(arr);

    //获取容量
    cout << "arrPerson.Capacity = " << arr.getCapacity() << endl;   // 5
    //获取长度
    cout << "arrPerson.Size = " << arr.getSize() << endl;
}

int main() {
    //test01();
    //test02();
    test03();
    return 0;
}
