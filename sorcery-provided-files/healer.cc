#include "healer.h"
using namespace std;

Healer::Healer() : Minion{2, 1, 1}, Desc{"Heal 2 HP when healer enters play."} {}

string Healer::getName() {
    return "Healer";
}

string Healer::getType() {
    return "minion_triggered_ability";
}

string Healer::getDesc() {
    return Desc;
}
