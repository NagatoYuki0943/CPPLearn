#include <iostream>
#include <string>

using namespace std;
/**
 * C++���е����Ժ���Ϊ ͳ��Ϊ��Ա
 * ����:��Ա���� ��Ա����
 * ��Ϊ:��Ա���� ��Ա����
 * C#��������,�������¼�
 * PHP��������,�����ͳ���(����ֻ���������)
 */

//���һ��ѧ����,������������ѧ��,���Ը�������ѧ�Ÿ�ֵ,������ʾѧ����������ѧ��
class student {
public://����Ȩ��
    int s_id;
    string s_name;

    //��id������ֵ
    void setid_name(int id, string name) {
        s_id = id;
        s_name = name;
    }

    //���
    void showStudent() {
        cout << "ѧ��ID��:" << s_id << " ������:" << s_name << endl;
    }
};

int main() {
    //��������ѧ��
    student xiaoming;
    xiaoming.setid_name(5, "С��");
    xiaoming.showStudent();

    system("pause");
    return 0;
}
