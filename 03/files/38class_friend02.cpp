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


class Building;

class GoodFriend {
public:
    GoodFriend();

    void visit1();  //让visit1访问building中的私有成员
    void visit2();  //让visit1不能访问building中的私有成员

    Building *building;
};


class Building {
    ///告诉编译器,GoodFriend::visit1()是友元类内函数
    friend void GoodFriend::visit1();  ///Building要在GoodFriend下面,因为它要声明友元
public:
    Building();

    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外实现
Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

//GoodFriend要用到Building类,因此要放到Building下面
GoodFriend::GoodFriend() {
    building = new Building;     ///new在堆区创建对象,返回指针,用 building指针保存
}

void GoodFriend::visit1() {
    cout << "visit1 好朋友这个类正在访问:" << building->m_SittingRoom << endl;
    cout << "visit1 好朋友这个类正在访问:" << building->m_BedRoom << endl;
    cout << endl;
}

void GoodFriend::visit2() {
    cout << "visit2 好朋友这个类正在访问:" << building->m_SittingRoom << endl;
    //cout << "visit2 好朋友这个类正在访问:" << building->m_BedRoom <<endl;  //不能访问
}


void test01() {
    GoodFriend gf;
    gf.visit1();
    gf.visit2();
}

int main() {
    test01();

    system("pause");
    return 0;
}
