#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct A
{
	// private://ski senc ban inqy chie chanachum
        int x;
	// public://ese chi chanachum zut imananq vor publica ira access specifier=@
		// A(){std::cout <<" ctor";}
		// void get(){std::cout << "ye";}
		// ~A(){std::cout << "dtor";}
}A;
int main()
{
	A obj;
	obj.x = 5;
	// obj.get();
	return (0);
}