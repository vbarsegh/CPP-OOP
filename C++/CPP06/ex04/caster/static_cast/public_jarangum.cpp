// C++ Program to demonstrate 
// static_cast in inheritance
#include <iostream>
using namespace std;
class Base 
{};
class Derived : public Base 
{};

// Driver code
int main()
{
  Derived d1;
  
  // Implicit cast allowed
  Base* b1 = (Base*)(&d1);
  
  // upcasting using static_cast
  Base* b2 = static_cast<Base*>(&d1);

  cout << "d1 address->" << &d1 << endl;
  cout << "b2 address->" << b2 << endl;
  return 0;
}