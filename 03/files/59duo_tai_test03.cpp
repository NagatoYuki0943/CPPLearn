#include <iostream>

using namespace std;
/**
 * ���Է�ΪCPU,GPU,�ڴ�,Ӳ��....
 * ÿ�����������������,�ṩ��ͬ����������ͬ���,
 * �����õ��Թ����ĺ���,����ÿ����������Ľ���
 */
//��������
class CPU {
public:
    virtual void Calculator() = 0;
};

class GPU {
public:
    virtual void Display() = 0;
};

class Mem {
public:
    virtual void Storage() = 0;
};

class Computer {
public:
    Computer(CPU *cpu, GPU *gpu, Mem *mem) : m_cpu(cpu), m_gpu(gpu), m_mem(mem) {
    }

    ~Computer() {
        //��������ָ��
        if (m_cpu != NULL) {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL) {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_mem != NULL) {
            delete m_mem;
            m_mem = NULL;
        }
    }

    //�ṩ�����ĺ���
    void work() {
        //���þ���ӿ�
        m_cpu->Calculator();
        m_gpu->Display();
        m_mem->Storage();
    };

private:
    CPU *m_cpu;    //CPU���ָ��
    GPU *m_gpu;    //�Կ����ָ��
    Mem *m_mem; //�ڴ������ָ��
};

//���峧��
//Intel
class IntelCPU : public CPU {
public:
    virtual void Calculator() {
        cout << "����intel��CPU��ʼ������!" << endl;
    }
};

class IntelGPU : public GPU {
public:
    virtual void Display() {
        cout << "����intel��GPU��ʼ��ʾ��!" << endl;
    }
};

class IntelMEM : public Mem {
public:
    virtual void Storage() {
        cout << "����intel��MEM��ʼ�洢����!" << endl;
    }
};

//Lenovo
class LenovoCPU : public CPU {
public:
    virtual void Calculator() {
        cout << "����Lenovo��CPU��ʼ������!" << endl;
    }
};

class LenovoGPU : public GPU {
public:
    virtual void Display() {
        cout << "����Lenovo��GPU��ʼ��ʾ��!" << endl;
    }
};

class LenovoMEM : public Mem {
public:
    virtual void Storage() {
        cout << "����Lenovo��MEM��ʼ�洢����!" << endl;
    }
};

void test01() {
    //��һ̨����
    CPU *intelCPU = new IntelCPU;   //����ָ��ָ������
    GPU *intelGPU = new IntelGPU;
    Mem *intelMEM = new IntelMEM;
    Computer *computer1 = new Computer(intelCPU, intelGPU, intelMEM);
    computer1->work();
    cout << "----------" << endl;
    delete computer1; //Computer�������������ɾ������ָ��,�Ͳ�����д��

    //�ڶ�̨����
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMEM);
    /**
     * computer1->work();  //��һ�л��ӡcomputer2������,���ע���������delete computer1�ͻ��ӡcomputer1��
     */
    computer2->work();
    cout << "----------" << endl;
    delete computer2; //Computer�������������ɾ������ָ��,�Ͳ�����д��

    //����̨����
    Computer *computer3 = new Computer(new IntelCPU, new LenovoGPU, new IntelMEM);
    computer3->work();
    cout << "----------" << endl;
    delete computer3; //Computer�������������ɾ������ָ��,�Ͳ�����д��
}


int main() {
    test01();
    system("pause");
    return 0;
}