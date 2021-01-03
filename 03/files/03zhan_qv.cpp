#include <iostream>

using namespace std;

/**
 * 栈区数据注意事项  ---不要返回局部变量的地址
 * 栈区的数据有编译器管理和开辟
 *形参数据也会存在栈区
 */
int *func() {
    //局部变量
    int a = 10;  //局部变量,存放在栈区,栈区的数据在函数执行完之后自动释放
    return &a; //返回局部变量的地址
}

int main() {
    //接受func的返回值
    int *p = func();
    cout << *p << endl;  //*p解引用,p是a的地址,*p应该输出10,但是局部变量在函数用完就销毁了,找不到
    //在vs中第一次可以打印,因为编译器做了保留,但是第二次就不行了,数据不保留了

    system("pause");
    return 0;
}
