#ifndef _APPRENTICESUMMONER_H_
#define _APPRENTICESUMMONER_H_
#include "minion.h"
#include <string>

class ApprenticeSummoner : public Minion {
protected:
    std::string Desc;
    int ability_cost;
    int extra_cost = 0;
public:
    ApprenticeSummoner();
    std::string getName() override;
    std::string getType() override;
    std::string getDesc() override;
    int getAbilityCost() override;
    void addExtraCost(int i) override;
    void clear_extra_cost() override;
};

#endif
