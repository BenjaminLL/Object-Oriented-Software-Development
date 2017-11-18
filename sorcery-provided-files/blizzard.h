#ifndef _BLIZZARD_H_
#define _BLIZZARD_H_
#include "spell.h"
#include <string>

class Blizzard : public Spell {
protected:
    std::string Desc;
    
public:
    Blizzard();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
