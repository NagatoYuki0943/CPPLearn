#include <iostream>

using namespace std;

/**
 * ����Ĭ�ϲ���
 * ������Ǵ������,���ô����,�����������Ĭ��ֵ
 */

/** ע������:
 * 1.���ĳ��λ���Ѿ�����Ĭ�ϲ���,name�����λ������,�����ұ�����Ĭ��ֵ
 */
/*int func1(int a,int b=10,int c){   //cû��Ĭ��ֵ�ͻᱨ��

} */

/**
 * 2.�������������Ĭ�ϲ���,����ʵ�־Ͳ�����Ĭ�ϲ���
 * ������ʵ�ֶ���ͬһ������ֻ����һ��Ĭ�ϲ���
 */
//����
int func2(int a, int b = 2);

//ʵ��
int func2(int a = 2, int b) {   //ʵ�ָ���Ĭ�ϲ����ᱨ��,�������a������ʱ����,ʵ�ֵ�ʱ������ǿ��Ե�
    return a + b;
}


int func(int a, int b = 10, int c = 20) {
    return a + b + c;
}

int main() {
    int a = 10;
    cout << func(a) << endl;  //40

    func2();
    system("pause");
    return 0;
}
