#include <iostream>

using namespace std;

int main() {
    /**
     * ����,�����������,�����ڴ�λ��һ��
     * int &����=ԭ��
     * ע��:���ñ����ʼ��,��ʼ��֮��Ͳ��ܱ���
     */

    int a = 10, d = 20;
    int &b = a;
    //int &b=10; //����,���ñ������úϷ����ڴ�ռ�
    //int &c;    //����,�����ʼ��
    b = d;  //�������,������b=d��ֵ20
    //int &b=d;  //����,�����ٸ������ö���

    cout << a << endl;  //20
    cout << b << endl;  //20
    b = 100;
    cout << a << endl;  //100
    cout << b << endl;  //100


    system("pause");
    return 0;
}
