#include <iostream>
#include <vector>
using namespace std;

/**
 * assign insert erase clear push_back pop_back
 * begin end
 * front back at []
 * empty size resize reserve capacity
 * swap
 */

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


//vector
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

    //必须写在填入数字后面,不然插入不了数字
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(auto &i: v){
        for(auto &j: i){
            cout << j << "\t";
        }
        cout << endl;
    }
    //0	1	2	3
    //1	2	3	4
    //2	3	4	5
    //3	4	5	6
}


int main(){
    //test1();
    test2();
    return 0;
}