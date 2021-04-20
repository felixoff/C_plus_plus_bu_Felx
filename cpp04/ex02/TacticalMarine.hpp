#include "Squad.hpp"
class TacticalMarine:public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	TacticalMarine &operator =(TacticalMarine const &other);
	virtual ~TacticalMarine();
	virtual ISpaceMarine* clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;
};
