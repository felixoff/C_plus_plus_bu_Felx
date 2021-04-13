#include<iostream>
class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {}
	virtual ISpaceMarine* clone() const = 0;
	virtual void battleCry() const = 0;
	virtual void rangedAttack() const = 0;
	virtual void meleeAttack() const = 0;
};

class TacticalMarine:public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	TacticalMarine &operator =(TacticalMarine const &other);
	virtual ~TacticalMarine();
	virtual ISpaceMarine* clone() const override;
	virtual void battleCry() const override;
	virtual void rangedAttack() const override;
	virtual void meleeAttack() const override;
};

TacticalMarine::TacticalMarine()
{
	std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &other)
{
	std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout<<"Aaargh..."<<std::endl;
}

void TacticalMarine::battleCry() const
{
	std::cout<< "For the holy PLOT!"<<std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout<< "* attacks with a bolter *"<<std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout<< "* attacks with a chainsword *"<<std::endl;
}

ISpaceMarine *TacticalMarine::clone() const
{
	ISpaceMarine *clone = new TacticalMarine();
	return clone;
}

TacticalMarine &TacticalMarine::operator =(TacticalMarine const &other)
{
	return *this;
}

class AssaultTerminator:public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &other);
	AssaultTerminator &operator =(AssaultTerminator const &other);
	virtual ~AssaultTerminator();
	virtual ISpaceMarine* clone() const override;
	virtual void battleCry() const override;
	virtual void rangedAttack() const override;
	virtual void meleeAttack() const override;
};

AssaultTerminator::AssaultTerminator()
{
	std::cout<<"* teleports from space *"<<std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other)
{
	std::cout<<"* teleports from space *"<<std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout<< "I'll be back..."<<std::endl;
}

void AssaultTerminator::battleCry() const
{
	std::cout<< "This code is unclean. PURIFY IT!"<<std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout<< "* does nothing *"<<std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout<< "* attacks with chainfists *"<<std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	ISpaceMarine *clone = new AssaultTerminator();
	return clone;
}

AssaultTerminator &AssaultTerminator::operator =(AssaultTerminator const &other)
{
	return *this;
}

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) const = 0;
	virtual int push(ISpaceMarine*) = 0;
};


class Squad:public ISquad
{
private:
	ISpaceMarine **units;
	int count;
public:
	Squad();
	Squad(Squad const &other);
	Squad &operator =(const Squad &other);
	virtual ~Squad();
	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int i) const;
	virtual int push(ISpaceMarine* unit);
};

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

int main()
{
ISpaceMarine* bob = new TacticalMarine;
ISpaceMarine* jim = new AssaultTerminator;
ISquad* vlc = new Squad;
vlc->push(bob);
vlc->push(jim);
for (int i = 0; i < vlc->getCount(); ++i)
{
	ISpaceMarine* cur = vlc->getUnit(i);
	cur->battleCry();
	cur->rangedAttack();
	cur->meleeAttack();
}
delete vlc;
return 0;
}
