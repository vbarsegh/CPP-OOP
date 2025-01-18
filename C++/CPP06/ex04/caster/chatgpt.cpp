#include <iostream>
int main()
{
    void* p = &a;

    // C-style cast:
    int* ip = (int*)p; // Неявно комбинирует static_cast и reinterpret_cast

    // C++ casts:
    int* ip1 = static_cast<int*>(p);        // Ошибка компиляции
    int* ip2 = reinterpret_cast<int*>(p);  // Разрешено, но небезопасно
}