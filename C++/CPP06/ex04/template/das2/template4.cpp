#include <iostream>

template <typename RT = double, typename T1, typename T2>
RT sq_rect(T1 a, T2 b)
{
    return (a * b);
}


int main()
{
    int res_1 = sq_rect(5, 6.5);//DOUBLE sq_rect<DOUBLE, int, double>(int a, double b)
                        // 5 * 6.5 = 32.5=>double
    double res_2 = sq_rect(5, 6);//DOUBLE sq_rect<DOUBLE, int, int>(int a, int b)
//verevi erku toxum vor <>sra mej ban chenq nshum inqy default RT-in double a veragrum,isk taki erku toxerum hstak nshum enq u mer nshac tipna linum RT-n

    short res_3 = sq_rect<short>(2, 3);//SHORT sq_rect<SHORT, int, int>(int a, int b)
                                        //typename RT = double;->double-i poxaren bervum drvuma short,u veradarcvox arjeqi tipy darnuma short
    short res_4 = sq_rect<int>(2.2, 3.5);//INT sq_rect<INT, double, double>(double a, double b)
    return (0);
}