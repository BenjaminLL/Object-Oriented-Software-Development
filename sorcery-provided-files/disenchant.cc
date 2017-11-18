#include "disenchant.h"
using namespace std;

Disenchant::Disenchant() : Spell{1}, Desc{"Destroy the top enchantment on target minion"} {}

string Disenchant::getName() {
    return "Disenchant";
}

string Disenchant::getType() {
    return "spell";
}

string Disenchant::getDesc() {
    return Desc;
}
