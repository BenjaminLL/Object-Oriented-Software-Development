#include "auraofpower.h"
using namespace std;

AuraofPower::AuraofPower() : Ritual{1, 1, 4}, Desc{"Whenever a minion enters play under your control, it gamins +1/+1"} {}

string AuraofPower::getName() {
    return "Aura of Power";
}

string AuraofPower::getType() {
    return "ritual";
}

string AuraofPower::getDesc() {
    return Desc;
}
