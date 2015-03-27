#include <iostream>
using std::cout;
using std::endl;

class A{
public:
   void foo(){cout<<"A"<<endl;}
};

class B :  public A{ //+ virtual
public:
};

class C :  public A{ // + virtual
public:
};

class D : public B, public C {
public :
    void foo(){}; // - foo
};

int main()
{
    D d;
    d.foo();
}
