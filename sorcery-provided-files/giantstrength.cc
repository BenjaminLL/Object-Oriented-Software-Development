#include "enchantments.h"
#include "giantstrength.h"
using namespace std;

GiantStrength::GiantStrength(): Enchantments{1} {}

string GiantStrength::getType() {
    return "enchantment_attack_defence";

}

string GiantStrength::getDesc() {
    return "";
}

string GiantStrength::getAttack_entan() {
    return "+2";
}

string GiantStrength::getDefence_entan() {
    return "+2";
}

string GiantStrength::getName() {
    return "Giant Strength";
}
