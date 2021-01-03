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
 * 查看文件是否为空
 * char ch;
 * ifs >> ch;  //读取一个字符
 * if(ifs.eof()){  //如果读取一个字符,这个字符是结尾,说明文件为空  ifs.eof()
 * }
 */
void test01() {
    //1.创建流对象
    //2.创建读对象
    ifstream ifs;
    //3.打开文件病判断是否打开成功
    ifs.open("test.txt", ios::in);  //ios::in 读文件 默认读取文件的目录是cmake-build-debug
    /// ifs.is_open() 判断打开成功失败
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    //第一种
    cout << "1:" << endl;
    /*char buf0[1024]={0};
    ///ifs >> buf 会一直读取,直到为空停止
    while(ifs >> buf0){
        cout << buf0 << endl;
    }*/

    //第二种
    cout << "2:" << endl;
    /*char buf1[1024]={0};
    ///ifs.getline(存放位置,读取数目)
    while(ifs.getline(buf1,sizeof(buf1))){
        cout << buf1 << endl;
    }*/


    //第三种  推荐
    cout << "3:" << endl;
    string buf2;
    ///getline(基础输入流,保存位置)
    /*while (getline(ifs,buf2)){
        cout << buf2 << endl;
    }*/

    //第四种:一个一个字符读
    cout << "4:" << endl;
    char c;
    ///ifs.get() 一次读一个字符
    ///(c=ifs.get())!=EOF  DOF文件尾
    while ((c = ifs.get()) != EOF) {
        cout << c;
    }


    //5.关闭文件
    ifs.close();

}

int main() {
    test01();
    system("pause");
    return 0;
}