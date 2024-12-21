#include "Cat.hpp"

Cat::Cat()
{
    set_type("Cat");
    CatBrain = new Brain();
    std::cout << "Cat default ctor is called" << std::endl;
}

Cat::Cat(const Cat&  other) : Animal(other)
{
    this->CatBrain = new Brain(*(other.CatBrain));
    std::cout << "Cat copy ctor is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    delete this->CatBrain;
    this->CatBrain = new Brain(*(other.CatBrain));//stex new Brain-@ defalut ctorov chem anum ayl Braini copy ctorov vor el stex for ov chfram,ayl menak en vor Braini copy ctori mej fory frum em heriqa
    // this->CatBrain = other.CatBrain;
    // for (int i = 0; i < 100; i++)
    // {
    //     CatBrain->ideas[i] = other.CatBrain->ideas[i];
    // }
   
   Animal::operator=(other);
    // this->type = other.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Cat::myaaauuu" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat dtor is called" << std::endl;
    delete CatBrain;
}
