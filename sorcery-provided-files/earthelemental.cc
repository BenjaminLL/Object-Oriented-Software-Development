#include "earthelemental.h"
using namespace std;

EarthElemental::EarthElemental() : Minion{3, 4, 4}, Desc{""} {}

string EarthElemental::getName() {
    return "Earth Elemental";
}

string EarthElemental::getType() {
    return "minion_no_ability";
}

string EarthElemental::getDesc() {
    return Desc;
}


