#include "banish.h"
using namespace std;

Banish::Banish() : Spell{2}, Desc{"Destroy target minion or ritual"} {}

string Banish::getName() {
    return "Banish";
}

string Banish::getType() {
    return "spell";
}

string Banish::getDesc() {
    return Desc;
}
