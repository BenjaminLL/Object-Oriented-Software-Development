#include "cards.h"
using namespace std;

Cards::Cards(int cost): cost{cost} {}

Cards::~Cards() {}

int Cards::getcost() {
    return cost;
}

void setRitual(shared_ptr<Cards> new_ritual) {}

int getAttack() {return 1;}
int getDefence() {return 1;}
void getAttacked(int i) {}

string getAttack_entan() {return "";}
string getDefence_entan() {return "";}

string getType() {return "";}
string getName() {return "";}
int getAbilityCost() {return 1;}

int getRitualCost() {return 1;}
int getRitualCharges() {return 1;}
void addRitualCharges(int i) {}

void addExtraAtk(int i) {}
void addExtraDef(int i) {}
void addExtraCost(int i) {}

bool isSilence() {return false;}
void setSilence(bool b) {}

shared_ptr<Cards> getEnchant() {
    shared_ptr<Cards> a;
    return a;
}
void setEnchant(std::shared_ptr<Cards> en) {}
shared_ptr<Cards> getComp(){
    shared_ptr<Cards> a;
    return a;
}
void setComp(std::shared_ptr<Cards> enchant) {}
shared_ptr<Cards> getPrev() {
    shared_ptr<Cards> a;
    return a;
}
void setPrev(std::shared_ptr<Cards> enchant) {}

void clear() {}
void clear_extra_cost() {}

void inspect() {}

string no_enchant(shared_ptr<Cards> c) {return "";}
