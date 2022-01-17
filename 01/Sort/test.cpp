#include <iostream>
#include <stack>
#include <functional>
using namespace std;


void printArr(int arr[], int len){
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;
}


void chooseSort(int arr[], int len){
    for (int i = 0; i < len-1; ++i) {
        int min = i;
        for (int j = i+1; j < len; ++j) {
            //升序,降序在于 > <
            if(arr[min] > arr[j]){      //大于号
                min = j;
            }
        }
        if (min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}


void insertSort(int arr[], int len){
    for (int i = 1; i < len; ++i) {
        int temp = arr[i];           //取出值,不是下标
        bool flag = false;
        int j = i-1;
        for (; j >= 0; --j) {
            //升序,降序在于 > <
            if (temp < arr[j]){      //注意这里的temp
                flag= true;
                arr[j+1] = arr[j];
            }else{
                break;               //不要忘了break
            }
        }
        if (flag)
            arr[j+1] = temp;
    }
}


void bubbleSort(int arr[], int len){
    for (int i = 0; i < len - 1; ++i) {
        bool flag = true;       //排好了
        for (int j = 0; j < len-1-i; ++j) {
            //升序,降序在于 > <
            if (arr[j] > arr[j+1]){
                flag = false;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (flag)
            break;
    }
}


/**
 * 列表逆序,放入栈中
 */
void reverseList(){
    int arr[] = {1, 2, 3, 4, 5};
    stack<int> s;
    for(int i: arr){
        s.push(i);
    }
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main(){
    int arr[] = {10,5,9,1,3,5,7,-10};
    int len = sizeof (arr) / sizeof (int);
    chooseSort(arr, len);
    printArr(arr, len);

    int arr1[] = {10,5,9,1,3,5,7,-10};
    len = sizeof (arr1) / sizeof (int);
    insertSort(arr1, len);
    printArr(arr1, len);


    int arr2[] = {10,5,9,1,3,5,7,-10};
    len = sizeof (arr2) / sizeof (int);
    bubbleSort(arr2, len);
    printArr(arr2, len);

    reverseList();
    return 0;
}