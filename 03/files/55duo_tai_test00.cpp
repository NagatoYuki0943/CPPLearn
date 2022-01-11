#include <iostream>
#include <string>

using namespace std;
/**
 * C++提倡使用多态设计程序结构
 * 多态的优点:
 *      1.代码组织结构清晰(各个类分开存储,互不影响)
 *      2.可读性强
 *      3.利于前期和后期的扩展以及维护   真实开发中,提倡 开闭原则 : 对扩展进行开发,对修改进行关闭
 *      缺点:
 *      1.代码量多;
 */
//普通实现
class Calculator {
public:
    int getResult(string oper) {
        if (oper == "+") {
            return m_Num1 + m_Num2;
        } else if (oper == "-") {
            return m_Num1 - m_Num2;
        } else if (oper == "*") {
            return m_Num1 * m_Num2;
        } else if (oper == "/") {
            return m_Num1 / m_Num2;
        } else if (oper == "%") {
            return m_Num1 % m_Num2;
        } else {
            return 0;
        }
        //如果想要扩展新的功能,需要修改源码
        ///真实开发中,提倡 开闭原则 : 对扩展进行开发,对修改进行关闭
    }

    int m_Num1;  //操作数1&2
    int m_Num2;
};

void test01() {
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 5;
    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
    cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
    cout << c.m_Num1 << "/" << c.m_Num2 << "=" << c.getResult("/") << endl;
    cout << c.m_Num1 << "%" << c.m_Num2 << "=" << c.getResult("%") << endl;
}

///利用多态实现计算器
//实现计算器的抽象类
class AbstractCalculator {
public:
    virtual int getResult() {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//设计加法计算器类
class AddCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 + m_Num2;
    }
};

//减法类
class SubstractCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 - m_Num2;
    }
};

//乘法类
class MultiplyCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 * m_Num2;
    }
};

//除法类
class DivideCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 / m_Num2;
    }
};

void test02() {
    //多态使用
    ///父类的指针(引用)指向子类的对象
    AbstractCalculator *abc;
    //加法
    abc = new AddCalculator; //在堆区创建加法类的指针
    abc->m_Num1 = 10, abc->m_Num2 = 6;
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc是指向父类的指针,里面的值是子类
    //用完记着销毁
    delete abc;

    //减法
    abc = new SubstractCalculator;
    abc->m_Num1 = 10, abc->m_Num2 = 6;  //注意,用完一次要记着赋值
    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc是指向父类的指针,里面的值是子类
    //用完记着销毁
    delete abc;

    //乘法
    abc = new MultiplyCalculator;
    abc->m_Num1 = 10, abc->m_Num2 = 6;  //注意,用完一次要记着赋值
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc是指向父类的指针,里面的值是子类
    //用完记着销毁
    delete abc;
}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}