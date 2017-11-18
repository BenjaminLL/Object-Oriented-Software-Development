#ifndef _FIREELEMENTAL_H_
#define _FIREELEMENTAL_H_
#include "minion.h"
#include <string>

class FireElemental : public Minion {
protected:
    std::string Desc;
public:
    FireElemental();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
    
};

#endif
