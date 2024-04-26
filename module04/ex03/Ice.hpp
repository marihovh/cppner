#pragma once
#include "AMateria.hpp"

class Ice:public AMateria
{
    public:
        Ice();
        Ice(std::string const & type);
        Ice(const Ice &copik);
        Ice &operator = (const Ice &other);
        ~Ice();
        AMateria *clone() const;
        void use(ICharacter& target);
};