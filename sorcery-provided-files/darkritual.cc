#include "darkritual.h"
using namespace std;

DarkRitual::DarkRitual() : Ritual{0, 1, 5}, Desc{"At the start of your turn, gain 1 magic"} {}

string DarkRitual::getName() {
    return "Dark Ritual";
}

string DarkRitual::getType() {
    return "ritual";
}

string DarkRitual::getDesc() {
    return Desc;
}
