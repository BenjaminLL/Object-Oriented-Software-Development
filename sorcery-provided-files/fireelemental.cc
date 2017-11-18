#include "fireelemental.h"
using namespace std;

FireElemental::FireElemental() : Minion{2, 2, 2}, Desc{"Whenever an opponent's minion enters play, deal 1 damage to it."} {}

string FireElemental::getName() {
    return "Fire Elemental";
}

string FireElemental::getType() {
    return "minion_triggered_ability";
}

string FireElemental::getDesc() {
    return Desc;
}


