#include <iostream>
#include <string>

using namespace std;

/**
 * ��Ա��������Ϊ˽��
 * �ô�:
 *      1.�����Լ����ƶ�дȨ��
 *      2.����д,���Լ�����ݵ���Ч��,����ʹ���ж������п��Ƹ�ֵ
 */
class Person {
    //���� �ɶ���д
    string m_Name;
    //���� �ɶ���д
    int m_Age = 10;
    //���� ֻд
    string m_Lover;
public:
    //���������ɶ���д
    void setName(string name) {
        m_Name = name;
    }

    string getName() {
        return m_Name;
    }

    //���� ���� 0-150
    void setAge(int age) {
        if (age < 0 || age > 150) {
            cout << "����������û����" << endl;
            return;
        }
        m_Age = age;
    }

    //���� ��ȡ
    int getAge() {
        return m_Age;
    }

    //���� ֻд
    void setLover(string Lover) {
        m_Lover = Lover;
    }
};

int main() {
    Person p1;
    //����
    p1.setName("С��");
    cout << "������" << p1.getName() << endl;
    //����,����ֱ�Ӹ���,��private
    p1.setAge(110);
    cout << "������" << p1.getAge() << endl;
    //����
    p1.setLover("�־�");


    system("pause");
    return 0;
}
