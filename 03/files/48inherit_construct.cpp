#include <iostream>

using namespace std;

/**
 * ���๹��Ҳ�ṹ������
 * �̳��й��������˳��
 * �ȸ��๹��,�����๹��  ���и���,��������
 * ����������,��������  �Ȼ�����,�ٻٸ���
 *
 */
class Base {
public:
    Base() {
        cout << "Base���캯��" << endl;
    }

    ~Base() {
        cout << "Base��������" << endl;
    }
};

class Son : public Base {
public:
    Son() {
        cout << "Son���캯��" << endl;
    }

    ~Son() {
        cout << "Son��������" << endl;
    }
};

void test01() {
    Son son01;
}

int main() {
    test01();
    system("pause");
    return 0;
}