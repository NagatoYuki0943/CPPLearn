#include <iostream>

using namespace std;
/**
 * ð������
 * ����:ÿ�ζ��ӵ�һ����ʼ����,���ڵıȽϽ����ķŵ�����,ÿ�Ƚ�һ�����ľͷŵ����
 * ����,ÿ�ζ������һ����ʼ����,���ڵıȽϽ����ķŵ���ǰ��,ÿ�Ƚ�һ�����ľͷŵ�ǰ��
 */
//�������
void OutPut(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

//ð������
void func1(int *arr, int len) {  //��������ͷ��ָ�룬����ֱ�Ӵ����������֣���Ϊ�������־���ָ��
    //��������
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {     //�Ƚ�len-1��,���糤��Ϊ10,len-1=9,��0-8һ��9��
        //�ж����޽����ı�־
        bool flag = true;
        for (int j = 0; j < len - 1 - i; j++) { //jÿ�ζ��ӵ�һ����ʼ��,��С��len-1-I,��һ�α�9��,�ڶ��α�8��,�Դ�����
            if (arr[j] > arr[j + 1]) {         //����������Լ�С�ͽ���λ��
                flag = false;
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        //û�з���������˵���Ѿ��źã��˳�����
        if (flag) {
            break;
        }
        sum++;
    }
    cout << sum << "��" << endl;
    cout << "�������У�";
    OutPut(arr, len);

    //��������
    for (int i = 0; i < len - 1; i++) {      //�Ƚ�len-1��,���糤��Ϊ10,len-1=9,��0-8һ��9��
        //�ж����޽����ı�־
        bool flag = true;
        //������,������Եõ���һ��������
        for (int j = len - 1; j > i; j--) {  //jÿ�ζ������һ����ʼ��,��С��len-1-I,��һ�α�9��,�ڶ��α�8��,�Դ�����
            if (arr[j] > arr[j - 1]) {     //����ǰ����Լ�С�ͽ���λ��
                flag = false;
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        //û�з���������˵���Ѿ��źã��˳�����
        if (flag) {
            break;
        }
    }
    cout << "�������У�";
    OutPut(arr, len);
}

int main() {
    int arr[] = {0, 2, 5, 4, 8, 6, 9, 54, 1, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    func1(arr, len);   //����������һ��ָ��

    return 0;
}
