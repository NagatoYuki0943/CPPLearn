#include <iostream>
#include <string>

using namespace std;
/**
 * �ڳ�����,��Щ˽������,Ҳ�������������һЩ������������з���,����Ҫ�õ��õ���Ԫ�ļ���
 * ��Ԫ��Ŀ������һ�����������������һ�����˽�г�Ա
 * �ؼ���:friend
 *
 * ��Ԫ������ʵ��:
 *      ȫ�ֺ�������Ԫ(�����κ�����ߺ�����),Ҳ���԰���������д��class���浱����Ԫ����
 *      ������Ԫ(��������)
 *      ��Ա��������Ԫ
 */

//������
class Building {
    ///ȫ�ֺ�������Ԫ,����������,GoodFriend���Է������е�˽�г�Ա,���ù�������
    friend void GoodFriend(Building &build);

public:
    Building() : m_SittingRoom("����"), m_Bedroom("����") {
    }

    string m_SittingRoom; //����
private:
    string m_Bedroom;     //����
};

//ȫ�ֺ���
void GoodFriend(Building &build) {
    cout << "�����ѵ�ȫ�ֺ������ڷ���:" << build.m_SittingRoom << endl;
    cout << "�����ѵ�ȫ�ֺ������ڷ���:" << build.m_Bedroom << endl;
}

void test01() {
    Building building;
    GoodFriend(building); //����build����

}

int main() {
    test01();

    system("pause");
    return 0;
}
