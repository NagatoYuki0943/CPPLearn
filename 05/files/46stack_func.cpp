#include <iostream>
#include <stack>

using namespace std;

/**
 * 构造函数：
 *  stack<T> stk;                   //stack采用模板类实现， stack对象的默认构造形式
 *  stack(const stack &stk);        //拷贝构造函数
 *
 * 赋值操作：
 *  stack& operator=(const stack &stk);         //重载等号操作符
 *
 * 数据存取：
 *  push(elem);         //向栈顶添加元素
 *  pop();              //从栈顶移除第一个元素
 *  top();              //返回栈顶元素
 *
 * 大小操作：
 *  empty();            //判断堆栈是否为空
 *  size();             //返回栈的大小
 */
void test01() {
    stack<int> s1;
    //入栈
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    stack<int> s2(s1);

    cout << "s2's size is " << s2.size() << endl;   //s2's size is 5

    //只要栈顶不为空,就查看栈顶,并执行出栈
    while (!s2.empty()) {
        cout << s2.top() << " ";                    //5 4 3 2 1
        s2.pop();
    }
    cout << endl;
    cout << "s2's size is " << s2.size() << endl;   //s2's size is 0
}

int main() {
    test01();
    return 0;
}
