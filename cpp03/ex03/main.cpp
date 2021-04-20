#include "NinjaTrap.hpp"

int main( void )
{
    ClapTrap anonim1;
    ClapTrap notAnonim1("sjennett");
    ClapTrap clon1(notAnonim1);
    ClapTrap  peer1;
    peer1 = anonim1;

    ScavTrap anonim2;
    ScavTrap notAnonim2("sjennett");
    ScavTrap clon2(notAnonim2);
    ScavTrap  peer2;
    peer2 = anonim2;

    FragTrap anonim3;
    FragTrap notAnonim3("sjennett");
    FragTrap clon3(notAnonim3);
    FragTrap  peer3;
    peer3 = anonim3;

    NinjaTrap anonim4;
    NinjaTrap notAnonim4("sjennett");
    
    std::cout << std::endl;

    clon1.rangedAttack("droid");
    clon1.meleeAttack("someone");
    clon1.takeDamage(93);
    clon1.takeDamage(32);
    clon1.beRepaired(120);
    clon1.takeDamage(99);
    clon1.recoverEnergy(87);

    std::cout << std::endl;

    clon2.rangedAttack("droid");
    clon2.meleeAttack("someone");
    clon2.takeDamage(93);
    clon2.takeDamage(32);
    clon2.beRepaired(120);
    clon2.takeDamage(99);
    clon2.recoverEnergy(87);
    clon2.challengeNewcomer();
    clon2.challengeNewcomer();
    clon2.challengeNewcomer();
    peer2.challengeNewcomer();
    peer2.challengeNewcomer();
    
    std::cout << std::endl;
   
    clon3.rangedAttack("droid");
    clon3.meleeAttack("someone");
    clon3.takeDamage(93);
    clon3.takeDamage(32);
    clon3.beRepaired(120);
    clon3.takeDamage(99);
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.recoverEnergy(87);
    clon3.vaulthunter_dot_exe("sjennett");
    clon3.vaulthunter_dot_exe("sjennett");
    
    std::cout << std::endl;

    notAnonim4.rangedAttack("droid");
    notAnonim4.meleeAttack("someone");
    notAnonim4.takeDamage(93);
    notAnonim4.takeDamage(32);
    notAnonim4.beRepaired(120);
    notAnonim4.takeDamage(99);
    notAnonim4.recoverEnergy(87);
    anonim4.ninjaShoebox(clon1);
    anonim4.ninjaShoebox(clon2);
    anonim4.ninjaShoebox(clon3);
    anonim4.ninjaShoebox(notAnonim4);
    std::cout << std::endl;
}