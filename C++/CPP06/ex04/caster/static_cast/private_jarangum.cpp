// C++ program to demonstrate 
// static_cast in case of 
// private inheritance
#include <iostream>
using namespace std;

class Base 
{};

class Derived: private Base //protectedovel error klni
{ 
  // Inherited private/protected 
  // not public
};

// Driver code
int main()
{    
  Derived d1;
  
  // Implicit type cast allowed
  Base* b1 = (Base*)(&d1);
  
  // static_cast not allowed
  Base* b2 = static_cast<Base*>(&d1);
  return 0;
}

