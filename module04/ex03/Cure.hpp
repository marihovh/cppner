#pragma once
#include "AMateria.hpp"
#include "./ICharacter.hpp"

class Cure:public AMateria
{
    public:
        Cure();
        Cure(std::string const & type);
        Cure(const Cure &copik);
        Cure &operator = (const Cure &other);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};