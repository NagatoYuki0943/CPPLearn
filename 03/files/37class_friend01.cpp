#include <iostream>
#include <string>

using namespace std;
/**
 * 在程序里,有些私有属性,也想让类外特殊的一些函数或者类进行访问,就需要用到用到友元的技术
 * 友元的目的是让一个函数或者类访问另一个类的私有成员
 * 关键字:friend
 *
 * 友元的三种实现:
 *      全局函数做友元(不在任何类或者函数中)
 *      类做友元(其他的类)
 *      成员函数做友元
 */

//建筑物
class Building {
    ///类做友元,这个在这里声明的类可以访问这个类中的私有成员
    friend class GoodFriend;

public:
    Building();

    string m_SittingRoom; //客厅
private:
    string m_Bedroom;     //卧室
};

//类外写成员函数
Building::Building() {
    m_SittingRoom = "客厅";
    m_Bedroom = "卧室";
}


//朋友类
class GoodFriend {
public:
    GoodFriend();

    Building *building;

    void visit();  //参观函数访问building的属性
};

//类外实现
GoodFriend::GoodFriend() {
    //创建建筑物的对象
    building = new Building;   ///new在堆区创建对象,返回指针,用 building指针保存
}

void GoodFriend::visit() {
    cout << "好朋友这个类正在访问:" << building->m_SittingRoom << endl;
    cout << "好朋友这个类正在访问:" << building->m_Bedroom << endl;
}


void test01() {
    GoodFriend gf;
    gf.visit();
}

int main() {
    test01();

    system("pause");
    return 0;
}
