#include <iostream>

using namespace std;
/**
 *插入排序。注意，若后面一个元素比其前面一个元素小，则将这两个元素交换位置，然后再来比较这个插入元素与前面一个元素的大小，
 *若小，则还需要交换这两个元素位置，一直到这个插入元素在正确的位置为止
 */
//升序排序
void UpInsertSort(int arr[], int len) {
    //1，确定插入多少回，假设一个数字一次性插入到对的位置，同时第一个位置假设是对的
    for (int i = 1; i < len; i++)  //i从第一个开始,到最后一个
    {
        //获取初值
        int temp = arr[i];
        //判断有无交换的条件
        bool flag = false;
        //从i开始,从右往左比较,直到最左侧
        int j = i - 1;  //要从外面赋值,不然下面无法交换
        for (; j >= 0; j--)  //j从i-1开始,往左找到第0个
        {
            if (arr[j] > temp) {
                //数据后移
                arr[j + 1] = arr[j];

                //说明当前位置有交换
                flag = true;
            } else {
                //说明当前在对的位置,前面的都比temp小
                break;
            }
        }
        if (flag) {
            arr[j + 1] = temp; //j运行完之后会-1,到要交换的前一个位置, 所以要+1
        }
    }
}

//降序排序
void DownInsertSort(int arr[], int len) {
    //1，确定插入多少回，假设一个数字一次性插入到对的位置，同时第一个位置假设是对的
    for (int i = 1; i < len; i++)  //i从第一个开始,到最后一个
    {
        //获取初值
        int temp = arr[i];
        //判断有无交换的条件
        bool flag = false;
        //从i开始,从右往左比较,直到最左侧
        int j = i - 1;  //要从外面赋值,不然下面无法交换
        for (; j >= 0; j--)  //j从i-1开始,往左找到第0个
        {
            if (temp > arr[j]) {
                //数据后移
                arr[j + 1] = arr[j];

                //说明当前位置有交换
                flag = true;
            } else {
                //说明当前在对的位置,前面的都比temp小
                break;
            }
        }
        if (flag) {
            arr[j + 1] = temp; //j运行完之后会-1,到要交换的前一个位置, 所以要+1
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
    //调用升序排序
    UpInsertSort(arr, len);
    OutPut(arr, len);

    //调用降序排序
    DownInsertSort(arr, len);
    OutPut(arr, len);

}
