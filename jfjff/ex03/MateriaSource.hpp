#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource:public IMateriaSource
{
    private:
        AMateria *mater[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
	    MateriaSource(MateriaSource const &other);
	    MateriaSource &operator =(const MateriaSource &other);
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif