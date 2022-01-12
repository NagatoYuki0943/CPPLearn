#include <iostream>
#include <queue>

using namespace std;

/**
 * queue 常用接口
 * 构造函数：
 *  queue<T> que;                  //queue采用模板类实现，queue对象的默认构造形式
 *  queue(const queue &que);       //拷贝构造函数
 *
 * 赋值操作：
 *  queue& operator=(const queue &que);   //重载等号操作符
 *
 * 数据存取：
 *  push(elem);         //往队尾添加元素
 *  pop();              //从队头移除第一个元素
 *  front();            //返回第一个元素
 *  back();             //返回最后一个元素
 *
 * 大小操作：
 *  empty();            //判断堆栈是否为空
 *  size();             //返回栈的大小
 */
void test01() {
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);

    //查看长度
    cout << "q1's size is " << q1.size() << endl;      //q1's size is 5

    while (!q1.empty()) {
        //查看队头和队尾
        cout << q1.front() << "-" << q1.back() << " ";  //10-50 20-50 30-50 40-50 50-50
        q1.pop();
    }
    cout << endl;

    cout << "q1's size is " << q1.size() << endl;       //q1's size is 0
}

int main() {
    test01();
    return 0;
}
