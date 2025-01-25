#include <iostream>

constexpr int f(int n)
{
    if (n <= 1) return (1);//stex stacvuma vor daje if-@ compile time a stugvelu
    return (n * f(n - 1));
}

int main()
{
    int num = 5;
    std::cout << f(5) << std::endl;//compile time
    std::cout << f(num) << std::endl;//run time
}
// Ключевое слово constexpr сообщает компилятору, что функция может быть вычислена на этапе компиляции, если переданные аргументы являются константными выражениями.