#include "magicfatigue.h"
#include "enchantments.h"
using namespace std;

MagicFatigue::MagicFatigue(): Enchantments{0} {}

string MagicFatigue::getType() {
	return "enchantment";
}

string MagicFatigue::getDesc() {
    return "Enchanted minion's activated ability costs 2 more";
}

string MagicFatigue::getName() {
	return "Magic Fatigue";
}
