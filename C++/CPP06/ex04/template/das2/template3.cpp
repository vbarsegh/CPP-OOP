#include <iostream>

template <typename T1, typename T2>
auto sq_rect(T1 a, T2 b)
{
    return (a * b);
}


int main()
{
    int res_1 = sq_rect(5, 6.5);//double sq_rect<int, double>(int a, double b)
                        // 5 * 6.5 = 32.5=>double
    double res_2 = sq_rect(5, 6);//int sq_rect<int, int>(int a, int b)=>kampilatory chi nayum vor double-i a veragrum funckiayi veradarcrac arjeqy vor double veradarcni,inqy ardyunqina nayum`5*6=30=>int a dnum auto-i poxaren
    short res_3 = sq_rect<short, short>(2, 3);//int sq_rect<short, short>(short a, short b)
                                            //  ~~~
    short res_4 = sq_rect<double>(2, 3);//double sq_rect<double, int>(double a, int b)
    return (0);
}