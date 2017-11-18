#include "collection.h"
#include "cards.h"
#include "enchantments.h"
#include "giantstrength.h"
#include "magicfatigue.h"
#include "silence.h"
#include "damage.h"
#include "ritual.h"
#include "auraofpower.h"
#include "darkritual.h"
#include "lightritual.h"
#include "standstill.h"
#include "spell.h"
#include "disenchant.h"
#include "banish.h"
#include "blizzard.h"
#include "recharge.h"
#include "clone.h"
#include "unsummon.h"
#include "raisedead.h"
#include "minion.h"
#include "airelemental.h"
#include "earthelemental.h"
#include "fireelemental.h"
#include "healer.h"
#include "potionseller.h"
#include "novicepyromancer.h"
#include "mastersummoner.h"
#include "apprenticesummoner.h"


using namespace std;

Collection::Collection() {}
Collection::~Collection() {}

void Collection::attach(shared_ptr<Cards> c) {
	col.emplace_back(c);
}

void Collection::detach(shared_ptr<Cards> c) {
	for (auto it = col.begin(); it != col.end(); ++it) {
		if (*it == c) {
			col.erase(it);
			break;
		}
	}
}



void Collection::setNum(int num) {
	this->num = num;
}

int Collection::getNum() {
    return num;
}




vector<shared_ptr<Cards>> &Collection::getcards() {
	return col;
}

shared_ptr<Cards> Collection::getcard(int i) {
	return col[i];
}


shared_ptr<Cards> getRitual() {
    shared_ptr<Cards> a;
    return a;
}

void setRitual_on_cards(std::shared_ptr<Cards> new_ritual) {}
bool hasRitual() {return false;}

void shuffle() {}




