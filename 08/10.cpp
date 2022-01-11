#include <iostream>

using namespace std;



template<typename T>
void swap1(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T1, typename T2>
void chooseSort(T1 arr[], int len, T2 t2){
    int c;
    for (int i = 0; i < len-1; ++i) {
        c = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[c] < arr[j]) {
                c = j;
            }
        }
        if (c != i) {
            T1 temp = arr[i];
            arr[i] = arr[c];
            arr[c] = temp;
        }
    }
}

template<typename T = int>  //可以给模板设定默认的类型
void printArr(T arr[] , int len){
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}


int main(){
    int a = 1, b = 3;
    swap1<int>(a, b);   //显示调用
    cout << a << "\t" << b << endl;

    swap1(a, b);        //隐式调用
    cout << a << "\t" << b << endl;

    int arr[] = {1, 2, 3, 9, -10,58,9, 5};
    int len = sizeof(arr) / sizeof(int);
    chooseSort(arr, len, 5);
    printArr(arr, len);


    return 0;
}

