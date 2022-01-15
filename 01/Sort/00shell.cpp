#include <iostream>

using namespace std;

/**
 * 希尔排序，先将待排序列进行预排序，使待排序列接近有序，然后再对该序列进行一次插入排序，此时插入排序的时间复杂度为O(N)，
 * 时间复杂度平均：O(N^1.3)
 * 空间复杂度：O(1)
 */
void shellSort(int* arr, int len)
{
    int gap = len;
    while (gap>1){
        //每次对gap折半操作
        gap = gap / 2;
        //单趟排序
        for (int i = 0; i < len - gap; i++){
            int end = i;
            int tmp = arr[end + gap];
            while (end >= 0){
                if (tmp < arr[end]){
                    arr[end + gap] = arr[end];
                    end -= gap;
                }
                else{
                    break;
                }
            }
            arr[end + gap] = tmp;
        }
    }
}

int main(){
    int arr[] = {5, 3, 6, 7, 3, 2, 7, 9, 8, 6, 34, 32, 5, 4, 43, 12, 37};
    int length = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, length);

    for(int i: arr){
        cout << i << " ";
    }
    //2 3 3 4 5 5 6 6 7 7 8 9 12 32 34 37 43
    cout << endl;
}