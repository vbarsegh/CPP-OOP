#include <iostream>
class A {
public:
    void foo() {}
    int x = 10;
};

class B : public A {};  // Обычное наследование
class C : public A {};  // Обычное наследование
class D : public B, public C {}; // D содержит два экземпляра A через B и C

int main() {
    D d;
    // std::cout << d.x < std::endl;
    // Ошибка: двусмысленность, неясно, какой A использовать - из B или C.
    A* base = static_cast<A*>(&d);
    
    
    // A* base = static_cast<A*>(static_cast<B*>(&d)); // Работает, путь уточнён,de senc kashxati

    return 0;
}//static_cast ogtagorcelu chi nayev bazmakimjarangman depqum
// Unambiguous
// Если базовый класс присутствует в иерархии несколько раз (без виртуального наследования),
// то это называется двусмысленностью. static_cast не может выполнить преобразование, так как неясно,
// к какому экземпляру базового класса нужно обратиться.
