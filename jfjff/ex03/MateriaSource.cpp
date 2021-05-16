#include "MateriaSource.hpp"



MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
}

MateriaSource &MateriaSource::operator =(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
        delete this->mater[i];
    for (int i = 0; i < 4; i++)
        this->mater[i] = other.mater[i];
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (m && this->mater[i] == NULL)
        {
            this->mater[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0;i < 4; i++)
    {
        if (this->mater[i]->getType() == type)
        {
            return this->mater[i]->clone();
        }
    }
    return 0;
}
