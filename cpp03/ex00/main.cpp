#include "FragTrap.hpp"

int main( void )
{
    FragTrap anonim;
    FragTrap notAnonim("sjennett");
    FragTrap clon(notAnonim);
    FragTrap  peer;
    peer = anonim;

    clon.rangedAttack("droid");
    clon.meleeAttack("someone");
    clon.takeDamage(93);
    clon.takeDamage(32);
    clon.beRepaired(120);
    clon.takeDamage(99);
    clon.vaulthunter_dot_exe("sjennett");
    clon.vaulthunter_dot_exe("sjennett");
    clon.vaulthunter_dot_exe("sjennett");
    clon.vaulthunter_dot_exe("sjennett");
    clon.vaulthunter_dot_exe("sjennett");
    clon.recoverEnergy(87);
    clon.vaulthunter_dot_exe("sjennett");
    clon.vaulthunter_dot_exe("sjennett");
    return 0;
}
