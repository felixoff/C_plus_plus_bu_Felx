#include "Squad.hpp"

int Squad::getCount() const
{
	return this->count;
}

Squad::~Squad()
{
	int i = 0;
	while (this->units[i])
	{
		delete this->units[i];
		i++;
	}
	delete this->units;
}

ISpaceMarine *Squad::getUnit(int i) const
{
	if (i > this->count - 1 || this->count < 1)
		return NULL;
	else
	{
		return this->units[i];
	}
}

Squad::Squad():count(0),units(NULL)
{
}

Squad::Squad(Squad const &other)
{
	this->count = 0;
	int i = 0;
	while (i < other.count)
	{
		this->count = this->push(other.units[i]);
		i++;
	}
}

Squad &Squad::operator =(const Squad &other)
{
	int i = 0;
	while (i < this->count)
	{
		delete this->units[i];
		i++;
	}
	delete this->units;
	this->units = NULL;
	this->count = 0;
	while (i < other.count)
	{
		this->count = this->push(other.units[i]);
		i++;
	}
	return *this;
}

int Squad::push(ISpaceMarine* unit)
{
	if (this->count > 0)
	{
		int i = 0;
		while (i < this->count)
		{
			if (this->units[i] == unit)
				return(this->count);
			i++;
		}
		ISpaceMarine **cpy = new ISpaceMarine*[this->count + 1];
		i  = 0;
		while (i < this->count)
		{
			cpy[i] = this->units[i];
			i++;
		}
		delete[] this->units;
		this->units = cpy;
		this->count++;
		this->units[this->count - 1] = unit;
	}
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->count  = 1;
	}
	return this->count;
}
