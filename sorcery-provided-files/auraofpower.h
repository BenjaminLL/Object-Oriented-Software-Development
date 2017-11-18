#ifndef _AURAOFPOWER_H_
#define _AURAOFPOWER_H_
#include "ritual.h"
#include <string>

class AuraofPower : public Ritual {
protected:
    std::string Desc;
public:
    AuraofPower();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
