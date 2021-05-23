#include <iostream>

using namespace std;
/**
 * ��������ͬ����Ա,ֱ�ӷ��ʼ���
 * ���ʸ���ͬ����Ա,��Ҫ��������
 *      class Son
 *      class Son : public Base
 *      ͨ�����������ʸ�����ͬ����Ա����  s1.Base::m_A
 *      ͨ�����������ø���ͬ������       s2.Base::func();
 *      ���ø����е����غ���              s2.Base::func(10);
 *   ��������г��ֺ͸���ͬ���ĺ�����Ա����,�����ͬ����Ա�����ص����������е�ͬ������(���غ���Ҳ�ᱻӰ��)
 *   Ҫ��Base::��ʽ���ʸ����е����غ���
 */

/**
 * ע��
 * (1)  PHPû��ͬ������,�����������ͬ������������д,C++��C#����ͬ��������������,ʹ����virtual��abstract������д
 *      PHP���෽����д���෽�����ܱȸ�����ϸ�,�����෽�������public,���෽��������public;���෽�������protected,���෽������ʹpublic��protected
 *      C++��û����������
 *      C#ʹ��virtual/abstract��override��дʱ�����޸ķ������η�
 *
 * (2)  PHP7Ҫ����д�ķ��������븸�ౣ�ֲ���һ��(����������)
 *      C++��û����������
 *      C#ʹ��virtual/abstract��override��дʱҲҪ����һ��(����������),������д��û����
 *      C#ʹ�ø��ǲ�����д,(�����޲���,�����в���)�����������ø��෽��,�������������෽��
 *
 *  phpʹ�� parent::���෽��() ���ø��෽��,���۾�̬,��̬��ʹ��parent::
 */

class Base {
public:
    Base() {
        m_A = 100;
    }

    void func() {
        cout << "Base - func()����" << endl;
    }

    //������������
    void func(int a) {
        cout << "Base - func(int a)����" << endl;
    }

    int m_A;
};

class Son : public Base {
public:
    Son() {
        m_A = 200;
    }

    void func() {
        cout << "Son - func()����" << endl;
    }

    int m_A;
};

//ͬ����Ա���Դ���ʽ
void test01() {
    Son s1;
    cout << "m_A=" << s1.m_A << endl;         //Ĭ�ϴ�ӡ�������������
    cout << "Son-m_A=" << s1.Base::m_A << endl;//����������  s1.Base::m_A
}

//ͬ����Ա������������ʽ
void test02() {
    Son s2;
    s2.func();           //Ĭ�ϵ������ຯ��
    s2.Base::func();     //ʹ�ø�����������ø���func()
    ///��������г��ֺ͸���ͬ���ĺ�����Ա����,�����ͬ����Ա�����ص����������е�ͬ������(���غ���Ҳ�ᱻ����)
    ///Ҫ��Base::��ʽ���ʸ����е����غ���
    s2.Base::func(10);
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}



