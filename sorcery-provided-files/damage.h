#ifndef _DAMAGE_H_
#define _DAMAGE_H_
#include "cards.h"
#include "enchantments.h"
#include <string>

class Damage : public Enchantments {
public:
    Damage();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};


#endif
