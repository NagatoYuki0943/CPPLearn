#include <iostream>

using namespace std;

/**
 * ��̬��Ա�ͷǾ�̬��Ա����ͬ��,����ʽһ��
 * ��̬��Ա:��̬����:���ж�����ͬһ������;��������,�����ʼ��;����׶η����ڴ�
 *        ��̬��Ա����:���ж�����ͬһ������;���ʾ�̬��Ա����
 *      ��������ͬ����Ա,ֱ�ӷ��ʼ���
 *      ���ʸ����Ա,��Ҫ��������
 *
 *  s.m_A        === Son::m_A        s.func()       == Son::func()         //����
 *  s.Base::m_A  === Son::Base::m_A  s.Base::func() == Son::Base::func()   //����
 *                   ǰһ��::��ͨ������Son��ʽ����,�ڶ���::�Ƿ���Sase�������µ�m_A
 *
 *  ע��:��������г��ֺ͸���ͬ���ĺ�����Ա����,�����ͬ����Ա�����ص����������е�ͬ������(���غ���Ҳ�ᱻӰ��)
 *      Ҫ��Base::��ʽ���ʸ����е����غ���
 */
class Base {
public:
    static int m_A;

    static void func() {
        cout << "Base--static void func()" << endl;
    }

    static void func(int a) {
        cout << "Base--static void func(int a)" << endl;
    }
};

//�����ʼ��
int Base::m_A = 100;

class Son : public Base {
public:
    static int m_A;

    static void func() {
        cout << "Son--static void func()" << endl;
    }

    static void func(int a) {
        cout << "Son--static void func(int a)" << endl;
    }
};

//�����ʼ��
int Son::m_A = 200;


///ͬ����̬��Ա����
void test01() {
    Son s;
    //ͨ���������
    cout << "Son��:\t" << s.m_A << endl;           //200
    cout << "Base��:\t" << s.Base::m_A << endl;    //100
    //ͨ����������
    cout << "Son��:\t" << Son::m_A << endl;        //200
    cout << "Base��:\t" << Son::Base::m_A << endl; //100  ǰһ��::��ͨ������Son��ʽ����,�ڶ���::�Ƿ���Sase�������µ�m_A

}

//ͬ����̬����
void test02() {
    Son s;
    //ͨ���������
    s.func();
    s.Base::func();
    s.Base::func(5);      //���ʸ������غ���
    //ͨ����������
    Son::func();
    Son::Base::func();
    Son::Base::func(5);   //���ʸ������غ���
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}