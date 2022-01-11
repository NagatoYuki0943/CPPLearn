#include <iostream>

using namespace std;
/**
 * 电脑分为CPU,GPU,内存,硬盘....
 * 每个零件抽象出抽象基类,提供不同厂商生产不同零件,
 * 创建让电脑工作的函数,调用每个零件工作的杰阔
 */
//三个基类
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
        //析构三个指针
        if (this->m_cpu != NULL) {
            delete this->m_cpu;
            this->m_cpu = NULL;
        }
        if (this->m_gpu != NULL) {
            delete this->m_gpu;
            this->m_gpu = NULL;
        }
        if (this->m_mem != nullptr) {
            delete this->m_mem;
            this->m_mem = nullptr;
        }
    }

    //提供工作的函数
    void work() {
        //调用具体接口
        this->m_cpu->Calculator();
        this->m_gpu->Display();
        this->m_mem->Storage();
    };

private:
    CPU *m_cpu;    //CPU零件指针
    GPU *m_gpu;    //显卡零件指针
    Mem *m_mem; //内存条零件指针
};

//具体厂商
//Intel
class IntelCPU : public CPU {
public:
    void Calculator() override {
        cout << "这是intel的CPU开始计算了!" << endl;
    }
};

class IntelGPU : public GPU {
public:
    void Display() override {
        cout << "这是intel的GPU开始显示了!" << endl;
    }
};

class IntelMEM : public Mem {
public:
    void Storage() override {
        cout << "这是intel的MEM开始存储了了!" << endl;
    }
};

//Lenovo
class LenovoCPU : public CPU {
public:
    void Calculator() override {
        cout << "这是Lenovo的CPU开始计算了!" << endl;
    }
};

class LenovoGPU : public GPU {
public:
    void Display() override {
        cout << "这是Lenovo的GPU开始显示了!" << endl;
    }
};

class LenovoMEM : public Mem {
public:
    void Storage() override {
        cout << "这是Lenovo的MEM开始存储了了!" << endl;
    }
};

void test01() {
    //第一台电脑
    CPU *intelCPU = new IntelCPU;   //父类指针指向子类
    GPU *intelGPU = new IntelGPU;
    Mem *intelMEM = new IntelMEM;
    auto *computer1 = new Computer(intelCPU, intelGPU, intelMEM);
    computer1->work();
    cout << "----------" << endl;
    delete computer1; //Computer类的析构函数会删除三个指针,就不用手写了

    //第二台电脑
    auto *computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMEM);
    /**
     * computer1->work();  //这一行会打印computer2的数据,如果注释了上面的delete computer1就会打印computer1的
     */
    computer2->work();
    cout << "----------" << endl;
    delete computer2; //Computer类的析构函数会删除三个指针,就不用手写了

    //第三台电脑
    auto *computer3 = new Computer(new IntelCPU, new LenovoGPU, new IntelMEM);
    computer3->work();
    cout << "----------" << endl;
    delete computer3; //Computer类的析构函数会删除三个指针,就不用手写了
}


int main() {
    test01();
    system("pause");
    return 0;
}