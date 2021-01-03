#include <iostream>

using namespace std;
/**
 *��������ע�⣬������һ��Ԫ�ر���ǰ��һ��Ԫ��С����������Ԫ�ؽ���λ�ã�Ȼ�������Ƚ��������Ԫ����ǰ��һ��Ԫ�صĴ�С��
 *��С������Ҫ����������Ԫ��λ�ã�һֱ���������Ԫ������ȷ��λ��Ϊֹ
 */
//��������
void UpInsertSort(int arr[], int len) {
    //1��ȷ��������ٻأ�����һ������һ���Բ��뵽�Ե�λ�ã�ͬʱ��һ��λ�ü����ǶԵ�
    for (int i = 1; i < len; i++)  //i�ӵ�һ����ʼ,�����һ��
    {
        //��ȡ��ֵ
        int temp = arr[i];
        //�ж����޽���������
        bool flag = false;
        //��i��ʼ,��������Ƚ�,ֱ�������
        int j = i - 1;  //Ҫ�����渳ֵ,��Ȼ�����޷�����
        for (; j >= 0; j--)  //j��i-1��ʼ,�����ҵ���0��
        {
            if (arr[j] > temp) {
                //���ݺ���
                arr[j + 1] = arr[j];

                //˵����ǰλ���н���
                flag = true;
            } else {
                //˵����ǰ�ڶԵ�λ��,ǰ��Ķ���tempС
                break;
            }
        }
        if (flag) {
            arr[j + 1] = temp; //j������֮���-1,��Ҫ������ǰһ��λ��, ����Ҫ+1
        }
    }
}

//��������
void DownInsertSort(int arr[], int len) {
    //1��ȷ��������ٻأ�����һ������һ���Բ��뵽�Ե�λ�ã�ͬʱ��һ��λ�ü����ǶԵ�
    for (int i = 1; i < len; i++)  //i�ӵ�һ����ʼ,�����һ��
    {
        //��ȡ��ֵ
        int temp = arr[i];
        //�ж����޽���������
        bool flag = false;
        //��i��ʼ,��������Ƚ�,ֱ�������
        int j = i - 1;  //Ҫ�����渳ֵ,��Ȼ�����޷�����
        for (; j >= 0; j--)  //j��i-1��ʼ,�����ҵ���0��
        {
            if (temp > arr[j]) {
                //���ݺ���
                arr[j + 1] = arr[j];

                //˵����ǰλ���н���
                flag = true;
            } else {
                //˵����ǰ�ڶԵ�λ��,ǰ��Ķ���tempС
                break;
            }
        }
        if (flag) {
            arr[j + 1] = temp; //j������֮���-1,��Ҫ������ǰһ��λ��, ����Ҫ+1
        }
    }
}

void OutPut(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 1, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    OutPut(arr, len);
    //������������
    UpInsertSort(arr, len);
    OutPut(arr, len);

    //���ý�������
    DownInsertSort(arr, len);
    OutPut(arr, len);

}
