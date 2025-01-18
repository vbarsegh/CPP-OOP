#include <iostream>
 
// int main()
// { 
//     // int&& lnk_2 = 14;//okay
//     // const int& lnk_2 = 14;//okay
//     // int& lnk_2 = 14;//error
// // const int* ptr;
// // int* const ptr_2;

// // int nb = 10;
// // const int& lnk_1 = nb;




//     //int& const lnk_2->senc ban chka refernce-i hamar
//     // const int& lnk_2,esi pointerneri nuyn erku constna=>const int* const ptr = &a;

//     int c = 10;
//     int n = 3;
//     int& lnk_c = c;
//     // lnk_2++;//errora
//     // lnk_2 = c;//okay
// }



int main()
{
    int a = 10;
    int b = 25;
    int& c = a;

    c = b;
    // b = 20;
    // std::cout << c << " " << b << std::endl;
    
    b = 20;
    std::cout << a << " " << c << std::endl;
}