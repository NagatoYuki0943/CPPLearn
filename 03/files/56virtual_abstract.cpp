#include <iostream>

using namespace std;

/**
 * ���麯���ͳ�����
 * �ڶ�̬��,ͨ���������麯����ʵ���Ǻ��������,��Ҫ���ǵ���������д������,��˿��Խ��麯����Ϊ���麯��
 * ���麯���﷨ : virtual ����ֵ���� ������ (�����б�) = 0;
 * ���������˴��麯��,�����Ҳ�ɳ�����
 *      �������ص�:
 *          1.�޷�ʵ��������
 *          2.���������д�������еĴ��麯��,����Ҳ���ڳ�����
 */

class Base {
public:
    ///���麯��,ǰ�������virtual������ܵ���0
    ///���������˴��麯��,�����Ҳ�ɳ�����
    virtual void func() = 0;


    virtual ~Base() = 0;
};

class Son : public Base {
public:
    void func() override {
        cout << "func��������" << endl;
    }

    ~Son() override = default;
};

void test01() {
    //Base b1;  //����,�����಻��ʵ����
    //new Base; //����,�����಻��ʵ����
    Son s1;  //�����������д����Ĵ��麯��,����Ҳ�ǳ�����,Ҳ����ʵ����
    Base *pointer;    //����ָ���������
    pointer = new Son;
    pointer->func();
    delete pointer;
}

int main() {
    test01();
    system("pause");
    return 0;
}

