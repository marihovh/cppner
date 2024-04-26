#pragma once
#include "./ICharacter.hpp"
#include <iostream>
class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        std::string const &getType() const;
        AMateria();
        void setType(std::string const &type);
        AMateria(const AMateria& copik);
        AMateria& operator=(const AMateria& other);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria();
};