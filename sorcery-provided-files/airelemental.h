#ifndef _AIRELEMENTAL_H_
#define _AIRELEMENTAL_H_
#include "minion.h"
#include <string>

class AirElemental : public Minion {
protected:
    std::string Desc;
    
public:
    AirElemental();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
    
    
};

#endif
