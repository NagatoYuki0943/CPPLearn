#include <iostream>

using namespace std;
/**
 * ��װ,�̳кͶ�̬
 * ��װ������:
 *      1.�����Ժ���Ϊ��Ϊһ������,���������е�����
 *      2.�����Ժ���Ϊ����Ȩ�޿���
 * ��������ʱ��,���Ժ���Ϊд��һ��,��������
 * class ����{����Ȩ��: ����/��Ϊ}
 */
//���һ��Բ��,��Բ���ܳ� //2 * PI *�뾶
//PI
const double PI = 3.14;

class Circle {
    //����Ȩ��
    //����Ȩ��
public:
    //����
    int m_radius;

    //��Ϊ
    //��ȡԲ���ܳ�(����)
    double calculateZC() {
        return 2 * PI * m_radius;
    }
};

class Person {
public:
    char m_Name[64]; //������ʹ��string,�������
    int age;
};

Person p = {"���� ", 18};  //���������ֱ�Ӵ�������ֵ
int main() {

    //ͨ��Բ��,���������Բ(����)
    Circle c1; //��������
    c1.m_radius = 10;
    int ZC = c1.calculateZC(); //62
    cout << "Բ���ܳ���:" << ZC << endl;


    system("pause");
    return 0;
}

/**
 * ����ʹ��new���������ָ��
 * ����������Ķ���
 * Building *build;
 * build = new Building;   //new�ڶ�����������,����ָ��,�� buildingָ�뱣��
 */
