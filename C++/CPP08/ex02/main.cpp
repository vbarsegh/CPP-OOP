#include "MutantStack.hpp"
#include <list>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    // return 0;
     std::list<int> mstack2;

    mstack2.push_back(5);    // Вместо push
    mstack2.push_back(17);   // Вместо push
    std::cout << mstack2.back() << std::endl;   // Вместо top()
    mstack2.pop_back();      // Вместо pop()
    std::cout << mstack2.size() << std::endl;   // size() остаётся прежним
    mstack2.push_back(3);    // Вместо push
    mstack2.push_back(5);    // Вместо push
    mstack2.push_back(737);  // Вместо push
    mstack2.push_back(0);    // Вместо push

    // Инициализируем итераторы
    std::list<int>::iterator it2 = mstack2.begin();
    std::list<int>::iterator it2e = mstack2.end();

    ++it2;  // Перемещаем итератор
    --it2;  // Перемещаем итератор обратно

    // Проходим по элементам списка
    while (it2 != it2e)
    {
        std::cout << *it2 << " ";
        ++it2;
    }
    std::cout << std::endl;

  
}