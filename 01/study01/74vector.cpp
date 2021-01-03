#include <iostream>
#include <vector>

using namespace std;

int main() {
    /**
     * 模板类vector类似于string类,也是一种动态数组.可以再运行阶段设置vector对象的长度,
     * 可以再末尾附加新数据,还可以在中间附加新数据.基本上,它是使用new创建动态数组的代替品
     * 使用之前要使用#include <vector>
     * vector<类型> 名字(长度)  长度可以使整形常亮或者变量
     * C++11之后,可将列表  用于vector和array对象,但在C++98中,不能对vector对象这样做
     */

    vector<int> a(3);
    vector<int> b2 = {1, 2};  //初始化,不需要(),=可以省略
    cout << b2[0] << endl; //输出第一个
    int n;
    cin >> n;
    vector<double> b(n);

    system("pause");
    return 0;
}