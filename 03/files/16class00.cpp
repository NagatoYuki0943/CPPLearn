#include <iostream>

using namespace std;
/**
 * 封装,继承和多态
 * 封装的意义:
 *      1.将属性和行为作为一个整体,表现生活中的事物
 *      2.将属性和行为加以权限控制
 * 在设计类的时候,属性和行为写在一起,表现事物
 * class 类名{访问权限: 属性/行为}
 */
//设计一个圆类,求圆的周长 //2 * PI *半径
//PI
const double PI = 3.14;

class Circle {
    //访问权限
    //公共权限
public:
    //属性
    int m_radius;

    //行为
    //获取圆的周长(函数)
    double calculateZC() {
        return 2 * PI * m_radius;
    }
};

class Person {
public:
    char m_Name[64]; //不建议使用string,会出问题
    int age;
};

Person p = {"张三 ", 18};  //类可以这样直接创建并赋值
int main() {

    //通过圆类,创建具体的圆(对象)
    Circle c1; //创建方法
    c1.m_radius = 10;
    int ZC = c1.calculateZC(); //62
    cout << "圆的周长是:" << ZC << endl;


    system("pause");
    return 0;
}

/**
 * 可以使用new创建对象的指针
 * 创建建筑物的对象
 * Building *build;
 * build = new Building;   //new在堆区创建对象,返回指针,用 building指针保存
 */
