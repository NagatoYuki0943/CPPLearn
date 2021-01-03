#include <iostream>
//#include <string>   //使用c++字符规则中的时候要用这个包含,但是clion不用也可以
using namespace std;

int main() {
    //c风格字符串  char 变量名[]="字符串"     字符用单引号  字符串用双引号
    char str1[] = "hello world";
    cout << str1 << endl;

    //c++风格     string 变量名="字符串"
    string str2 = "nihao,zaima";
    cout << str2 << endl;
    cout << str2[0] << endl;   //字符串就是一个字符的数组,可以使用 [0]输出单个字符
    return 0;
}
/**
 * C类型字符串
	char类型字符串 必须要以空字符结尾才是字符串 
	char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I' };     只是一个数组,不是字符串
	char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0' };      是一个字符串
	另一种简单写法 用括号括起来的字符串隐式的包括结尾的空字符,不用显示的包括它
	char bird[11] = "MR.Cheeps";
	char fish[] = "Bubbles";

	注意:字符串常量(使用双引号)不能与字符常量(使用单引号互换),字符常量(如 'S')是字符串编码的简写表示.在ASCII中,'S'只是82的另一种写法,因此,下面的语句是可以的
	char ch = 'S' ;
	但是 "S" 不是字符常量,它表示的是两个字符(字符S和\0)组成的字符串.更糟的是,"S"表示的实际是字符串所在的内存地址.因此下面的语句试图将一个内存地址赋值给ch
	char ch = "s";
	由于地址在C++中是一种独立的类型,因此C++编译器不允许这种不合理的做法
	
	标准头文件 cstring提供了很多与字符串相关的函数的声明
	strlen() 函数返回字符串的长度,只能用于char数组,不能用于string类型,strcpy(),strcat().cin.getline(),cin.get()同理
	strcpy(str1, str2 ); 将str2的值赋值给str1
	strcpy(str1 ,str2 ); 将str2拼接到str1尾部,放到str1中
	对于string类型来说可以直接使用 "=" 进行赋值,使用 "+" 进行拼接,更加简单

	char str1[]="asdfae";
	char str3[]="sdfe";
	string str2="asdfaed";
	int len1=strlen(str1);
	//int len2=strlen(str2);   //strlen函数不能检查string类型的字符串的长度
	    
	strcpy(str1,str3);
	//strcpy(str1,str2);       //strcpy只能用于char类型,不能用于string类型
	strcat(str1,str3);
	 //strcat(str1,str2);       //strcat只能用于char类型,不能用于string类型
	
	注意 : cin 输入字符串遇到空格,回车会结束,所以不能输入带有空格的字符串
	要使用 cin.getline() 和 cin.get()输入带有空格的字符;
	cin是iostream的一个对象,getline和get是类内的方法
	cin.getline(字符串名字,长度)   cin.get(字符串名字,长度)
	getline()每次读取一行,它通过换行符结束,getline()将换行符丢弃,将换行符转换为空格 ,get()会将换行符保留在输入队列中,下一个输入的就是换行
	
	对于get()会保留空格,可以使用下面的方法接收
	cin.get(name,20);
	cin.get();
	cin.get(dessert,50);
	cin.get();
	
	或者
	cin.get(name,20).get();
	cin.get(dessert,50).get();
	
	混合输入数字和字符串会出现问题
	
	int year;
	cin >> year;
	cin.get();   //or cin.get(ch)    如果没有这一行,输入year之后不会输入address了,下面一行和上面两行同理
	//(cin >> year).get();     or   (cin >> year).get(ch)

	char address[50];
	cin.getline( address, 50 );

string字符串类

	string中的字符可以通过数组方式进行访问
	string对象声明为简单对象,而不是数组
	string str1;
	cin >> str1;
	类设计能让程序能够自动处理string的大小,自动调整长度.


C++11初始化
	如果开始不给任何值,自动设置为0
	char str1[10] {1,2,3};
	string str2[5] {1,2,5,6};
	

	char ch[20];
	string str;
	cin.getline(ch,20);   //类内方法,第一个参数的目标数组,第二个参数是长度,getline不能用于string类型
getline(cin,str);         //这一行没有 .  说明不是类中的方法  它把cin作为参数,指出到哪里去查找输入
 */ 