#include <iostream>

using namespace std;
/**
 * ����:�ɳ���Ա�����ͷ�,�������Ա���ͷ�,�������ʱ�в���ϵͳ����
 * ʹ�� new �ڶ��������ڴ�           new���ص��Ǹ����͵�ָ��,��ָ����
 * ʹ��delete ɾ��ָ���ɾ������������
 * ɾ����ͨ����:delete p;  ɾ������:delete[] arr;
 */
/**
 * ��ջ��������ά����
 * Worker **��ָ��Worker*��ָ��,������**ָ��
 * Worker ** newSpace=new Worker* [newSize];
 */
int *func() {
    //����new�ؼ��ֿ��Խ����ݿ��ٵ�����
    //new���ص��Ǹ����͵�ָ��,��ָ����
    //ָ�뱾��Ҳ�Ǿֲ�����,�����ջ��,ָ�뱣��������Ƿ��ڶ���
    int *p = new int(10); //int(10) int����,��ֵΪ10
    return p;
}

void test01() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    //�����������ɳ���Ա�����ͷ�
    //�ͷ�ʹ��delete p �ͷŵ�ַ
    delete p;
    cout << *p << endl;   //7493760,�����,��Ϊdelete�Ѿ��ͷ���p
}

void test02() {
    int *arr = new int[10];//��������Ϊ10������
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;     //����ͨ������������һ��
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //�ͷ�����,
    delete[] arr;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    /*int *p=func();
    cout << (long long)p << endl; //������ַ
    cout << *p << endl;
    cout << *p << endl;   //������Ҳ����,������ջ��һ��������
    cout << *p << endl;*/

    //test01();
    test02();


    system("pause");
    return 0;
}
