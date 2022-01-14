#include <iostream>

using namespace std;
/**
 * 选择排序
 * 时间复杂度：最坏情况：O(N^2)
 *            最好情况：O(N^2)
 * 空间复杂度：O(1)
 */

/**
 *先认为第一个是最小的或者最大的,从下一个开始找,如果找到比第一个小的或者大的,交换两者位置
 */

//输出
void OutPut(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//升序
void upSelectSort(int a[], int len) {
    cout << "升序排列" << endl;
    int min;
    for (int i = 0; i < len - 1; i++) {   // i从0开始,到小于len-1结束
        min = i;
        for (int j = i + 1; j < len; j++) { //j从i+1开始,到len-1结束
            if (a[min] > a[j]) {        //和降序唯一的区别
                min = j;
            }
        }
        if (min != i) {
            int tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }
}

//降序
void downSelectSort(int a[], int len) {
    cout << "降序排列" << endl;
    int max;
    for (int i = 0; i < len - 1; i++) {    // i从0开始,到小于len-1结束
        max = i;
        for (int j = i + 1; j < len; j++) {  //j从i+1开始,到len-1结束
            if (a[max] < a[j]) {         //和升序唯一的区别
                max = j;
            }
        }
        if (max != i) {
            int tmp = a[max];
            a[max] = a[i];
            a[i] = tmp;
        }
    }
}

int main() {
    int arr[] = {9, 8, 3, 2, 1, 7, 0, 6, 5, 4, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    OutPut(arr, len);
    upSelectSort(arr, len);
    OutPut(arr, len);
    downSelectSort(arr, len);
    OutPut(arr, len);
    //OutPut(a);
    return 0;
}
