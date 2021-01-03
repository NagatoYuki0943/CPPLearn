#include <iostream>

using namespace std;
/**
 * C++中struct和class唯一区别在于默认的访问权限不同
 * struct默认权限公开 public
 * class默认权限私有  private
 *      C++中成员属性和方法默认都是私有,php中成员属性必须设定,而成员方法不设定默认是public
 * struct  里面的属性和方法也可以使用public,protected,private
 */

struct stu0 {
//private:
    int id; //默认权限公开
};

class stu1 {
    int id; //默认权限私有
    int showScore() {
        return 15;
    }
};

int main() {
    stu0 s1;
    s1.id = 10;
    stu1 s2;
    s2.id;          //报错,C++中成员属性和方法默认都是私有,php中成员属性必须设定,而成员方法不设定默认是public
    s2.showScore(); //报错
    system("pause");
    return 0;
}
