#ifndef _GIANTSTRENGTH_H_
#define _GIANTSTRENGTH_H_
#include "cards.h"
#include "enchantments.h"
#include <string>

class GiantStrength : public Enchantments {
public:
    GiantStrength();
    std::string getType() override;
    std::string getName() override;
    std::string getDesc() override;
    std::string getAttack_entan() override;
    std::string getDefence_entan() override;
    
};


#endif
