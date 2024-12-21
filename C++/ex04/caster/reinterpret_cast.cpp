#include <iostream>
//reinterpret_cast-@ ogtagorcvum en miayn pointerneri i reference-neri depqum

// int main()
// {
//     // int a = 10;
//     // int b = reinterpret_cast<int>(a);//es depqum xndir cho ta vortev erkusne int tipi ein
//     // //bayc stex sxal kta compilery
//     // char c = reinterpret_cast<char>(a);


//     int a = 10;
//     int* ptr_a = &a;
//     char* ptr_ch = reinterpret_cast<char*>(ptr_a);
//     // char b = reinterpret_cast<char>(a);//sxala vortev sovorakan tiperi hamar chi reinterpret_cast-@,bayc ete ssilka i pointer lini,chisht klni
//     char& lnk_a = reinterpret_cast<char&>(a);

//     void*   ptr_v = reinterpret_cast<void*>(ptr_a);
// }

struct point
{
    int x;
    int y;
};

struct point3D
{
    int x,y,z;
};

int main()
{
    point pt {1, 2};
    point3D* ptr_3d = reinterpret_cast<point3D *>(&pt);
    point3D& lnk_3d = reinterpret_cast<point3D &>(pt);
}