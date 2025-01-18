#include <iostream>
//dynamic_cast-@ ashxatum e pointerneri ev referancneri vra
class Thing
{
    public:
        virtual void print() const {}
};

class Ball : public Thing
{
    int radius;
    int color;
public:
    virtual void print() const override {puts("Ball");}
    void    get_data(int& r, int&c) const {r = radius; c = color;}    
};

class Mouse : public Thing
{
public:
    virtual void print() const override {puts("Mouse");}
};

class Cart
{
public:
    void add_thing(const Thing& th)
    {
        th.print();
        
        const Ball* ptr_ball = dynamic_cast<const Ball*>(&th);

        if(ptr_ball)
        {
            int radius;
            int color;
            ptr_ball->get_data(radius, color);
            puts("th is a Ball");
        }
        else    
            puts("th is not a Ball");
    }
};

int main()
{
    Cart cr;

    Mouse mouse;
    Ball ball;

    cr.add_thing(mouse);
    cr.add_thing(ball);
}


// class Thing
// {
//     public:
//         void print() const {}
// };

// class Ball : public Thing
// {
//     int radius;
//     int color;
// public:
//     void print() const {puts("Ball");}
//     void    get_data(int& r, int&c) const {r = radius; c = color;}    
// };

// class Mouse : public Thing
// {
// public:
//     void print() const  {puts("Mouse");}
// };

// class Cart
// {
// public:
//     void add_thing(const Thing& th)
//     {
//         th.print();
        
//         const Ball* ptr_ball = dynamic_cast<const Ball*>(&th);

//         if(ptr_ball)
//         {
//             int radius;
//             int color;
//             ptr_ball->get_data(radius, color);
//             puts("th is a Ball");
//         }
//         else    
//             puts("th is not a Ball");
//     }
// };

// int main()
// {
//     Cart cr;

//     Mouse mouse;
//     Ball ball;

//     cr.add_thing(mouse);
//     cr.add_thing(ball);
// }
//stex compile aneluc kstananq hetevyal error-@`(sax virtaulnery jnjelem)
// caster/dynamic_cast.cpp:31:32: error: 'Thing' is not polymorphic
// const Ball* ptr_ball = dynamic_cast<const Ball*>(&th);

// sranic karelia pastel ayn,vor dynamic_cast-@ ogtagorcvum e Polymorphic(ete classy parunakum e gone 1virtual funkcia ,na hamarvum e Polymorphic) classneri vra(jmk)
// Որոշակի դասի տեսակը որոշելու համար dynamic_cast օգտագործում է դասերի համար նախատեսված մեթոդների վիրտուալ աղյուսակի հասցեն, ուստի այն կարող է աշխատել միայն առնվազն մեկ վիրտուալ մեթոդ պարունակող դասերի հետ, եթե դասերը չեն պարունակում վիրտուալ մեթոդներ, ապա գաղտնի Cast օպերատորը նրանց գործնականում ընդհանրապես չի դիմել