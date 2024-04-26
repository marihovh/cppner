#include "./Character.hpp"

Character::Character()
{
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		this->slot[i] = NULL;
	}
}

void Character::setName(std::string &name)
{
    this->name = name;
}

std::string const & Character::getName() const
{
    return this->name;
}

Character::Character(std::string const &name)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    this->name = name;
};

Character::Character(const Character& copik)
{
    *this = copik;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete this->slot[i];
            this->slot[i] = other.slot[i]->clone();
        }
    }
    return *this;
}

void Character::equip(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
            if (this->slot[i] == m)
                return ;
        for (int i = 0; i < 4; i++)
            if (!this->slot[i])
                this->slot[i] = m;
    }
    std::cout << "Materia chka\n";
}

void Character::unequip(int idx)
{
    if (this->slot[idx])
    {
        delete this->slot[idx];
        this->slot[idx] = NULL;
    }
    else
        std::cout << "aaaaa\n";
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 4 && this->slot[idx])
    {
        this->slot[idx]->use(target);
    }
    else
	    std::cout << "Materia Doesn't Exist\n";
}