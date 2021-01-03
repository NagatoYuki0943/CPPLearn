#include <iostream>

using namespace std;

/**
 * �������캯������ʱ��
 *  1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
 *  2.ֵ���ݵķ�ʽ������������ֵ
 *  3.��ֵ��ʽ���ؾֲ�����
 */
class Person {
public:
    //�޲ι���
    Person() {
        cout << "Person(){}�޲ι��캯������" << endl;
    }

    //�вι���
    Person(int age) {
        m_Age = age;
        cout << "Person(){}�вι��캯������" << endl;
    }

    //��������
    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "Person(){}�������캯������" << endl;
    }

    //��������
    ~Person() {
        cout << "~Person(){}������������" << endl;
    }

    int m_Age;
};

//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {
    Person p1(20);
    Person p2(p1);
    cout << "p2������:" << p2.m_Age << endl;
}

//2.ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p) {  //ֵ����

}

void test02() {
    Person p; //�޲ι���
    doWork(p);//���ÿ������캯��,ʵ�δ����βε�ʱ����ÿ�������
}

//3.��ֵ��ʽ���ؾֲ�����
Person doWork2() {
    Person p1;
    cout << (long long) &p1 << endl;
    return p1;  //Ӧ�÷��ص���ֵ,�´��p1������ֵ,����clion��������ַ��ͬ
}

void test03() {
    Person p = doWork2();
    cout << (long long) &p << endl;
}


int main() {
    //test01();
    //test02();
    test03();


    system("pause");
    return 0;
}
