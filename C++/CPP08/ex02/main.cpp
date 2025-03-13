#include "MutantStack.hpp"
#include <list>
int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(737);

        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        
        std::cout << "Elements in reverse order: ";
        while (rit != rite) {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
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
    }
    std::cout << std::endl;
    {

        std::list<int> mstack2;

        mstack2.push_back(5);   
        mstack2.push_back(17);  
        std::cout << mstack2.back() << std::endl;  
        mstack2.pop_back();   
        std::cout << mstack2.size() << std::endl;
        mstack2.push_back(5);   
        mstack2.push_back(3);
        mstack2.push_back(737); 
        mstack2.push_back(0);   

        std::list<int>::iterator it2 = mstack2.begin();
        std::list<int>::iterator it2e = mstack2.end();
        ++it2;
        --it2;
        while (it2 != it2e)
        {
            std::cout << *it2 << " ";
            ++it2;
        }
        std::cout << std::endl;
    }
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(737);

        MutantStack<int>::const_iterator cit = mstack.cbegin();
        MutantStack<int>::const_iterator cite = mstack.cend();
        
        std::cout << "Const elements in stack: ";
        while (cit != cite) {
            std::cout << *cit << " ";
            // *cit = 100;//error
            ++cit;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        MutantStack<int> mstack1;
        mstack1.push(5);
        mstack1.push(17);
        
    
        MutantStack<int> mstack2(mstack1);
        std::cout << "Top of mstack2 after copy: " << mstack2.top() << std::endl; 
   
        MutantStack<int> mstack3;
        mstack3.push(1);
        mstack3 = mstack1; 
        std::cout << "Top of mstack3 after assignment: " << mstack3.top() << std::endl; 
    }
    cout << endl;
    {
         MutantStack<int> mstack;

        std::cout << "Is stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;  // Должно вывести "Yes"
        mstack.push(42);
        std::cout << "Is stack empty after push? " << (mstack.empty() ? "Yes" : "No") << std::endl;  // Должно вывести "No"
    
    }
}