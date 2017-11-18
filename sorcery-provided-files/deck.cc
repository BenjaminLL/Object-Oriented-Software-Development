#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <utility>
#include <sstream>
#include <fstream>
#include "airelemental.h"
#include "earthelemental.h"
#include "fireelemental.h"
#include "potionseller.h"
#include "novicepyromancer.h"
#include "apprenticesummoner.h"
#include "mastersummoner.h"
#include "healer.h"
#include "banish.h"
#include "unsummon.h"
#include "recharge.h"
#include "disenchant.h"
#include "raisedead.h"
#include "blizzard.h"
#include "clone.h"
#include "lightritual.h"
#include "darkritual.h"
#include "auraofpower.h"
#include "standstill.h"
#include "giantstrength.h"
#include "magicfatigue.h"
#include "silence.h"
#include "damage.h"
using namespace std;

Deck::Deck(string deck) {
    ifstream file{deck};
    string name;
    
    while(1) {
        getline(file,name);
        if (!file) break;
        
        if (name == "Air Elemental") {
            attach(make_shared<AirElemental>());
        } else if (name == "Earth Elemental") {
            attach(make_shared<EarthElemental>());
        } else if (name == "Fire Elemental") {
            attach(make_shared<FireElemental>());
        } else if (name == "Potion Seller") {
            attach(make_shared<PotionSeller>());
        } else if (name == "Novice Pyromancer") {
            attach(make_shared<NovicePyromancer>());
        } else if (name == "Apprentice Summoner") {
            attach(make_shared<ApprenticeSummoner>());
        } else if (name == "Master Summoner") {
            attach(make_shared<MasterSummoner>());
        } else if (name == "Healer") {
            attach(make_shared<Healer>());
        } else if (name == "Banish") {
            attach(make_shared<Banish>());
        } else if (name == "Unsummon") {
            attach(make_shared<Unsummon>());
        } else if (name == "Recharge") {
            attach(make_shared<Recharge>());
        } else if (name == "Disenchant") {
            attach(make_shared<Disenchant>());
        } else if (name == "Raise Dead") {
            attach(make_shared<RaiseDead>());
        } else if (name == "Blizzard") {
            attach(make_shared<Blizzard>());
        } else if (name == "Clone") {
            attach(make_shared<Clone>());
        } else if (name == "Light Ritual") {
            attach(make_shared<LightRitual>());
        } else if (name == "Dark Ritual") {
            attach(make_shared<DarkRitual>());
        } else if (name == "Aura of Power") {
            attach(make_shared<AuraofPower>());
        } else if (name == "Standstill") {
            attach(make_shared<StandStill>());
        } else if (name == "Giant Strength") {
            attach(make_shared<GiantStrength>());
        } else if (name == "Magic Fatigue") {
            attach(make_shared<MagicFatigue>());
        } else if (name == "Silence") {
            attach(make_shared<Silence>());
        } else if (name == "Damage") {
            attach(make_shared<Damage>());
        }
   
  }
    num = col.size();

}

Deck::~Deck() {}

void Deck::shuffle() {
	srand(time(NULL));
	vector<shared_ptr<Cards>> new_list;
	int loop = num;
	for (int i = 0; i < num; ++i) {
		int temp = rand() % loop;
		new_list.emplace_back(col[temp]);
		detach(col[temp]);
		--loop;
	}

	swap(new_list, col);
}

