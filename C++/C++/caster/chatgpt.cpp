#include <iostream>
int main()
{
    // float f = 3.14;
    // void* p = &f;
    // int* ip1 = static_cast<int*>(p); // Ошибка компиляции,xabuma chatgpt-n,lavel compile linuma
  
  
    // float a = 42.42;
    // void* p = &a;

    // // C++ casts:
    // int* ip1 = static_cast<int*>(p);        // Ошибка компиляции
    // int* ip2 = reinterpret_cast<int*>(p);  // Разрешено, но небезопасно


    int a = 42;
    int* ptr_a = &a;
    
    // double *ptr_d = static_cast<double*>(ptr_a);//error
    int *ptr_i = static_cast<int*>(ptr_a);//good
}
    // C-style cast:
    // int* ip = (int*)p; // Неявно комбинирует static_cast и reinterpret_cast