#include "lightritual.h"
using namespace std;

LightRitual::LightRitual() : Ritual{2, 1, 3}, Desc{"At the start of your turn, draw 1 more card"} {}

string LightRitual::getName() {
    return "Light Ritual";
}

string LightRitual::getType() {
    return "ritual";
}

string LightRitual::getDesc() {
    return Desc;
}
