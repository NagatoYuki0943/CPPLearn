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
 * 二进制读文件
 * 打开方式: ios::binary
 * 二进制方式读文件主要利用流对象调用成员函数read
 * 函数原型 istream & read(char * buffer, int len);
 * 参数解释:字符指针buffer指向内存中的一段存储空间,len是读的字节数
 */
class Person {
public:
    char m_Name[64];
    int m_Age;
};

void test01() {
    //1.包含头文件
    //2.创建流对象
    ifstream ifs;
    //3.打开文件,判断文件是否打开成功
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读文件
    Person p;
    ifs.read((char *) &p, sizeof(Person));
    cout << "姓名:" << p.m_Name << endl;   //名字乱码,vs可以看到
    cout << "年龄:" << p.m_Age << endl;
    //5.关闭文件
    ifs.close();
}


int main() {
    test01();
    system("pause");
    return 0;
}