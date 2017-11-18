#ifndef _DISENCHANT_H_
#define _DISENCHANT_H_
#include "spell.h"
#include <string>

class Disenchant : public Spell {
protected:
    std::string Desc;
    
public:
    Disenchant();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
