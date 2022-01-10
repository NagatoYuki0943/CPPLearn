#include <iostream>
using namespace std;


void out(int *arr, int len){
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
}

void bubbleSort(int *arr, int len){
    for (int i = 0; i < len-1; ++i) {
        //减少计算量
        bool flag = true;
        for (int j = 0; j < len-1-i; ++j) {
            //升序降序只要改这里的大于号就可以
            if(arr[j] > arr[j+1]){
                flag = false;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        if (flag){
            break;
        }
    }
}

void selectSort(int *arr, int len){
    int c;
    for (int i = 0; i < len-1; ++i) {
        //先指定第一个是最小的/最大的,然后找比它小/大的
        c = i;
        for (int j = i+1; j < len; ++j) {
            //升序降序只要改这里的大于号就可以
            if (arr[j] > arr[c]){
                c = j;
            }
        }

        if (c != i){
            int tmp = arr[c];
            arr[c] = arr[i];
            arr[i] = tmp;
        }
    }
}


int main(){
    int a[] = {1, 2, 3,8,4,0,-8,51,40, -11,-584,481,465,1,1,10};
    //bubbleSort(a,sizeof(a)/sizeof (int));
    selectSort(a,sizeof(a)/sizeof (int));

    out(a, sizeof(a)/sizeof (int));
    return 0;
}