#pragma once
#include "./IMateriaSource.hpp"
#include "./AMateria.hpp"

class MateriaSource:public IMateriaSource
{
    private:
	    AMateria *slot[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copik);
        MateriaSource& operator=(const MateriaSource &other);
        ~MateriaSource();
    public:
        void learnMateria(AMateria* nor);
	    AMateria* createMateria (std::string const &);
};