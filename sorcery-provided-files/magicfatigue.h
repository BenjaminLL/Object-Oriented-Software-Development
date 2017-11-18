#ifndef _MAGICFATIGUE_H_
#define _MAGICFATIGUE_H_
#include "cards.h"
#include "enchantments.h"
#include <string>

class MagicFatigue : public Enchantments {
public:
    MagicFatigue();
    std::string getType() override;
    std::string getDesc() override;
    std::string getName() override;
};

#endif
