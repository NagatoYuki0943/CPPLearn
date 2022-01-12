#include <iostream>
#include <map>
using namespace std;
/**
 *
 *  map中所有元素都是pair
 *  pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
 *  所有元素都会根据元素的键值自动排序
 *
 * 本质：
 *  map/multimap属于关联式容器，底层结构是用二叉树实现。set底层也是二叉树
 *
 *  map和multimap区别：
 *  map不允许容器中有重复key值元素
 *  multimap允许容器中有重复key值元素
 *
 *  没有assign()方法赋值
 *  也没有push和pop方法,要使用insert插入,erase clear删除
 *
 *  insert
 *  erase(key) clear
 *  empty size
 *  swap
 *  find
 *  count
 *  sort
 *  m[key] = value
*/
void printMap(map<int, int> &m){
    for(auto &i: m){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
}

void test1(){
    map<int, int> m1 = {pair<int,int>(0, 1), pair<int,int>(1, 2)};
    cout << m1[1] << endl;

    m1.insert(pair<int,int>(2,3));
    printMap(m1);

    map<int, int> m2(m1);
    map<int, int> m3 = m1;
    printMap(m3);

    cout << m3.empty() << " " << m3.size() << endl; //0 3
    cout << endl;

    map<int,int> m4 = {pair<int,int>(2, 3), pair<int,int>(3, 4)};
    m4.swap(m1);
    printMap(m1);
    //2 3
    //3 4

    m1.erase(2);
    printMap(m1);
    // 3 4
}

class MyCompare{
public:
    //降序
    bool operator()(int a, int b) const{
        return a > b;
    }
};

void test2(){
    map<int, int, MyCompare> m = {make_pair(1, 1), make_pair(2, 3), make_pair(3, 5)};
    for(auto &i: m){
        cout << i.first << " " << i.second << endl;
    }
    //降序
    //3 5
    //2 3
    //1 1
}



int main(){
    //test1();
    test2();
    return 0;
}


