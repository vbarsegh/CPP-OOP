#include <stdio.h>

typedef struct P
{
    char c;
    char c2;
    char c3;
    int num;


} P;

int main()
{
    P obj;
    printf("size->%lu\n", sizeof(obj));
}
