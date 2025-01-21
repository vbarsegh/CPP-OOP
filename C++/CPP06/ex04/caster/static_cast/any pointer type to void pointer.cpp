// C++ program to demonstrate 
// static_cast to cast 'to and 
// from' the void pointer
#include <iostream>
using namespace std;

// Driver code
int main()
{
  int i = 10;
  void* v = static_cast<void*>(&i);
  int* ip = static_cast<int*>(v);
  cout << *ip << endl;//good
  return 0;
}