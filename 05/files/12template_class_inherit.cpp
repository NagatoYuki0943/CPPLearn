#include <iostream>

using namespace std;
/**
 * ��ģ����̳�
 *
 * ����ģ�������̳�ʱ,Ҫע�����¼���
 *      1.������̳еĸ�����һ����ģ��ʱ,������������ʱ��,Ҫָ�������е�T������
 *      2.�����ָ��,�������޷�����������ڴ�
 *      3.��������ָ����������T������,����Ҳ���Ϊģ����
 */
template<class T>
class Base{
    T m;
};

//1.������̳еĸ�����һ����ģ��ʱ,������������ʱ��,Ҫָ�������е�T������  <int>
class Son1 : public Base<int>{

};

void test01(){
    Son1 s1;
}

//3.��������ָ����������T������,����Ҳ���Ϊģ����
template<class T1,class T2>
class Son2 : public Base<T2>{
public:
    Son2(){
        cout << "T1������Ϊ: " << typeid(T1).name() << endl;    //T1������Ϊ: i
        cout << "T2������Ϊ: " << typeid(T2).name() << endl;    //T2������Ϊ: c
    }
    T1 obj;
};

void test02(){
    Son2<int,char> s2;  //<int,char> ==> template<class T1,class T2>

}


int main() {
    test01();
    test02();
    return 0;
}
