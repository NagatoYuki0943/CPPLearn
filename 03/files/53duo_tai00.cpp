#include <iostream>

using namespace std;
/**
 * ����ָ�����ֱ��ָ�����
 *
 * ��̬��C++���������������֮һ
 * ��̬������:
 *      ��̬��̬:�������غ�������������ھ�̬��̬,���ú������������
 *      ��̬��̬:��������麯��ʵ������ʱ��̬
 * ��̬��̬�Ͷ�̬��̬������:
 *      ��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
 *      ��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ
 * ��̬��̬:
 *      void speak(){}
 * ��̬��̬:
 *      virtual void speak(){}
 */
/**
 * ��̬��̬
 * 1.Ҫ�м̳�,����Ҫ���麯��(virtual),
 * 2.����Ҫ��д������麯��  (��������ֵ����,�������ƺͲ����б���ȫ��ͬ),������д��virtual�ؼ���д��д����
 */
/**
 * ��̬��̬��ʹ��,�����ָ���������ָ������Ķ���
 */
//������
class Animal {
public:
    //�麯��
    virtual void speak() {
        cout << "������˵��" << endl;
    }
};

//è��
class Cat : public Animal {
public:
    void speak() {
        cout << "Сè��˵��" << endl;
    }
};

//����
class Dog : public Animal {
public:
    void speak() {
        cout << "С����˵��" << endl;
    }
};

//ִ��˵���ĺ���
///��ַ���,�ڱ���׶ξ�ȷ��������ַ,��Animal����,��Animal�ڵĺ���
///�����ִ�е�ַ���,��ô���������ַ�Ͳ�����ǰ��,��Ҫ�����н׶ν��а�,��ַ���  ��Animal�еĺ���ǰ����virtual����
void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    Dog dog;
    //�������ý����������
    doSpeak(cat);  ///Animal & animal = cat ����ָ�����ֱ��ָ�����   һ��ʼ��ӡ:������˵��,����virtual�ͱ�Ϊ:Сè��˵��
    doSpeak(dog);

    Animal animal;
    animal.speak();    ///��������virtual,���������Ȼ���Է���
    doSpeak(animal);
}

void test02() {
    ///�ַ�����������������,����Animal���ǿ���,��С��1,����virtual��С��4(32λ),��clion����8(64λ) ��һ��ָ��
    cout << "sizeof Animal=" << sizeof(Animal) << endl;
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}