#include <iostream>

using namespace std;

/**
 *c++���������ٸ�һ�������4������
 *  1.Ĭ�Ϲ��캯��(�޲�,������Ϊ��)
 *  2.Ĭ����������(�޲�,������Ϊ��)
 *  3.Ĭ�Ͽ������캯��,������ֵ���п���
 *  4.��ֵ����� operator=,�����Խ���ֵ����   = �Ǹ�ֵ,���ǿ���
 *
 *  ������Ĭ���ṩ�� = ��ֵ��ǳ����,��������������ڶ���,�������,Ҫ�������
 *  �������������ָ�����,����ֵ����ʱҲ�������ǳ��������
 *
 *  ע��:����ʹ��ȫ�ֺ���,operator=�����ǷǾ�̬����,ȫ�����Ǿ�̬��  =ֻ��ʹ�ó�Ա����
 */
class Person {
public:
    Person(int age) {
        m_Age = new int(age);//���ٵ�����
    }

    int *m_Age;

    ~Person() {
        if (m_Age != NULL)
            delete m_Age;
        m_Age = NULL;
    }

    //���ظ�ֵ�����
    //Ҫ��������,��Ȼ���صĲ����Լ��Ķ���
    Person &operator=(Person &p) {  //ע�����ô�ֵ,��Ȼp1��ֵ�������
        //�������ṩǳ����,����
        //m_Age=p.m_Age;
        ///Ӧ�����ж��Ƿ��������ڶ���,�����,���ͷŸɾ�,Ȼ�������
        if (m_Age != NULL) {   //��������Լ���,�� �Ⱥ���ߵĶ���
            delete m_Age;
            m_Age = NULL;
        }
        //���
        m_Age = new int(*p.m_Age);
        return *this; //�����Լ��Ķ���
    }
};

//����ʹ��ȫ�ֺ���,operator=�����ǷǾ�̬����,ȫ�����Ǿ�̬��
//Person& operator=(Person &p1, Person &p2){ }


void test01() {
    Person p1(18);
    Person p2(20);
    Person p3(30);
    //p2=p1;  //Ĭ��ǳ����,�ᵼ��p2������Ҳ��18,Ҫ�޸ĳ����
    p3 = p2 = p1; ///Ĭ�ϱ���,��ΪoperatorĬ���޷���ֵ,����ֵ��Person&,Ҫ�����ò�û��
    cout << "p1������:" << *p1.m_Age << endl; //������,m_Age��ָ��
    cout << "p2������:" << *p2.m_Age << endl; //������,m_Age��ָ��
    cout << "p3������:" << *p3.m_Age << endl; //������,m_Age��ָ��

}

int main() {
    test01();
    int a = 10, b = 20, c = 30;
    c = b = a;
    cout << "a=" << a << endl; //10
    cout << "b=" << b << endl; //b=a=10
    cout << "c=" << c << endl; //c=b=10

    system("pause");
    return 0;
}