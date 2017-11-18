#include "blizzard.h"
using namespace std;

Blizzard::Blizzard() : Spell{3}, Desc{"Deal 2 damage to all minions"} {}

string Blizzard::getName() {
    return "Blizzard";
}

string Blizzard::getType() {
    return "spell";
}

string Blizzard::getDesc() {
    return Desc;
}
