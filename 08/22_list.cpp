#include <iostream>
#include <list>

using namespace std;
/**
 * 链表
 * assign push_back pop_back push_front pop_front
 * begin end
 * empty size resize
 * erase remove(值) clear
 * at [] front back
 * swap
 * reverse sort
 *  没有[] at 不能任意找数据,必须从头开始 ++ -- 不能+1 -1
*/

void printList(list<int > &l){
    for(auto &i: l){
        cout << i << " ";
    }
    cout << endl;
}

void test1(){
    list<int> l1 = {1, 2, 4};
    l1.push_front(0);
    l1.push_back(5);
    printList(l1);           //0 1 2 4 5

    list<int> l2(l1);

    //长度
    list<int> l3(l1.begin(), l1.end());
    list<int> l4;
    l4.assign(++l2.begin(), --l2.end());

    list<int> l5(3, 5);
    list<int> l6;
    l6.assign(3, 5);

    list<int> l7 = l6;
}

void test2(){
    list<int> l1{1, 2, 3, 4};
    list<int> l2{6, 6, 7};

    //交换位置
    l1.swap(l2);
    printList(l1);  //6 6 7
    printList(l2);  //1 2 3 4

    cout << l1.size() << " " << l1.empty() << endl; // 3 0
    l1.resize(10, -1);
    printList(l1);  //6 6 7 -1 -1 -1 -1 -1 -1 -1

    // +1错误,必须++,因为必须连续找
    l1.insert(l1.begin()++, 9);

    //删除值
    l1.erase(++l1.begin());

    //删除值,python也有
    l1.remove(-1);
    printList(l1);  //9 6 7

    cout << l1.front() << " " << l1.back() << endl;     //9 7

    // 没有[]
    //cout << list[1] << endl;
    //cout << list.at(1) << endl;


    l1.clear();
}

void test3(){
    list<int> l = {1, 5, 7, 0, 5, 8, 10};
    l.reverse();    //翻转
    printList(l);   //10 8 5 0 7 5 1

    l.sort();       //排序
    printList(l);   //0 1 5 5 7 8 10
}

class Person{
public:
    Person(string name, int age, int heigth){
        this->name = name;
        this->age = age;
        this->height = heigth;
    }
    string name;
    int age;
    int height;
};

void printPersonList(list<Person> l){
    for(auto &i: l){
        cout << i.name << " " << i.age << " " << i.height << endl;
    }
}


//人物比较
bool comparePerson(Person &a, Person &b){
    if(a.age == b.age){
        //身高降序
        return a.height < b.height;
    }
    //年龄降序
    return  a.age > b.age;
}

void test4(){
    list<Person> l;
    Person p1("A", 15, 155);
    Person p2("B", 18, 156);
    Person p3("C", 13, 180);
    Person p4("D", 13, 160);
    Person p5("E", 11, 200);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);

    printPersonList(l);
    //A 15 155
    //B 18 156
    //C 13 180
    //D 13 160
    //E 11 200
    cout << endl;
    //自定义排序
    l.sort(comparePerson);

    printPersonList(l);
    //B 18 156
    //A 15 155
    //D 13 160
    //C 13 180
    //E 11 200

}

int main(){
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}