#include <iostream>

using namespace std;

/**
 * c++�п�ָ��Ҳ�ǿ��Ե��ó�Ա������,����ҲҪע����û���õ�thisָ��
 * д��:  Person *p=NUll;
 * ����õ�thisָ��,��Ҫ�����жϱ�֤���뽡׳��
 */

class Person {
public:
    void showClassName() {
        cout << "this is Person class" << endl;  //ֻ����ַ�������
    }

    void showPersonAge() {
        //����ԭ���Ǵ����ָ����NULL
        //��������жϾͿ����ų�������,Ϊ�վͲ�����
        if (this == NULL) {
            return;
        }
        cout << "age=" << m_Age << endl;        //����˵�ǰ�����еı���
    }

    int m_Age;
};

void test01() {
    Person *p = NULL;       //û��ȷ�еĶ���
    p->showClassName();   //������Է���
    p->showPersonAge();   //���Ĭ�ϲ��ܷ���
}


int main() {
    test01();

    system("pause");
    return 0;
}
