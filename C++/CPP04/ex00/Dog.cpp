#include "Dog.hpp"

Dog::Dog()
{
    set_type("Dog");
    std::cout << "Dog default ctor is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy ctor is called" << std::endl;
    // this->type = other.type;
    //dogi copy ctory kanchveluc pastoren  partadir paymana ira base classi(Animal-i) copy ctornel kanchel,vochte kancchel ayl cherez base classi copy ctorov irakancanel ira(Dogi) copy ctory

    //2)esli shto Dog::Dog(const Dog& other)-sra ardyunqum kampilatory cherevacox ira koxmic inishylayzd listum berum dnum Animali default ctori kanch(vortev orinak type Dogy chuner,inqy jarangec Animalic ov uner ev nor unecav,dra hamara skzbum kanchvelu Animali ctory ,vor es nor stexcvox Dogy unena et type-@)
    //3)menq yndunceinq vor palyubasu petqa dogi copy ctorum grvi vor et Animali atributnery init arvi(te che zut default ctory Animali kanchelov zibil klnen et atributnery), ay hma te eti dzerov kanenq te Animali copy ctori kanchi shnorhiv ,mer gorcna,bayc aveli lava cherez Animali copy ctori mijocov,nereqevum kase xi
    //4)innchova lav Dog::Dog(const Dog& other) : Animal(other),es Animali copy ctory kannchely,nra hamar vor ete Animal classum nor atributner avelanan chbrnenq ham Animlai copy ctorum avelacnenq ham dogi cati copy ctornerum,ayl menak Animali copy ctorum anenq,isk Animali cabkacac jarangi hamar vor copy ctor kanchem ira meje hamapatasxanabar Animali copy ctorov anem et initnery,dus ekav menak avelacri Animali copy ctori mej ,isk nenc ham Animali copy ctorum en hamm avelacnum jam dogi hame cati,zut gorcy karchacnelu hamar enq senc uzum anenq
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog op+ is called" << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Dog::haaaaaaafffff" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog dtor is called" << std::endl;
}