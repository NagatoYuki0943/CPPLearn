#include <iostream>
#include <string>

using namespace std;
/**
 * C++�ᳫʹ�ö�̬��Ƴ���ṹ
 * ��̬���ŵ�:
 *      1.������֯�ṹ����(������ֿ��洢,����Ӱ��)
 *      2.�ɶ���ǿ
 *      3.����ǰ�ںͺ��ڵ���չ�Լ�ά��   ��ʵ������,�ᳫ ����ԭ�� : ����չ���п���,���޸Ľ��йر�
 *      ȱ��:
 *      1.��������;
 */
//��ͨʵ��
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
        //�����Ҫ��չ�µĹ���,��Ҫ�޸�Դ��
        ///��ʵ������,�ᳫ ����ԭ�� : ����չ���п���,���޸Ľ��йر�
    }

    int m_Num1;  //������1&2
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

///���ö�̬ʵ�ּ�����
//ʵ�ּ������ĳ�����
class AbstractCalculator {
public:
    virtual int getResult() {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//��Ƽӷ���������
class AddCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 + m_Num2;
    }
};

//������
class SubstractCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 - m_Num2;
    }
};

//�˷���
class MultiplyCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 * m_Num2;
    }
};

//������
class DivideCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 / m_Num2;
    }
};

void test02() {
    //��̬ʹ��
    ///�����ָ��(����)ָ������Ķ���
    AbstractCalculator *abc;
    //�ӷ�
    abc = new AddCalculator; //�ڶ��������ӷ����ָ��
    abc->m_Num1 = 10, abc->m_Num2 = 6;
    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc��ָ�����ָ��,�����ֵ������
    //�����������
    delete abc;

    //����
    abc = new SubstractCalculator;
    abc->m_Num1 = 10, abc->m_Num2 = 6;  //ע��,����һ��Ҫ���Ÿ�ֵ
    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc��ָ�����ָ��,�����ֵ������
    //�����������
    delete abc;

    //�˷�
    abc = new MultiplyCalculator;
    abc->m_Num1 = 10, abc->m_Num2 = 6;  //ע��,����һ��Ҫ���Ÿ�ֵ
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;  //abc��ָ�����ָ��,�����ֵ������
    //�����������
    delete abc;
}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}