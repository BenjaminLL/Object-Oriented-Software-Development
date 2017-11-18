#include "enchantments.h"
#include <memory>
using namespace std;

Enchantments::Enchantments(int cost): Minion{cost,0,0} {}

Enchantments::~Enchantments() {}

void Enchantments::setComp(shared_ptr<Cards> enchant) {
    component = enchant;
}

shared_ptr<Cards> Enchantments::getComp() {
    return component;
}

shared_ptr<Cards> Enchantments::getPrev() {
    return prev;
}

void Enchantments::setPrev(shared_ptr<Cards> enchant) {
    prev = enchant;
}
