#ifndef _LIGHTRITUAL_H_
#define _LIGHTRITUAL_H_
#include "ritual.h"
#include <string>

class LightRitual : public Ritual {
protected:
    std::string Desc;
public:
    LightRitual();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
