class A {
public:
    virtual void foo() {}
};

class B : virtual public A {};  // Виртуальное наследование
class C : virtual public A {};  // Виртуальное наследование
class D : public B, public C {}; // D наследует A виртуально через B и C

int main() {
    D d;
    A* base = static_cast<A*>(&d); // Ошибка: static_cast не работает с виртуальным наследованием
    return 0;
}



// #include <iostream>
// class Base {
//     public:
//         // Base();
//         // virtual ~Base(){std::cout << "a\n";};
// };
// class Derived : public virtual Base {
//     public:
//     // Derived();
//     // ~Derived();
// };

// int main()
// {
//     Base* b = new Derived;
//     Derived* d = static_cast<Derived*>(b);
// }//chem jokum xi chi karum cast ani??????