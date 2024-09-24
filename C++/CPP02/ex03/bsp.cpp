#include "Point.hpp"

float crossProduct(Point a, Point b, Point C)
{
    return (b.x - a.x) * (C.y - a.y) - (b.y - a.y) * (C.x - a.x);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float ab = crossProduct(a, b, point);
    float bc = crossProduct(b, c, point);
    float ca = crossProduct(c, a, point);

    return (ab >= 0 && bc >= 0 && ca >= 0)
        || (ab <= 0 && bc <= 0 && ca <= 0);
}

int main()
{
 Point a = {0, 0};
    Point b = {5, 0};
    Point c = {0, 5};
    Point P = {1, 1}; // Точка для проверки

    if (isPointInTriangle(a, b, c, P)) {
        std::cout << "Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Point is outside the triangle." << std::endl;
    }

    return 0;
}