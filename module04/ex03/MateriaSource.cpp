#include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std:: cout << "Default constructor of MateriaSource\n";
    for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copik)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		this->slot[i] = copik.slot[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->slot[i];
			this->slot[i] = other.slot[i]->clone();
		}
	}
	return(*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		this->slot[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* nor)
{
    for (int i = 0; i < 4; i++)
	{
        std::cout << "asas\n";
		if(this->slot[i] == nor)
			return;
		if (!this->slot[i])
		{
			this->slot[i] = nor;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] && this->slot[i]->getType() == type)
            return (this->slot[i]->clone());
    }
    std::cout << "Can't find the Materia\n";
    return (0);
}