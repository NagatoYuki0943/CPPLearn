#include <iostream>

using namespace std;

/**
 * ��������++�����,ʵ���Լ�����������
 * <<���ص����������ֵ,����������
 * ǰ�õ�����������,���õ�������ֵ
 * ֧�ֳ�Ա������ȫ�ֺ���д��
 */
class MyInteger {
    //ʹ����Ԫȫ�ֺ���
    friend ostream &operator<<(ostream &cout, MyInteger m);

public:
    MyInteger() {
        m_Num = 0;
    }

    ///����ǰ�õ���++�����
    MyInteger &operator++() { //����Ҫ����,������MyInteger&,������Ϊ��һֱ��һ�����������
        //�Ƚ���++����,�ڷ���
        m_Num++;
        return *this;  //��������
    }

    ///���غ��õ���++�����
    //MyInteger operator++(){   //ֱ������д�ᱨ��,����Ϊ������ĺ����ظ���
    MyInteger operator++(int) {  ///����д��int,��������֪�����Ǻ��õ���,int����ռλ����,������������ǰ�úͺ���
        //���õ������ص���ֵ,��������,�������õĻ��᷵�ؾֲ�object tmp
        //�ȼ�¼��ʱ���
        MyInteger tmp = *this;
        //�����
        m_Num++;
        //��󽫼�¼�������
        return tmp;
    }

private:
    int m_Num;
};

//ȫ�ֺ�������
ostream &operator<<(ostream &cout, MyInteger m) { //�����m��Ҫ����,��Ȼ�����Ҳ����ֲ�
    cout << m.m_Num;
    return cout;
}

void test01() {
    MyInteger myint;
    cout << ++(++myint) << endl; //2
    cout << myint << endl;       //2
}

void test02() {
    MyInteger myint;
    cout << myint++ << endl;  //0
    cout << myint << endl;    //1
}

int main() {
    test01();
    //test02();

    system("pause");
    return 0;
}
