#include "ISquad.hpp"

class Squad:public ISquad
{
private:
	int count;
	ISpaceMarine **units;
public:
	Squad();
	Squad(Squad const &other);
	Squad &operator =(const Squad &other);
	virtual ~Squad();
	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int i) const;
	virtual int push(ISpaceMarine* unit);
};
