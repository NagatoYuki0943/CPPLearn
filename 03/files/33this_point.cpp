#include <iostream>

using namespace std;

/**
 * c++ͨ���ṩ����Ķ���ָ��,thisָ��,�������Լ�
 * thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
 * thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
 * thisָ�벻��Ҫ����,ֱ��ʹ�ü���
 *
 * thisָ��ı�����ָ�볣��,ָ���ָ���ǲ������޸ĵ�
 *
 * this��;:
 *      ������Ƴ�ͻ:���βκͳ�Ա����ͬ��ʱ,ʹ��this->ָ������
 *      ���ض�����:����ķǾ�̬��Ա�������ض�����,����ʹ�� return *this  (������)
 *
 * @return
 */
class Person {
public:
    Person(int age) : age(age) {    //this->age(age) ��������ʹ�� ���ǿ���age(age)
        //age=age;        //0 û�и�ֵ�ɹ�,����age��ͬһ��
        //this->age=age;  //18  ��ֵ�ɹ�
    }

    ///ע��:���ر���Ҫʹ��&,�᷵���Լ�
    ///�������ֵ,ÿ�η��صİ����忽�������º���,age���ǵ���ԭ����ֵ
    Person &PersonAddAge(Person &p) {
        this->age += p.age;   //���������+���Լ������丳ֵ����������
        return *this; //����object����
    }

    //this=NULL; //thisָ�벻�����޸�ָ���ָ��
    int age;
};

///������Ƴ�ͻ:���βκͳ�Ա����ͬ��ʱ,ʹ��this->ָ������
void test01() {
    Person p1(18);
    cout << "p1������:" << p1.age << endl;
}

///���ض�����,return * this
void test02() {
    Person p1(10);
    Person p2(5);

    //�������û�з���ֵ,ֻ�ܵ���һ��,��Ϊû�з���,��û���ڵ���
    //����*this֮������ظ������������,����object,����object�ĺ���
    //����ֵ������ Person&  ���÷���
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);   //��ʽ���˼��
    cout << "p2������Ϊ:" << p2.age << endl;     //5+10+10+10=35
}

int main() {
    //test01();
    test02();

    system("pause");
    return 0;
}
