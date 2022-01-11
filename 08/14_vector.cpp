#include <iostream>
#include <vector>
using namespace std;


void test1(){
    vector<int> v1 = {1, 2, 3, 4};
    v1.push_back(5);

    for(vector<int>::iterator i = v1.begin(); i < v1.end(); i++){
        cout << *i << "\t"; //1	2	3	4	5
    }

    for(auto &i: v1){
        cout << i << "\t";  //1	2	3	4	5
    }
}


class Person{
public:
    Person(string name, int age): name(name), age(age){

    }
    string name;
    int age;
};


//vector中放
void test2(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; ++i) {
        v1.push_back(i);
        v2.push_back(i+1);
        v3.push_back(i+2);
        v4.push_back(i+3);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (auto &i: v) {
        for(auto &j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}


int main(){
    //test1();
    test2();
    return 0;
}