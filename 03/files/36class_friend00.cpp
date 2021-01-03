#include <iostream>
#include <string>

using namespace std;
/**
 * 在程序里,有些私有属性,也想让类外特殊的一些函数或者类进行访问,就需要用到用到友元的技术
 * 友元的目的是让一个函数或者类访问另一个类的私有成员
 * 关键字:friend
 *
 * 友元的三种实现:
 *      全局函数做友元(不在任何类或者函数中),也可以把整个函数写在class里面当做友元函数
 *      类做友元(其他的类)
 *      成员函数做友元
 */

//建筑物
class Building {
    ///全局函数做友元,在类中声明,GoodFriend可以访问类中的私有成员,不用管作用域
    friend void GoodFriend(Building &build);

public:
    Building() : m_SittingRoom("客厅"), m_Bedroom("卧室") {
    }

    string m_SittingRoom; //客厅
private:
    string m_Bedroom;     //卧室
};

//全局函数
void GoodFriend(Building &build) {
    cout << "好朋友的全局函数正在访问:" << build.m_SittingRoom << endl;
    cout << "好朋友的全局函数正在访问:" << build.m_Bedroom << endl;
}

void test01() {
    Building building;
    GoodFriend(building); //传入build对象

}

int main() {
    test01();

    system("pause");
    return 0;
}
