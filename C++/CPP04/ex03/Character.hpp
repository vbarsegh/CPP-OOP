#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];//* ov enq haytararum,qani vor senc pointer enq stexcum vochte obyekt,isk aranc pointeri kstexcver AMateria tipi 4hat obyekt,baaaayc qani vor abstrakt claasi obyekt chenq kara stexcenq,ira tipi pointer enq haytararel
    public:
        Character();
        Character(const std::string new_name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual std::string const& getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        virtual ~Character();
        AMateria* getMateria(int idx) const {
        if (idx >= 0 && idx < 4) {
            return inventory[idx];
        }
        return nullptr;
    }  
};
