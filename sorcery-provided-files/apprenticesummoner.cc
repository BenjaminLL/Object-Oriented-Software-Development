#include "apprenticesummoner.h"
using namespace std;

ApprenticeSummoner::ApprenticeSummoner() : Minion{1, 1, 1}, Desc{"Summon a 1/1 air elemental"}, ability_cost{1} {}

string ApprenticeSummoner::getName() {
    return "Apprentice Summoner";
}

string ApprenticeSummoner::getType() {
    return "minion_activated_ability";
}

string ApprenticeSummoner::getDesc() {
    return Desc;
}

int ApprenticeSummoner::getAbilityCost() {
    return ability_cost + extra_cost;
}


void ApprenticeSummoner::addExtraCost(int i) {
    extra_cost += i;
}

void ApprenticeSummoner::clear_extra_cost() {
    extra_cost = 0;
}
