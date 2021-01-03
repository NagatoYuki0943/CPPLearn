#include <iostream>

using namespace std;
/**
 * enum(枚举)工具提供了另一种创建符号常亮的方式,这种方式可以替代const.它还允许定义新类型,但必须按严格的限制进行.
 * 下面的写法让spectrum成为新类型的名称,被称为枚举
 * 将red,yellow等作为符号常量,它们对应整数0~7,这些常量被叫做枚举量
 * 在默认的情况下,将整数值赋值给枚举量,第一个枚举量的值为0.第二个枚举量的值为1,以此类推
 */
enum spectrum {
    red, orange, yellow, green, blue, violet, indigo, ultraviolet
};
spectrum band1 = blue;
//spectrum band2=1; //不允许,只能是里面的值
///可以使用赋值运算符来显示的设置枚举值的量,指定的值必须是整数,
enum bits {
    one = 1, two = 2, four = 4, eight = 8
};
/// 也可以只是显示的定义其中一些枚举值的量
///first在默认的情况下为0,后面的second为100,third为101,依次递增
enum bigstep {
    first, second = 100, third
};

/**
 * 枚举的取值范围
 * 每个枚举都有取值范围,通过强制类型转换,可以将取值范围中的任何整数赋值给枚举变量,
 * 即使这个值不是枚举值
 * 取值范围定义,找到比最大的数大的数中的第一个2的整数次幂-1,如101 最大值是128-1
 */
int main() {

    system("pause");
    return 0;
}