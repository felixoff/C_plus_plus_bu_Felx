#include "SuperTrap.hpp"

int main( void )
{
    SuperTrap anonim4;
    SuperTrap notAnonim4("sjennett");
    SuperTrap clone(anonim4);
    clone = notAnonim4;
    
    std::cout << std::endl;

    notAnonim4.rangedAttack("droid");
    notAnonim4.meleeAttack("someone");

    std::cout << std::endl;
}