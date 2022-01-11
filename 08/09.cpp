#include <iostream>

using namespace std;

class Cpu{
public:
    virtual void Calculator() = 0;
};

class Gpu{
public:
    virtual void Display() = 0;
};

class Mem{
public:
    virtual void Storage() = 0;
};

class IntelCpu: public Cpu{
public:
    void Calculator() override{
        cout << "Intel Calculator" << endl;
    }
};

class IntelGpu: public Gpu{
public:
    void Display() override{
        cout << "Intel Display" << endl;
    }
};

class IntelMem: public Mem{
public:
    void Storage() override{
        cout << "Intel Storage" << endl;
    }
};

class AMDCpu: public Cpu{
public:
    void Calculator() override{
        cout << "AMD Calculator" << endl;
    }
};

class AMDGpu: public Gpu{
public:
    void Display() override{
        cout << "AMD Display" << endl;
    }
};

class AMDMem: public Mem{
public:
    void Storage() override{
        cout << "AMD Storage" << endl;
    }
};

class Computer{
public:
    Computer(Cpu *cpu, Gpu *gpu, Mem *mem){
        this->cpu_p = cpu;
        this->gpu_p = gpu;
        this->mem_p = mem;
    }

    ~Computer(){
        if(this->cpu_p != NULL){
            delete this->cpu_p;
            this->cpu_p = NULL;
        }
        if(this->gpu_p != nullptr){
            delete this->gpu_p;
            this->gpu_p = nullptr;
        }
        if(this->mem_p != nullptr){
            delete this->mem_p;
            this->mem_p = nullptr;
        }
    }

    void work(){
        this->cpu_p->Calculator();
        this->gpu_p->Display();
        this->mem_p->Storage();
    }
private:
    Cpu *cpu_p;
    Gpu *gpu_p;
    Mem *mem_p;
};


int main(){
    Cpu *c_p = new IntelCpu();
    Gpu *g_p = new AMDGpu();
    Mem *m_p = new IntelMem();

    Computer c = Computer(c_p, g_p, m_p);
    c.work();
    //Intel Calculator
    //AMD Display
    //Intel Storage

    Computer c1 = Computer(new AMDCpu(), new AMDGpu(), new IntelMem());
    c1.work();

    return 0;
}