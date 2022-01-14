#include <iostream>

using namespace std;
/**
 * merge
 * 归并算法
 * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
 * 归并排序主要分为三步，一是对数组的划分，二是对数组的排序，三是对数组的合并
 *
 * 时间复杂度约为 O(N)
 */

/**
 * 合并算法
 * @param arr
 * @param start 0
 * @param end   len-1
 * @param result
 */
void merge(int arr[], int start, int end, int *result) {
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

/**
 * 分割排序
 * @param arr
 * @param start 0
 * @param end   len-1
 * @param result
 */
void mergeSort(int arr[], int start, int end, int *result) {
    if (1 == end - start)   //只有两个数
    {
        if (arr[start] > arr[end]) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        return;
    } else if (end == start)  //只剩下一个数
        return;
    else {
        //多余两个数，进行分割，直到不大于二位置
        mergeSort(arr, start, (end - start + 1) / 2 + start, result);
        mergeSort(arr, (end - start + 1) / 2 + start + 1, end, result);
        //合并算法
        merge(arr, start, end, result);

        //让原数组等于临时数组
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
    mergeSort(arr, 0, length - 1, result);
    for (int i = 0; i < length; i++)
        cout << result[i] << ' ';
    return 0;
}

