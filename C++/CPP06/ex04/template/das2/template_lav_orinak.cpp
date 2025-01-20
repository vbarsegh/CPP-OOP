#include <iostream>

template <typename T>
T add(T a, T b) {puts("add: 1"); return (a + b);}

// int add(int a, int b)
// {
//     puts("add: voch shablonayin");
//     return (a + b);
// }henc esi bacenq 34rd toxi funkcia kanchi jmk kkanchvi henc es funkcian vochte verevi template-ov add-@!

template <typename T>
T add(T* a, T* b) {puts("add: 2"); return (*a + *b);}

template <typename T1, typename T2>
auto add(T1 a, T2 b) {puts("add: 3"); return (a + b);}

void add(std::string& dest, const std::string& src)
{
    puts("add: 4");
    dest.append(src);
}


int main()
{
    std::string str_1 = "Hello";
    std::string str_2 = "World";
    int a = 0;
    int b = 3;

    add(&a, &b);//add 2
    add(str_1, str_2);// add 4
    add(1, 2);//add 1
    add(2.3, 3.5);//add 1
    add(1, 2.5);//add 3


//ete menq unenq voch shablonayin funkcia hamapatasxan chisht argumentneri tiperov,apa henc et voch shablonayin funkcianel kkanchvi
//vorpes apacuyc`
     add(1, 2);//add 1,ay stex arden kkancvhi vochte add 1-@ ayl add voch shablonayiny
    return (0);
}