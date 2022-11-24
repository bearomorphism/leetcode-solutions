#include <iostream>

class A {
    public:
    A(){};
    virtual void print() final {
        std::cout << func_test() << std::endl;
    }
    protected:
    virtual int func_test() = 0;
};

class B: public A {
    public:
    B() {};
    protected:
    int func_test(){ return 420;}
};

int main() {
    B b;
    b.print();
}