#pragma once
#include "./ICharacter.hpp"
#include "./AMateria.hpp"

class Character:public ICharacter
{
    private:
        std::string name;
        AMateria *slot[4];
    public:
        Character();
        ~Character();
        Character(std::string const &name);
        Character(const Character& copik);
        std::string const & getName() const;
        void setName(std::string &name);
        Character& operator=(const Character& other);
    public:
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};