#include <iostream>

class A
{
    int x;
public:
    virtual A& foo(std::string str){std::cout << str << std::endl;}
    void moo(std::string str){std::cout << str << std::endl;}
};

class B : public A
{
    int z;
public:
    B& foo(){std::cout << "pahooo" << std::endl;}
};

int main()
{
    B obj;

    // obj.foo();//okeya
    obj.A::foo("hmmmmm");//esi sxala vortev B classum mana gali std::string parametrov foo funkcia,chi gtnum u sxala tali,vochte ete nayuma tenuma B um chka gnum A-i mej mana gali gtnum
}




// class A
// {
//     int x;
// public:
//     virtual void foo(std::string str){std::cout << str << std::endl;}
// };

// class B : public A
// {
//     int z;
// public:
//     virtual void foo() {std::cout << "pahooo" << std::endl;}
// };

// int main()
// {
//     B obj;

//     A* o = &obj;

//     // obj.foo();//okeya
//     o->foo("hmmmmm");//esi sxala vortev B classum mana gali std::string parametrov foo funkcia,chi gtnum u sxala tali,vochte ete nayuma tenuma B um chka gnum A-i mej mana gali gtnum
// }