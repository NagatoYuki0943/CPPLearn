#include <iostream>
using namespace std;

struct Student{
    string name;
    int age;
};



int main() {
    int iArr[10];


    struct Student st_arr[] = {
            {"a", 5},
            {"v", 2},
            {"c", 5},
            
    };

    for(auto &i : st_arr){
        cout << i.name << " " << i.age << endl;
    }
    return 0;
}
