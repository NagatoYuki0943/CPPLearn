#include <iostream>

using namespace std;

/**
 * const ����  static ��̬
 * const���γ�Ա����
 *  ������:
 *      ��Ա�������const���ǳ�Ϊ�������Ϊ������      void showPerson () const {}
 *      �������������޸ĳ�Ա����
 *      ��Ա��������ʱ�ӹؼ���mutable��,�ڳ���������Ȼ�����޸�   mutable int m_B;
 *  ������:
 *      ��������ǰ��const�Ƹö���Ϊ������
 *      ������ֻ�ܵ��ó�����,�����޸ı���
 *      ��Ա��������ʱ�ӹؼ���mutable��,�ڶ�����Ҳ��Ȼ�����޸�   mutable int m_B;
 */
class Person {
public:
    //������
    /**
     * thisָ��ı�����ָ�볣��,ָ���ָ���ǲ������޸ĵ�
     * Person * const this;
     * this=NULL; //thisָ�벻�����޸�ָ���ָ��
     * const Person * const this; === void showPerson () const{}
     * const ���ε���thisָ��,��ָ��ָ���ֵҲ�������޸�==������
     */

    void showPerson() const {
        //m_A=100; //�����Ͳ����޸�����ͨ������
        m_B = 100;
    }

    void func() {
        m_A = 1000;
    }

    int m_A;
    mutable int m_B; //�������,��ʹ�ڳ�������Ҳ�����޸����ֵ     ��Ա��������ʱ�ӹؼ���mutable��,�ڳ���������Ȼ�����޸�
};

void test01() {
    Person p;
    p.showPerson();
};

//������
void test02() {
    const Person p{}; //�ڶ���ǰ��const,��Ϊ������
    //p.m_A=100;    //�ᱨ��,�����޸�
    p.m_B = 110;      //mutable Ҳ�����޸�

    //������ֻ�ܵ��ó�����
    p.showPerson(); //���Ե��ó�����
    //p.func();     //�ᱨ��,��ͨ���������޸ı���,���ǳ��������޸�,��˲��ܵ���
}

int main() {


    system("pause");
    return 0;
}
