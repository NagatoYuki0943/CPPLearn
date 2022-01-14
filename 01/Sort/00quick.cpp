#include <iostream>

using namespace std;
/**
 * 快速排序,假定第一个值为中间值,先从右往左找一个比它小的,再从左边找一个比它大的数,交换两者位置,最后i==j,用中间值和i的值交换
 * 时间复杂度: N*log(N/2)
 */
/**
 * 升序排列
 * @param left  0
 * @param right len-1
 * @param arr
 */
void upQuickSort(int left, int right, int arr[]) {
    //左边为第一个，就从右往左找
    if (left >= right) {
        return;
    }
    int i, j, base, tmp;
    i = left;
    j = right;
    base = arr[left]; //取最左边的数为基准
    while (i < j) {
        ///i和j最后会相等
        //找到从右侧数第一个小于base的数
        while (arr[j] >= base && i < j) {  //找到之后才会退出循环
            j--;
        }
        //找到从左侧数第一个大于base的数
        while (arr[i] <= base && i < j) { //找到之后才会退出循环
            i++;
        }
        //交换左右两侧不同的数
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    //基准数归位,最终i的位置的值和开始基准位置的值交换位置
    arr[left] = arr[i];
    arr[i] = base;
    upQuickSort(left, i - 1, arr); //左边递归
    upQuickSort(i + 1, right, arr); //递归右边
}

/**
 * 降序排列
 * @param left  0
 * @param right len-1
 * @param arr
 */
void downQuickSort(int left, int right, int arr[]) {

    //左边为第一个，就从右往左找
    if (left >= right) {
        return;
    }
    int i, j, base, tmp;
    i = left;
    j = right;
    base = arr[left]; //取最左边的数为基准
    while (i < j) {
        ///i和j最后会相等
        //找到从右侧数第一个大于base的数
        while (arr[j] <= base && i < j) { //找到之后才会退出循环
            j--;
        }
        //找到从左侧数第一个小于base的数
        while (arr[i] >= base && i < j) { //找到之后才会退出循环
            i++;
        }
        //交换左右两侧不同的数
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    //基准数归位,最终i的位置的值和开始基准位置的值交换位置
    arr[left] = arr[i];
    arr[i] = base;
    downQuickSort(left, i - 1, arr); //左边递归
    downQuickSort(i + 1, right, arr); //递归右边
}

void OutPut(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 5, 3, 6, 8, 4, 5, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << len << endl;
    OutPut(arr, len);

    //升序排列
    upQuickSort(0, len - 1, arr);
    OutPut(arr, len);

    //降序排列
    downQuickSort(0, len - 1, arr);
    OutPut(arr, len);
    return 0;
}

