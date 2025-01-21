#include <iostream>

So to use static_cast in case of inheritance, the base class must be accessible, non virtual and unambiguous.
// int main()
// {
//     char ch = '0';
//     short sh = 0;
//     int i = 0;
//     double d = 0;

//     char* ptr_ch = &ch;
//     short* ptr_sh = &sh;
//     int* ptr_i = &i;
//     double* ptr_d = &d;

//     ch = static_cast<char>(sh);
//     // ch = reinterpret_cast<char>(sh);//error

//     d = static_cast<double>(i);
//     // d = reinterpret_cast<double>(i);//error

//     // sh = static_cast<short>(ptr_i);//error
//     sh = reinterpret_cast<short>(ptr_i);

//     // ptr_d = static_cast<double*>(ptr_ch);//error
//     ptr_d = reinterpret_cast<double*>(ptr_ch);

// }

//////////////////////////////////////
// struct point2D
// {
//     int x;
//     int y;
// };

// struct point3D : point2D//jarangelov menq  kaxvacutyun enq stexcum iranc mej,vory tuyl kta irakanacnel static_cast
// {
//     int x,y,z;
// };

// int main()
// {
//     point2D ptr_2d{1, 2};
//     point3D* ptr_3d = reinterpret_cast<point3D *>(&ptr_2d);
//     point3D* ptr_3d_2 = static_cast<point3D *>(&ptr_2d);//error,bayc static_cast.cpp-um cuyc ktam vonc anenq vor karananq static_castov el karananq anenq

//     point3D& lnk_3d = reinterpret_cast<point3D &>(ptr_2d);
// }

////////////////////////////
struct point
{
};

struct point2D
{
    int w = 4;
    int v;
};

struct point3D : point2D//jarangelov menq  kaxvacutyun enq stexcum iranc mej,vory tuyl kta irakanacnel static_cast
{
    int x = 2;
    int y,z;
};

int main()
{
    // point2D ptr_2d;
    // point3D* ptr_3d = reinterpret_cast<point3D *>(&ptr_2d);
    // // point3D* ptr_3d_2 = static_cast<point3D *>(&ptr_2d);//error,bayc static_cast.cpp-um cuyc ktam vonc anenq vor karananq static_castov el karananq anenq
    // ptr_3d->w = 5;
    // ptr_3d->x = 3;
    // std::cout <<ptr_3d->w << std::endl;
    // std::cout <<ptr_3d->x << std::endl; 

    point3D ptr_3d;
    // point2D* ptr_2d = reinterpret_cast<point2D *>(&ptr_3d);
    point2D* ptr_2d = static_cast<point2D *>(&ptr_3d);
    ptr_2d->w = 5;
    // ptr_2d->x = 3;//error
    ptr_2d->v = 3;
    std::cout <<ptr_2d->w << std::endl;
    std::cout <<ptr_2d->v << std::endl; 
}