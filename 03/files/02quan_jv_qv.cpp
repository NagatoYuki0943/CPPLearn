#include <iostream>

using namespace std;
#define A 10
//ȫ�ֱ���
int g_a = 10;
int g_b = 10;
//const���ε�ȫ�ֱ���,ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;


int main() {
    //ȫ����

    //ȫ�ֱ���,��̬����,����

    //������ͨ�ֲ�����,����ȫ����
    int a = 10;
    int b = 10;

    cout << "�ֲ�����a�ĵ�ַ��:\t" << (long long) &a << endl;  //6487580    (int)&aǿ��ת����10����,����clionҪʹ��long long
    cout << "�ֲ�����b�ĵ�ַ��:\t" << (long long) &b << endl;  //6487576

    //�ڴ��ַ��ͷλ�ò�ͬ,��ȫ����
    cout << "ȫ�ֱ���g_a�ĵ�ַ��:\t" << (long long) &g_a << endl;  //4206608
    cout << "ȫ�ֱ���g_b�ĵ�ַ��:\t" << (long long) &g_b << endl;  //4206612

    //��̬����,��ȫ����
    static int s_a = 10;
    static int s_b = 10;
    cout << "��̬����s_a�ĵ�ַ��:\t" << (long long) &s_a << endl;  //4206616
    cout << "��̬����s_b�ĵ�ַ��:\t" << (long long) &s_b << endl;  //4206620

    //����
    //�ַ�������  "hello world" ,��ȫ����
    cout << "�ַ��������ĵ�ַΪ:\t" << (long long) &"hello world" << endl;  //4210845

    //const���εı���
    //const���ε�ȫ�ֱ���,��ȫ����
    cout << "const���ε�ȫ�ֱ���c_g_a�ĵ�ַΪ:\t" << (long long) &c_g_a << endl;  //4210688
    cout << "const���ε�ȫ�ֱ���c_g_b�ĵ�ַΪ:\t" << (long long) &c_g_b << endl;  //4210692

    //const���εľֲ�����,����ȫ����
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "const���εľֲ�����c_l_a�ĵ�ַΪ:\t" << (long long) &c_l_a << endl;  //6487572
    cout << "const���εľֲ�����c_l_b�ĵ�ַΪ:\t" << (long long) &c_l_b << endl;  //6487568


    //#define A 10
    //cout << "define������A�ĵ�ַΪ:\t" << (long long)&A << endl;  //�ᱨ��

    system("pause");
    return 0;
}
