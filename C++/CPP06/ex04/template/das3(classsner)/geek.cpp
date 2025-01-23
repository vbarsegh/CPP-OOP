// C++ program to demonstrate
// working of non-type parameters
// to templates in C++
#include <iostream>
using namespace std;

// non-type argument (неконстантный аргумент) 

// template <typename T, int max> int arrMin(T arr[], int n)
// {
//     int m = max;
//     for (int i = 0; i < n; i++)
//         if (arr[i] < m)
//             m = arr[i];

//     return m;
// }

// int main()
// {
//     int arr1[] = { 10, 20, 15, 12 };
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);

//     char arr2[] = { 1, 2, 3 };
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);

//     // Second template parameter
//     // to arrMin must be a
//     // constant
//     cout << arrMin<int, 10000>(arr1, n1) << endl;
//     cout << arrMin<char, 256>(arr2, n2) << endl;

//     // int num = 256;
//     // cout << arrMin<char, num>(arr2, n2) << endl;/error

//     const int num = 256;//Non-type аргументы шаблонов должны быть вычисляемыми на этапе компиляции, потому что шаблоны в C++ обрабатываются компилятором во время компиляции, а не во время выполнения
//     // Если бы значение аргумента было известно только во время выполнения, компилятор не смог бы подготовить специализированную реализацию шаблона.


//     cout << arrMin<char, num>(arr2, n2) << endl;

    
//     return 0;
// }



    // Рассмотрим пример, что было бы, если бы non-type аргументы не были константными:

    template<int N>
    class Array {
        int data[N];
    };

    int main() {
        int size = 10;
        Array<size> arr; // Что делать компилятору?
        return 0;
    }
// В этом коде значение size неизвестно на этапе компиляции, поэтому компилятор не знает, сколько памяти нужно выделить для массива. Это сделает реализацию шаблонов невозможной.