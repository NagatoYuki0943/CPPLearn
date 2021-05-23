#include <iostream>
#include <string>

using namespace std;
/**
 * ��̬ʹ��ʱ,��������������Կ��ٵ�����,��ô����ָ�����ͷ�ʱ�޷����õ��������������
 * �����ʽ:�������е�����������Ϊ���������ߴ�������
 */
/**
 * �������ʹ��������Ĺ���:
 *     1.���Խ������ָ���ͷ��������
 *     2.����Ҫ�о���ĺ���ʵ��(�к�����)
 * ����:
 *     ����Ǵ�������,�������ڳ�����,�޷�ʵ��������
 * �������﷨:
 *     virtual ~����(){}
 * ���������﷨:
 *     virtual ~����()=0;
 * ����ʵ��: ����::~����(){}
 */
class Animal {
public:
    Animal() {
        cout << "Animal�Ĺ��캯������" << endl;
    }
    ///����������֮��,����͸�������������Ͷ��������,���Խ������ָ���ͷ��������ʱ�ͷŲ��ɾ�������
    /*virtual ~Animal(){
        cout << "Animal����������������" << endl;
    }*/
    /**
     * �������� (��Ҫ������ʵ��)
     * ���˴�������֮��,��������ڳ�����,�޷�ʵ����
     * �ᱨ��,��Ϊ��������������ʵ��,����дû��ʵ��,���ⲿʵ�����¾Ϳ�����
     */
    virtual ~Animal() = 0;

    virtual void Speak() = 0;
};

Animal::~Animal() {
    cout << "Animal�Ĵ���������������" << endl;
}


class Cat : public Animal {
public:
    explicit Cat(string name) {
        cout << "Cat�Ĺ��캯������" << endl;
        m_Name = new string(name);
    }

    ~Cat() override {///Ĭ�ϲ�����������������
        //���ٶ�������
        if (m_Name != NULL) {
            cout << "Cat��������������" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    void Speak() override {
        cout << *m_Name << "��˵��" << endl;
    }

    string *m_Name;
};

void test01() {
    Animal *animal = new Cat("Tomè");
    animal->Speak();
    ///����ָ����������ʱ�� ��������������������� ������������ж�������,������ڴ�й©
    delete animal;
}

int main() {
    test01();
    system("pause");
    return 0;
}