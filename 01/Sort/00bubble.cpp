#include <iostream>

using namespace std;
/**
 * 冒泡排序
 * 升序:每次都从第一个开始排序,相邻的比较将最大的放到最后边,每比较一次最大的就放到后边
 * 降序,每次都从最后一个开始排序,相邻的比较将最大的放到最前边,每比较一次最大的就放到前边
 */
//输出函数
void OutPut(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

//冒泡排序
void func1(int *arr, int len) {  //传入数组头的指针，可以直接传入数组名字，因为数组名字就是指针
    //升序排列
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {     //比较len-1次,比如长度为10,len-1=9,从0-8一共9次
        //判断有无交换的标志
        bool flag = true;
        for (int j = 0; j < len - 1 - i; j++) { //j每次都从第一个开始比,到小于len-1-I,第一次比9次,第二次比8次,以此类推
            if (arr[j] > arr[j + 1]) {         //遇到后面比自己小就交换位置
                flag = false;
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        //没有发生交换，说明已经排好，退出排序
        if (flag) {
            break;
        }
        sum++;
    }
    cout << sum << "次" << endl;
    cout << "升序排列：";
    OutPut(arr, len);

    //降序排列
    for (int i = 0; i < len - 1; i++) {      //比较len-1次,比如长度为10,len-1=9,从0-8一共9次
        //判断有无交换的标志
        bool flag = true;
        //倒着排,降序可以得到第一个是最大的
        for (int j = len - 1; j > i; j--) {  //j每次都从最后一个开始比,到小于len-1-I,第一次比9次,第二次比8次,以此类推
            if (arr[j] > arr[j - 1]) {     //遇到前面比自己小就交换位置
                flag = false;
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        //没有发生交换，说明已经排好，退出排序
        if (flag) {
            break;
        }
    }
    cout << "降序排列：";
    OutPut(arr, len);
}

int main() {
    int arr[] = {0, 2, 5, 4, 8, 6, 9, 54, 1, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    func1(arr, len);   //数组名字是一个指针

    return 0;
}
