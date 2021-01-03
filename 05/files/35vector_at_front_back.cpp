#include <iostream>
#include <vector>

using namespace std;

/**
 * 对vector中数据的存取操作
 * 函数原型:
 *  operator[index]     //返回索引index的数据
 *  at(int index)       //返回索引index的数据
 *  front()             //返回容器中第一个元素    *(v1.begin()) 和 front() 相同
 *  back()              //返回容器中最后一个元素  *(v1.end()-1) 和 back() 相同     注意: end() 指的是最后一个的下一个,不是最后一个
 *
 *  获取之后可以对原值进行赋值,和string的方式相同
 */

void test01() {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //使用[] 和 at 访问元素
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << "-" << v1[i] << " ";    //1-1 2-2 3-3 4-4 5-5 6-6 7-7 8-8 9-9 10-10
    }
    cout << endl;
    cout << v1.front() << " " << v1.back() << endl; //1 10

    //*(v1.begin()) 和 front() 相同
    cout << *(v1.begin()) << endl;  //1
    //*(v1.end()-1) 和 back() 相同
    cout << *(v1.end() - 1) << endl;  //10

    //注意: end() 指的是最后一个的下一个,不是最后一个
    cout << *(v1.end()) << endl;    //102492703

    //获取之后可以直接修改
    v1[1] = 15;
    v1[2] = 16;
    v1.front() =17;
    v1.back() = 18;
    cout << v1[1] << " " << v1[2] << " " << v1.front() << " " << v1.back() <<endl;  //15 16 17 18

}

int main() {
    test01();
    return 0;
}
