#include "clone.h"
using namespace std;

Clone::Clone() : Spell{2}, Desc{"Summon a same minion to the target minion"} {}

string Clone::getName() {
    return "Clone";
}

string Clone::getType() {
    return "spell";
}

string Clone::getDesc() {
    return Desc;
}
