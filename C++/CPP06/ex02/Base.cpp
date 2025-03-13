#include "Base.hpp"
using std::cout;
using std::endl;

Base::~Base()
{
    cout << "Base dtor is called" << endl;
}

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random = std::rand() % 3;

    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return (NULL);
}

void identify(Base* p)
{
    A* obj_a = dynamic_cast<A*>(p);
    B* obj_b = dynamic_cast<B*>(p);
    C* obj_c = dynamic_cast<C*>(p);

    if (obj_a)
        cout << "A is_a p" << endl;
    else if (obj_b)
        cout << "B is_a p" << endl;
    else if (obj_c)
        cout << "C is_a pp" << endl;
    else
        cout << "Unknown type" << endl;
}

void identify(Base& p)
{
    try
    { 
        A& obj_a = dynamic_cast<A&>(p);
        (void)obj_a;
        cout << "A is_a p" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        B& obj_b = dynamic_cast<B&>(p);
        (void)obj_b;
        cout << "B is_a p" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C& obj_c = dynamic_cast<C&>(p);
        (void)obj_c;
        cout << "C is_a p" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}