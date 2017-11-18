#ifndef _HEALER_H_
#define _HEALER_H_
#include "minion.h"
#include <string>

class Healer : public Minion {
protected:
    std::string Desc;
public:
    Healer();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
};

#endif
