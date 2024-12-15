#pragma once

class Ice : public AMateria
{
    private:
        /* data */
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
        virtual ~Ice();
};
