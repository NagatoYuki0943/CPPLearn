#include <iostream>

using namespace std;
/**
 * ���ÿ�����Ϊ���������޸�ʵ��,��ָ����ͬ
 */
//1.ֵ����
void mySwap01(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//2.��ַ����
void mySwap02(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//3.���ô���
void mySwap03(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 10, b = 20;
    mySwap01(a, b);   //ֵ����
    cout << "a=" << a << " b=" << b << endl;  //10 20 û�з����ı�
    mySwap02(&a, &b); //��ַ����
    cout << "a=" << a << " b=" << b << endl;  //20 10 �����ı�
    mySwap03(a, b); //���ô���
    cout << "a=" << a << " b=" << b << endl;  //10 20 �����ı�,������Ļ�����


    system("pause");
    return 0;
}
