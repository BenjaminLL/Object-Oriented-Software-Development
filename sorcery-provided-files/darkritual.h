#ifndef _DARKRITUAL_H_
#define _DARKRITUAL_H_
#include "ritual.h"
#include <string>

class DarkRitual : public Ritual {
protected:
    std::string Desc;
public:
    DarkRitual();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};


#endif
