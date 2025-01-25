#include <iostream>

// class Point
// {
//     int x{}, y{};
// public:
//     Point(int a, int b): x(a), y(b)
//     { }
// };

// class DoublePoint
// {
//     double x{}, y{};
// public:
//     DoublePoint(double a, double b): x(a), y(b)
//     { }
// };vor senc chlni ogtagorcum enq template

template <typename T>
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
        // Point<int> pt_i(2, 5);
        // Point<double> pt_d(2, 5);

        // Point pt_i2(20, 50);//C++17,minchev 17 standart esi compile errora`error: missing template arguments before ‘pt_i2’
        // //isk ete 17+a karelia ev <>sra mej tipy chnshel,poxancvac tverov inqy jokelua T-i poxaren inch dni,bayc esi klni ete unenq parametrov ctor
        // //ete menak default unenanq 17+standarthe chi prki,misht error kta(tox`46)
        // Point pt_d2(1.2, 3.7);//C++17
        //Մինչև C++17 ստանդարտը, դասերի կաղապարներ օգտագործելիս, մենք պետք է որոշակի տիպ գրեինք կաղապարի պարամետրերի համար, բայց սկսած C++17 ստանդարտից, պարամետրերը կարելի է հաշվարկել այս դասի կոնստրուկտորին փոխանցված արգումենտներից։ .
    }
    {
        Point<int> pt_i;
        Point<double> pt_d;

        Point pt_i2;//error,vortev default ctorov en T-n ches jokum inch pti drvi, isk parametroiv ctori vaxt poxancvac pargumentnerov karelia jokel(vory C++17ic sksac er)
        //bayc 2.cpp um nayi nenc anem vor 46toxi vra error chta
    }

}