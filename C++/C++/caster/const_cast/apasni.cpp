#include <iostream> 
using namespace std; 

int fun(int* ptr) 
{ 
	*ptr = *ptr + 10; //stex pastaci poxum enq val-i arjeqy vory const er,inchy hangecnuma undefined behaviour-i
	return (*ptr); 
} 

int main(void) 
{ 
	const int val = 10; 
	const int *ptr = &val; 
	int *ptr1 = const_cast <int *>(ptr); 
	fun(ptr1); 
	cout << val; //kaxvac kampilatoric kara ste 10e tpi kara 20e tpi
	return 0; 
} 

// {
//     int fun(int* ptr) 
//     { 
//         *ptr = *ptr + 10; 
//         return (*ptr); 
//     } 
    
//     int main(void) 
//     { 
//         int val = 10; //stex sax okeya vortev val-@ const haytararac chi
//         const int *ptr = &val; 
//         int *ptr1 = const_cast <int *>(ptr); 
//         fun(ptr1); 
//         cout << val; 
//         return 0; 
//     } 
// }

