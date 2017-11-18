#include "airelemental.h"
using namespace std;

AirElemental::AirElemental() : Minion{0, 1, 1}, Desc{""} {}

string AirElemental::getName() {
    return "Air Elemental";
}

string AirElemental::getType() {
    return "minion_no_ability";
}

string AirElemental::getDesc() {
    return Desc;
}

