#include <iostream>

template <typename T=int>//hres
class Point
{
    T x{}, y{};
public:
    Point(){};
    Point(T a, T b): x(a), y(b)
    { }
};


int main()
{
    {
        Point<int> pt_i;
        Point<double> pt_d;

        Point pt_i2;//C++17,daje en vor t=int grelem,ete standarty 17ic poqr exav meka error enq stanalu

        // Point obj(2.4, 4);//error
        Point<double> obj(2.4, 4);//isk senc oka,vortev hstak nshelenq vor double ynduni
    }

}