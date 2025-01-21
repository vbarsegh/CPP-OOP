#include <iostream>

template <typename T=int>//hres
class Point
{
    T x{}, y{};
    static T counter_obj;//ete unenq static popoxakan iran karanq init anenq senc`tox 23-24
public:
    Point(){};
    // Point(T a, T b): x(a), y(b)
    // { }
    Point(T a, T b);
    T get_x() {return x;}
    T get_y() {return y;}
    
    void set_xy(T a, T b);
    // {
    //     x = a;
    //     y = b;
    // }
};

template <typename T>
T Point<T>::counter_obj = 0;
// T counter_obj = 0;

template <typename T>
Point<T>::Point(T a, T b) : x(a), y(b)
{

}

template <typename T>
void Point<T>::set_xy(T a, T b)
{
    x = a;
    y = b;
}

int main()
{
    {
        Point<int> pt_i;
        Point<double> pt_d(7.5, -3.14);

        pt_i.set_xy(10, 20);
        std::cout << "pt_i.x = " << pt_i.get_x() << " ,pt_i.y  = " << pt_i.get_y() << std::endl;
        std::cout << "pt_d.x = " << pt_d.get_x() << " ,pt_d.y  = " << pt_d.get_y() << std::endl;
    }

}