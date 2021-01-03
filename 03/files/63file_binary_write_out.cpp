#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
 * 注意:clion默认读写文件的目录是cmake-build-debug目录
 */
/**
 * 写文件步骤
 *  1.包含头文件     #include <fstream>
 *  2.创建对象流     ofstream ofs;
 *  3.打开方式      ofs.open("文件路径",打开方式);
 *  4.写数据        ofs << "写入的数据"
 *  5.关闭文件      ofs.close();
 */
/**
 * 文件打开方式      解释
 * ios::out        为写文件而打开文件
 * ios::in         为读文件而打开文件
 * ios::ate        初始位置:文件尾
 * ios::app        追加方式写文件
 * ios::trunc      如果文件存在先删除,再创建
 * ios::binary     二进制方式
 * 注意:文件打开方式可以配合使用,利用 | 操作符
 * 例如:用二进制方式写文件 ios::binary | ios::out
 */
/**
 * 二进制写文件
 * 打开方式: ios::binary
 * 二进制方式写文件主要利用流对象调用成员函数write
 * 函数原型:ostream & write(const char * buffer,int len)
 * 参数解释:字符指针buffer指向内存中一段存储空间,len是读写的字节数
 */
class Person {
public:
    char m_Name[64]; //不建议使用string,会出问题
    int m_Age;
};

void test01() {
    //1.包含头文件
    //2.创建流对象
    ofstream ofs("person.txt", ios::out | ios::binary);  //直接使用构造函数也可以,不用 .open函数
    //3.打开文件
    //ofs.open("person.txt",ios::out | ios::binary); //ios::out | ios::binary  两个命令之间使用 | 操作符
    //4.写文件
    Person p = {"张三", 18};
    //ofs.write(静态类型指针,长度)
    ofs.write((const char *) &p, sizeof(Person));
    //5.关闭文件
    ofs.close();
}

int main() {
    test01();
    system("pause");
    return 0;
}