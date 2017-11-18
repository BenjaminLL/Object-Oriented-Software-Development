#ifndef _BANISH_H_
#define _BANISH_H_
#include "spell.h"
#include <string>

class Banish : public Spell {
protected:
    std::string Desc;
public:
    Banish();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
