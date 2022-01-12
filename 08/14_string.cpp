#include <iostream>
#include <string>

using namespace std;

void test1(){
    string a;

    const char *str = "Hello world";
    //指针初始化
    string b(str);

    //拷贝
    string c(b);

    string e;
    e.assign(c);

    //等号
    string d = c;

    //重复
    string f(10, 'b');
    string g;
    g.assign(10,'a');

    string h;
    h.assign("Hello");
    h.assign("nihao", 3);   //前三个字符
}

void test2(){
    string a = "123";
    a += "456";         //直接相加就是拼接
    cout << a << endl;  //123456

    a.append("ac");
    a.append("sdf", 1); //添加前1个值
    cout << a << endl;  //123456acs

    a.append("asdf", 1,3);
    cout << a << endl;  //123456acssdf
}


void test3(){
    string a = "adgagahy";
    //像数组操作
    cout << a[0] << endl;              //a
    cout << a.find('a') << endl;    //0
    cout << a.rfind('a') << endl;   //5

    //将1到3替换为0,长度会变化
    a.replace(1, 3,"0");
    cout << a << endl;  //a0gahy

    a.insert(1,"X");
    cout << a << endl;  //aX0gahy

    //有两个参数,位置和数量
    a.erase(0,1);
    cout << a << endl;  //X0gahy
}

int main(){
    test1();
    cout << "------------------------------" << endl;
    test2();
    cout << "------------------------------" << endl;
    test3();

    return 0;
}