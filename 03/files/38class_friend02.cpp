#include <iostream>
#include <string>

using namespace std;

/**
 * �ڳ�����,��Щ˽������,Ҳ�������������һЩ������������з���,����Ҫ�õ��õ���Ԫ�ļ���
 * ��Ԫ��Ŀ������һ�����������������һ�����˽�г�Ա
 * �ؼ���:friend
 *
 * ��Ԫ������ʵ��:
 *      ȫ�ֺ�������Ԫ(�����κ�����ߺ�����)
 *      ������Ԫ(��������)
 *      ��Ա��������Ԫ
 */


class Building;

class GoodFriend {
public:
    GoodFriend();

    void visit1();  //��visit1����building�е�˽�г�Ա
    void visit2();  //��visit1���ܷ���building�е�˽�г�Ա

    Building *building;
};


class Building {
    ///���߱�����,GoodFriend::visit1()����Ԫ���ں���
    friend void GoodFriend::visit1();  ///BuildingҪ��GoodFriend����,��Ϊ��Ҫ������Ԫ
public:
    Building();

    string m_SittingRoom;
private:
    string m_BedRoom;
};

//����ʵ��
Building::Building() {
    m_SittingRoom = "����";
    m_BedRoom = "����";
}

//GoodFriendҪ�õ�Building��,���Ҫ�ŵ�Building����
GoodFriend::GoodFriend() {
    building = new Building;     ///new�ڶ�����������,����ָ��,�� buildingָ�뱣��
}

void GoodFriend::visit1() {
    cout << "visit1 ��������������ڷ���:" << building->m_SittingRoom << endl;
    cout << "visit1 ��������������ڷ���:" << building->m_BedRoom << endl;
    cout << endl;
}

void GoodFriend::visit2() {
    cout << "visit2 ��������������ڷ���:" << building->m_SittingRoom << endl;
    //cout << "visit2 ��������������ڷ���:" << building->m_BedRoom <<endl;  //���ܷ���
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
