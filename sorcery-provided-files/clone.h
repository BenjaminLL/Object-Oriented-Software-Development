#ifndef _CLONE_H_
#define _CLONE_H_
#include "spell.h"
#include <string>

class Clone : public Spell {
protected:
    std::string Desc;
    
public:
    Clone();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};


#endif
