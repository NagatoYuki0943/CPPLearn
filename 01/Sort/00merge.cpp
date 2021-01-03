#include <iostream>

using namespace std;
/**
 * merge
 * �鲢�㷨
 * ��������������кϲ����õ���ȫ��������У�����ʹÿ��������������ʹ�����жμ������������������ϲ���һ���������Ϊ��·�鲢��
 * �鲢������Ҫ��Ϊ������һ�Ƕ�����Ļ��֣����Ƕ�������������Ƕ�����ĺϲ�
 */

///�ϲ��㷨
void merge(int *arr, int start, int end, int *result) {
    int left_length = (end - start + 1) / 2 + 1;
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while (left_index < start + left_length && right_index < end + 1)  //store arr into new array
    {
        if (arr[left_index] <= arr[right_index])
            result[result_index++] = arr[left_index++];
        else
            result[result_index++] = arr[right_index++];
    }
    while (left_index < start + left_length)
        result[result_index++] = arr[left_index++];
    while (right_index < end + 1)
        result[result_index++] = arr[right_index++];
}

///�ָ�����
void merge_sort(int *arr, int start, int end, int *result) {
    if (1 == end - start)   //ֻ��������
    {
        if (arr[start] > arr[end]) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        return;
    } else if (end == start)  //ֻʣ��һ����
        return;
    else {
        //���������������зָֱ�������ڶ�λ��
        merge_sort(arr, start, (end - start + 1) / 2 + start, result);
        merge_sort(arr, (end - start + 1) / 2 + start + 1, end, result);
        //�ϲ��㷨
        merge(arr, start, end, result);

        //��ԭ���������ʱ����
        for (int i = start; i <= end; ++i) {
            arr[i] = result[i];
        }
    }
}

int main() {
    int arr[] = {5, 3, 6, 7, 3, 2, 7, 9, 8, 6, 34, 32, 5, 4, 43, 12, 37};
    int length = sizeof(arr) / sizeof(arr[0]);
    int result[length];
    cout << "before sorted:" << '\n';
    for (int i = 0; i < length; i++)
        cout << arr[i] << ' ';
    cout << '\n'
         << "after sorted:" << '\n';
    merge_sort(arr, 0, length - 1, result);
    for (int i = 0; i < length; i++)
        cout << result[i] << ' ';
    return 0;
}

