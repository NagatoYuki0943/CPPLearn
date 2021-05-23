#include <iostream>

using namespace std;

int a[] = {1, 2, 3, 4};

void func1(int b[]){
    b[0] = 10;
}

void func2(int b[]){
    cout << b[0] << endl;
}

int main() {
    func1(a);
    func2(a);
    return 0;
}
