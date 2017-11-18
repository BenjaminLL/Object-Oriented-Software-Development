#include "enchantments.h"
#include "damage.h"
using namespace std;

Damage::Damage() :Enchantments{2} {}

string Damage::getDesc() {
    return "Deal 3 damage to opposite player";
}

string Damage::getName() {
	return "Damage";
}

string Damage::getType() {
	return "enchantment";
}
