#ifndef _EARTHELEMENTAL_H_
#define _EARTHELEMENTAL_H_
#include "minion.h"
#include <string>

class EarthElemental : public Minion {
protected:
    std::string Desc;
public:
    EarthElemental();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;

};

#endif
