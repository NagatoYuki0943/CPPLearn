#include <iostream>

using namespace std;

/**
 *  ������(chong)��:������������ͬ,��߸�����
 *  ����:1.��ͬһ����������
 *      2.����������ͬ
 *      3.������ �������Ͳ�ͬ �� ����������ͬ �� ˳��ͬ
 *  ע��:�����ķ���ֵ������Ϊ�������ص�����,ֻ�з���ֵ���Ͳ�ͬ�����϶�Ϊ������ͬ�ĺ���
 */

void func() {
    cout << "�޲���func�ĵ���" << endl;
}

void func(int a) {
    cout << "int a func�ĵ���" << endl;
}

/*void func(const int a){   //��ͨ��������const���ᱻ��Ϊ������,ֻ�����ô��ݲſ���
    cout << "int a func�ĵ���" << endl;
}*/
void func(int a, string str) {
    cout << "int a,string str func�ĵ���" << endl;
}

void func(string str, int a) {
    cout << "int a,string str func�ĵ���" << endl;
}
//ע��:�����ķ���ֵ������Ϊ�������ص�����,ֻ�з���ֵ���Ͳ�ͬ�����϶�Ϊ������ͬ�ĺ���
/*int func(string str,int a){
    cout << "int a,string str func�ĵ���" << endl;
    return a;
}*/

int main() {
    int a = 0;
    string str;

    func();
    func(a);
    func(a, str);
    func(str, a);


    system("pause");
    return 0;
}
