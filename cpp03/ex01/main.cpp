#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap anonim;
    ScavTrap notAnonim("sjennett");
    ScavTrap clon(notAnonim);
    ScavTrap  peer;
    peer = anonim;

    clon.rangedAttack("droid");
    clon.meleeAttack("someone");
    clon.takeDamage(93);
    clon.takeDamage(32);
    clon.beRepaired(120);
    clon.takeDamage(99);
    clon.recoverEnergy(87);
    clon.challengeNewcomer();
    clon.challengeNewcomer();
    clon.challengeNewcomer();
    peer.challengeNewcomer();
    peer.challengeNewcomer();
    return 0;
}