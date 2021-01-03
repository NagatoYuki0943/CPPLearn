#include <iostream>

using namespace std;

int main() {
    int arr[] = {300, 350, 400, 520, 220};
    int j = 0;

    for (int i = 0; i < 5; i++) {

        /*if(arr[i]<arr[i+1]) {
            j = i + 1;
        }*/
        if (arr[i] > arr[j]) {
            j = i;
        }
        //cout << j << endl;
    }
    cout << "最重的是第" << j << "只;" << "体重为" << arr[j] << endl;

    return 0;
}