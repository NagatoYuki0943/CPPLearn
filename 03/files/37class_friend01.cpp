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

//������
class Building {
    ///������Ԫ,�������������������Է���������е�˽�г�Ա
    friend class GoodFriend;

public:
    Building();

    string m_SittingRoom; //����
private:
    string m_Bedroom;     //����
};

//����д��Ա����
Building::Building() {
    m_SittingRoom = "����";
    m_Bedroom = "����";
}


//������
class GoodFriend {
public:
    GoodFriend();

    Building *building;

    void visit();  //�ιۺ�������building������
};

//����ʵ��
GoodFriend::GoodFriend() {
    //����������Ķ���
    building = new Building;   ///new�ڶ�����������,����ָ��,�� buildingָ�뱣��
}

void GoodFriend::visit() {
    cout << "��������������ڷ���:" << building->m_SittingRoom << endl;
    cout << "��������������ڷ���:" << building->m_Bedroom << endl;
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
