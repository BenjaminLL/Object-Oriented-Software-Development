#include <iostream>
#include <fstream>
#include "ascii_graphics.h"
#include "game.h"
#include "cards.h"
#include "collection.h"
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



Game::Game() {}


void Game::begin_ritual(int player) {
    shared_ptr<Collection> board = players[player].getCollection(3);
    if (board->hasRitual()) {
	string name = board->getRitual()->getName();
	if (name == "Dark Ritual") players[player].changeMagic(1);
    }
}

void Game::end_ritual(int player) {
    vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
    for (unsigned i = 0; i < minions_list.size(); i++) {
        string minion_type = minions_list[i]->getName();
        if (minion_type == "Potion Seller") {
            for (unsigned j = 0; j < minions_list.size(); j++) {
                minions_list[j]->addExtraDef(1);
            }
        }
    }
}


void Game::getMagic(int player) {
    players[player].changeMagic(1);
}



void Game::initial(string deck1, string deck2, bool test, string name1,
				string name2) {
	Player player1{name1};
	Player player2{name2};
	players.push_back(player1);
	players.push_back(player2);

	this->test = test;

	players[0].initial(deck1,test);
	players[1].initial(deck2,test);


}

void Game::draw(int player) {
	players[player].drawCard();
}	

void Game::discard(int player, int pos) {
	players[player].discard(pos);
}

void Game::attack(int player, int pos) {

    if (players[player].getCollection_of_cards(3)[pos]->getMoved()) {
        cout << "This minion has already been used once." << endl;
        return;
    }

	int i = player==player1_pos?1:0;

	int attack = players[player].getAttack(pos);

    try {
        players[i].getAttacked(attack);
    } catch (string m) {
        throw m;
    }
    players[player].getCollection_of_cards(3)[pos]->setMoved(true);
}

void Game::attack(int player, int pos, int target) {
    if (players[player].getCollection_of_cards(3)[pos]->getMoved()) {
        cout << "This minion has already been used once." << endl;
        return;
    }

    players[player].getCollection_of_cards(3)[pos]->setMoved(true);
	
    int i = player==player1_pos?1:0;
	int attack = players[player].getAttack(pos);
	
    vector<shared_ptr<Cards>> &minions = players[i].getCollection_of_cards(3);

    minions[target]->getAttacked(attack);
    int defence = minions[target]->getDefence();
    if (defence <= 0) {

        players[player].getCollection_of_cards(3)[pos]->setMoved(false);
        shared_ptr<Collection> grave = players[i].getCollection(2);
        minions[target]->setDamage(false);
        minions[target]->clear();
        minions[target]->clear_extra_cost();
        grave->attach(minions[target]);
        minions.erase(minions.begin()+target);
    }
    
    
    
    int attack_i = players[i].getAttack(target);
    vector<shared_ptr<Cards>> &minions_player = players[player].getCollection_of_cards(3);
    minions_player[pos]->getAttacked(attack_i);
    int defence_player = minions_player[pos]->getDefence();
    if (defence_player <= 0) {
        
        players[player].getCollection_of_cards(3)[pos]->setMoved(false);
        shared_ptr<Collection> grave = players[player].getCollection(2);
        minions_player[pos]->setDamage(false);
        minions_player[pos]->clear();
        minions_player[pos]->clear_extra_cost();
        grave->attach(minions_player[pos]);
        minions_player.erase(minions_player.begin()+pos);
    }
    
}

void Game::play(int player, int pos, bool test) {
    if (players[player].getCollection_of_cards(1).size() < pos + 1) {
        cout << "hand card in pos does not exist" << endl; // hand card in pos does not exist
    }
    else {
        vector<shared_ptr<Cards>>& hand_list = players[player].getCollection_of_cards(1);
        string card_type = hand_list[pos]->getType();
        
        if (card_type == "minion_no_ability" || card_type == "minion_triggered_ability" || card_type == "minion_activated_ability") {
           
	    int magic = players[player].getMagic();
	    string name = hand_list[pos]->getName();
	    if (name == "Novice Pyromancer" || name == "Apprentice Summoner") {
            
            if (magic < 1) {
                if (!test) {
                    cout << "There is no enough magic" << endl;
                    return;
                } else {
                    players[player].changeMagic(-magic);
                }
            } else {
                players[player].changeMagic(-1);
            }
	    } else if (name == "Fire Elemental" || name == "Potion Seller" || name == "Healer") {
            
            if (magic < 2) {
                if (!test) {
                    cout << "There is no enough magic" << endl;
                    return;
                } else {
                    players[player].changeMagic(-magic);
                }
            } else {
                players[player].changeMagic(-2);
            }
	    } else if (name == "Earth Elemental" || name == "Master Summoner"){
            
            if (magic < 3) {
                if (!test) {
                    cout << "There is no enough magic" << endl;
                    return;
                } else {
                    players[player].changeMagic(-magic);
                }
            } else {
                players[player].changeMagic(-3);
            }
	   }
            hand_list[pos]->setMoved(true);
            vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
            minions_list.push_back(hand_list[pos]);
            hand_list.erase(hand_list.begin()+pos);
            

            
            bool isRitual = players[player].getCollection(3)->hasRitual();
            if (isRitual) {
                shared_ptr<Cards> ritual_board = players[player].getCollection(3)->getRitual();
                string ritual_name = ritual_board->getName();
                int charges = ritual_board->getRitualCharges();
                
                if (ritual_name == "Aura of Power") {
                    if (charges >= 1) {
                        minions_list[minions_list.size() - 1]->addExtraAtk(1);
                        minions_list[minions_list.size() - 1]->addExtraDef(1);
                        ritual_board->addRitualCharges(-1);
                    }
                } else if (ritual_name == "Standstill"){
                    if (charges >= 2) {
                        minions_list[minions_list.size() - 1]->setMoved(false);
                        ritual_board->addRitualCharges(-2);
                        shared_ptr<Collection> greva = players[player].getCollection(2);
                        minions_list[minions_list.size() - 1]->setDamage(false);
                        minions_list[minions_list.size() - 1]->clear();
                        minions_list[minions_list.size() - 1]->clear_extra_cost();
                        greva->attach(minions_list[minions_list.size() - 1]);
                        minions_list.pop_back();
                        return;
                    }
                
                }
                
            }
            
            
            
            int target_player = player == 1?0:1;
            bool ritual_oppo = players[target_player].getCollection(3)->hasRitual();
            vector<shared_ptr<Cards>>& minions_list_opps = players[target_player].getCollection_of_cards(3);
            string name_minion = "";
            for (auto i : minions_list_opps) {
                name_minion = i->getName();
                if (name_minion == "Fire Elemental") {
                    minions_list[minions_list.size() - 1]->getAttacked(1);
                    int defence = minions_list[minions_list.size() - 1]->getDefence();
                    if (defence <= 0) {
                        minions_list[minions_list.size() - 1]->setMoved(false);
                        shared_ptr<Collection> grave = players[player].getCollection(2);
                        minions_list[minions_list.size() - 1]->setDamage(false);
                        minions_list[minions_list.size() - 1]->clear();
                        minions_list[minions_list.size() - 1]->clear_extra_cost();
                        grave->attach(minions_list[minions_list.size() - 1]);
                        minions_list.pop_back();
                        return;
                        
                    }
                }
            }
            
            if (ritual_oppo) {
                shared_ptr<Cards> ritual_board = players[target_player].getCollection(3)->getRitual();
                string ritual_name = ritual_board->getName();

                if (ritual_name == "Standstill") {
                    int charges = ritual_board->getRitualCharges();
                    if (charges >= 2) {
                        minions_list[minions_list.size() - 1]->setMoved(false);
                        ritual_board->addRitualCharges(-2);
                        shared_ptr<Collection> greva = players[player].getCollection(2);
                        minions_list[minions_list.size() - 1]->setDamage(false);
                        minions_list[minions_list.size() - 1]->clear();
                        minions_list[minions_list.size() - 1]->clear_extra_cost();
                        greva->attach(minions_list[minions_list.size() - 1]);
                        minions_list.pop_back();
                        
                    }

                    
                }
            }
            
        
        } else if (card_type == "ritual") {
            shared_ptr<Collection> board = players[player].getCollection(3);
            
            if (hand_list[pos]->getName() == "Dark Ritual") {
                board->setRitual_on_cards(hand_list[pos]);
                hand_list.erase(hand_list.begin()+pos);
            } else {
                int magic = players[player].getMagic();
                string name = hand_list[pos]->getName();
                
                if (name == "Aura of Power") {
                    if (magic < 1) {
                        if (!test) {
                            cout << "There is not enough magic" << endl;
                        }
                    } else {
                        board->setRitual_on_cards(hand_list[pos]);
                        if (magic < 1 && test) {
                            players[player].changeMagic(-magic);
                        } else {
                            players[player].changeMagic(-1);
                        }
                        hand_list.erase(hand_list.begin()+pos);
                    }
                } else if (name == "Standstill") {
                    if (magic < 3) {
                        if (!test)
                        cout << "There is not enough magic" << endl;
                    } else {
                        board->setRitual_on_cards(hand_list[pos]);
                        if (magic < 3 && test) {
                            players[player].changeMagic(-magic);
                        } else {
                            players[player].changeMagic(-3);
                        }
                        hand_list.erase(hand_list.begin()+pos);
                    }
                }
            }
        
        } else if (card_type == "spell") {
            string card_name = hand_list[pos]->getName();
            int magic = players[player].getMagic();
            
            if (card_name == "Banish" || card_name == "Unsummon" || card_name == "Disenchant" || card_name == "Clone") {
                
                cout << "this spell needs target" << endl; // this spell needs target
            
            } else if(card_name == "Recharge") {
                if (magic < 1) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                shared_ptr<Collection> board = players[player].getCollection(3);
                if (!board->hasRitual()) {
                    cout << "There is no ritual on the board" << endl;
                } else {
                    board->getRitual()->addRitualCharges(3);
                    hand_list.erase(hand_list.begin()+pos);
                    if (magic < 1 && test) {
                        players[player].changeMagic(-magic);
                    } else {
                        players[player].changeMagic(-1);
                    }
                }
            } else if (card_name == "Raise Dead") {
                if (magic < 1) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
                vector<shared_ptr<Cards>>& graveyard_list = players[player].getCollection_of_cards(2);
                
                if (minions_list.size() >= 5) {
                    cout << "There is no room for new minions." << endl;
                } else if ( graveyard_list.size() == 0) {
                    cout << "There is no cards in graveyard." << endl;
                } else {
                    shared_ptr<Cards> card = graveyard_list[graveyard_list.size() - 1];
                    minions_list.push_back(card);
                    graveyard_list.pop_back();
                    hand_list.erase(hand_list.begin()+pos);
                    if (magic < 1 && test) {
                        players[player].changeMagic(-magic);
                    } else {
                        players[player].changeMagic(-1);
                    }
                }
            } else if (card_name == "Blizzard") {
                
                if (magic < 3) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                for (int i = 0; i < 2; i++) {
                    vector<shared_ptr<Cards>>& target_list = players[i].getCollection_of_cards(3);
                    for (unsigned j = 0; j< target_list.size(); j++) {
                        target_list[j]->getAttacked(2);
                        int defence = target_list[j]->getDefence();
                        if (defence <= 0) {
                            shared_ptr<Collection> graveyard = players[i].getCollection(2);
                            target_list[j]->setDamage(false);
                            target_list[j]->setMoved(false);
                            target_list[j]->clear();
                            target_list[j]->clear_extra_cost();
                            graveyard->attach(target_list[j]);
                            target_list.erase(target_list.begin() + j);
                            
                        }
                    }
                    
                    
                }
                hand_list.erase(hand_list.begin()+pos);
                if (magic < 3 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-3);
                }
            }
        } else if (card_type == "enchantment" || card_type == "enchantment_attack_defence") {
            cout << "play not matched" << endl; // need target
        }
    }
}




void Game::play(int player, int pos, int target_player, int target, bool test) {
    if (players[player].getCollection_of_cards(1).size() <= pos  || players[target_player].getCollection_of_cards(3).size() <= target) {
        cout << players[player].getCollection_of_cards(1).size() << endl;
        cout << players[target_player].getCollection_of_cards(3).size() << endl;
        cout << "pos not correct" << endl;// hand card in pos does not exist
    } else {
        vector<shared_ptr<Cards>>& hand_list = players[player].getCollection_of_cards(1);
        string card_type = hand_list[pos]->getType();
        int magic = players[player].getMagic();
        
        if (card_type == "minion_no_ability" || card_type == "minion_triggered_ability" || card_type == "minion_activated_ability" || card_type == "ritual") {
            
            cout << "play not matched"  << endl; // does not need target
        
        } else if (card_type == "spell") {
            
            string card_name = hand_list[pos]->getName();
            
            if (card_name == "Recharge" || card_name == "Raise Dead"|| card_name == "Blizzard") {
                
                cout << "spell does not need target" << endl; // spells do not need target
            
            } else if(card_name == "Banish") {
                
                if (magic < 2) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                shared_ptr<Collection> minion = players[target_player].getCollection(3);
                shared_ptr<Collection> grave = players[target_player].getCollection(2);
                grave->attach(minion->getcard(target));
                minion->detach(minion->getcard(target));
                hand_list.erase(hand_list.begin()+pos);
                if (magic < 2 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-1);
                }
                
            } else if (card_name == "Unsummon") {
                
                if (magic < 1) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                shared_ptr<Collection> minion = players[target_player].getCollection(3);
                shared_ptr<Collection> deck = players[target_player].getCollection(0);
                deck->attach(minion->getcard(target));
                minion->detach(minion->getcard(target));
                hand_list.erase(hand_list.begin()+pos);
                if (magic < 1 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-1);
                }
                
            } else if (card_name == "Disenchant") {
                
                vector<shared_ptr<Cards>>& opponent_minions_list = players[target_player].getCollection_of_cards(3);
                
                shared_ptr<Cards> card = opponent_minions_list[target];
                shared_ptr<Cards> top_enchant;
                
                if (card->getEnchant().use_count() == 0) {
                    cout << "There is no enchantments on this minion." << endl;
                } else {
                    
                    if (magic < 1) {
                        if (!test) {
                            cout << "There is not enough magic." << endl;
                            return;
                        }
                    }
                    
                    top_enchant = card->getEnchant();
                    while(top_enchant->getComp().use_count() != 0) {
                        top_enchant = top_enchant->getComp();
                    }
                   
                    shared_ptr<Cards> temp;
                    
                    shared_ptr<Cards> aaa;
                    top_enchant->getPrev()->setComp(aaa);
                    top_enchant->setPrev(temp);
                    
                    string return_string = card->no_enchant(top_enchant);
                    if (return_string == "minion dead") {
                        card->setDamage(false);
                        card->setMoved(false);
                        card->clear();
                        card->clear_extra_cost();
                        shared_ptr<Collection> minion = players[target_player].getCollection(2);
                        minion->attach(card);
                        opponent_minions_list.erase(opponent_minions_list.begin()+target);
                        
                    } else if (return_string == "2") {
                        card->clear_extra_cost();
                    }
                }
                
                hand_list.erase(hand_list.begin()+pos);
                if (magic < 1 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-1);
                }
                
            } else if (card_name == "Clone") {
                
                if (magic < 2) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
                if (minions_list.size() <= 5) {
                    vector<shared_ptr<Cards>>& target_minions_list = players[target_player].getCollection_of_cards(3);
                    minions_list.push_back(target_minions_list[target]);
                }
                hand_list.erase(hand_list.begin()+pos);
                if (magic < 2 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-2);
                }
                
            }
        } else if (card_type == "enchantment" || card_type == "enchantment_attack_defence") {
            string card_name = hand_list[pos]->getName();
            shared_ptr<Cards> target_minion = players[target_player].getCollection_of_cards(3)[target];
            
            if (card_name == "Giant Strength") {
                
                if (magic < 1) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                target_minion->addExtraAtk(2);
                target_minion->addExtraDef(2);
                if (magic < 1 && test) {
                    players[player].changeMagic(-magic);
                } else {
                    players[player].changeMagic(-1);
                }
                
            } else if (card_name == "Magic Fatigue") {
                
                if (magic < 0) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    }
                }
                
                target_minion->addExtraCost(2);
                
            } else if (card_name == "Silence") {
                
                if (magic < 1) {
                    if (!test) {
                        cout << "There is not enough magic." << endl;
                        return;
                    } else {
                        players[player].changeMagic(-magic);
                    }
                } else {
                    players[player].changeMagic(-1);
                }
                
                target_minion->setSilence(true);
                
            } else if (card_name == "Damage") {
                if (magic < 2) {
                    cout << "There is not enough magic" << endl;
                    return;
                }
                target_minion->setDamage(true);
                players[player].changeMagic(-2);
            }
            
            
            
            if(target_minion->getEnchant().use_count() == 0) {
                target_minion->setEnchant(hand_list[pos]);
                hand_list[pos]->setPrev(target_minion);
            
            } else {
                shared_ptr<Cards> enchant = target_minion->getEnchant();
                
                while(1) {
                    if (enchant->getComp().use_count() == 0) {
                        enchant->setComp(hand_list[pos]);
                        hand_list[pos]->setPrev(enchant);
                    } else {
                        enchant = enchant->getComp();
                    }
                }
            }
            
            hand_list.erase(hand_list.begin()+pos);
            
        }
    }
}



void Game::play(int player, int pos, int target_player, bool test) { //use for Banish target with ritual
    
    vector<shared_ptr<Cards>>& hand_list = players[player].getCollection_of_cards(1);
    string name = hand_list[pos]->getName();
    
    if (name != "Banish") {
        cout << "Command is not correct." << endl;
    } else {
        int magic = players[player].getMagic();
        if (magic < 2) {
            if (!test) {
                cout << "There is not enough magic" <<endl;
                return;
            } else {
                players[player].changeMagic(-magic);
            }
        } else {
            players[player].changeMagic(-2);
        }
        shared_ptr<Cards> new_one;
        players[target_player].getCollection(3)->setRitual_on_cards(new_one);
        
        hand_list.erase(hand_list.begin()+pos);
        
    }
    
}




void Game::use(int player, int pos, bool test) {
    
    
    vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
    string minion_type = minions_list[pos]->getName();
    if (minions_list[pos]->isSilence()) {
        cout << "silenced" << endl;
        return;
    }
    
    if (players[player].getCollection_of_cards(3)[pos]->getMoved()) {
        cout << "This minion has already been used once." << endl;
        return;
    }
    
    int magic = players[player].getMagic();
    
    bool damage_use = minions_list[pos]->getDamage();
    if (damage_use) {
        int opposite_player = player == 1?0:1;
        players[player].getAttacked(2);
        return;
    }
    
    if (minion_type == "Air Elemental" || minion_type ==  "Earth Elemental" || minion_type ==  "Fire Elemental" || minion_type == "Potion Seller" || minion_type == "Novice Pyromancer") {
        cout << "cmd not matched" << endl; // these abilities need target
    } else if (minion_type == "Apprentice Summoner") {
        if (magic < 1) {
            if (!test) {
                cout << "not enough magic" << endl;
                return;
            }
        }
        if (minions_list.size() > 0) {
            auto a = make_shared<AirElemental>();
            minions_list.push_back(a);
            if (magic < 1 && test) {
                players[player].changeMagic(-magic);
            } else {
                players[player].changeMagic(-1);
            }
        }
        
        players[player].getCollection_of_cards(3)[pos]->setMoved(true);
        
    } else if (minion_type == "Master Summoner") {
        if (magic < 2) {
            if (!test) {
                cout << "not enough magic" << endl;
                return;
            }
        }
        
        int exist_minions = minions_list.size();
        int i = exist_minions;
        int j = 3;
        for (; exist_minions < 5; exist_minions++) {
            if (j <= 0) break;
            auto a = make_shared<AirElemental>();
            minions_list.push_back(a);
            --j;
        }
        
        if (i < 5){
            if (magic < 2 && test) {
                players[player].changeMagic(-magic);
            } else {
                players[player].changeMagic(-2);
            }
        }
        
        players[player].getCollection_of_cards(3)[pos]->setMoved(true);
    } else if (minion_type == "Healer") {
        if (magic < 1) {
            if (!test) {
                cout << "not enough magic" << endl;
                return;
            } else {
                players[player].changeMagic(-magic);
            }
        } else {
            players[player].changeMagic(-1);
        }
        
        players[player].getAttacked(-2);
        
        
        players[player].getCollection_of_cards(3)[pos]->setMoved(true);
    }
    
    
}



void Game::use(int player, int pos, int target_player, int target, bool test) {
    vector<shared_ptr<Cards>>& minions_list = players[player].getCollection_of_cards(3);
    string minion_type = minions_list[pos]->getName();
    if (minions_list[pos]->isSilence()) {
        cout << "silenced" << endl;
        return;
    }
    
    if (players[player].getCollection_of_cards(3)[pos]->getMoved()) {
        cout << "This minion has already been used once." << endl;
        return;
    }
    
    bool damage_use = minions_list[pos]->getDamage();
    if (damage_use) {
        cout << "Do not need target" << endl;
        return;
    }

    
    
    if (minion_type == "Air Elemental" || minion_type ==  "Earth Elemental" || minion_type ==  "Fire Elemental" || minion_type == "Potion Seller" || minion_type == "Apprentice Summoner" || minion_type == "Master Summoner" || minion_type == "Healer") {
        cout << "these abilities do not need target" << endl; // these abilities do not need target
    } else if (minion_type == "Novice Pyromancer") {
        int magic = players[player].getMagic();
        if (magic < 1) {
            if (!test) {
                cout << "There is not enough magic" << endl;
            }
        } else {
            vector<shared_ptr<Cards>>& opponent_minions_list = players[target_player].getCollection_of_cards(3);
            opponent_minions_list[target]->getAttacked(1);
            if (magic < 1 && test) {
                players[player].changeMagic(-magic);
            } else {
                players[player].changeMagic(-1);
            }
            int defence = opponent_minions_list[target]->getDefence();
            if (defence <= 0) {
                shared_ptr<Collection> graveyard = players[target_player].getCollection(2);
                opponent_minions_list[target]->setDamage(false);
                opponent_minions_list[target]->setMoved(false);
                opponent_minions_list[target]->clear();
                opponent_minions_list[target]->clear_extra_cost();
                graveyard->attach(opponent_minions_list[target]);
                opponent_minions_list.erase(opponent_minions_list.begin() + target);
                
            }
        }
        players[player].getCollection_of_cards(3)[pos]->setMoved(true);
    }
}


void Game::inspect(int whichPlayer, int pos) {
	players[whichPlayer].inspectCard(pos);
}	



void Game::displayBoard() {
	players[0].displayBoard(0);
	
	for (auto i : CENTRE_GRAPHIC) {
		cout << i << endl;
	}
	
	players[1].displayBoard(1);

}

void Game::displayHand(int whichPlayer) {
	if (whichPlayer == player1_pos) {
		players[player1_pos].showHand();
	} else {
		players[player2_pos].showHand();
	}
}

void Game::back_move(int player) {
    vector<shared_ptr<Cards>> &deck_minions = players[player].getCollection_of_cards(3);
    for (unsigned i = 0; i < deck_minions.size(); ++i) {
        bool isMove = deck_minions[i]->getMoved();
        if (isMove) deck_minions[i]->setMoved(false);
    }
    
    vector<shared_ptr<Cards>> &hand_cards = players[player].getCollection_of_cards(1);
    for (unsigned i = 0; i < deck_minions.size(); ++i) {
        bool isMove = hand_cards[i]->getMoved();
        if (isMove) hand_cards[i]->setMoved(false);
    }
}
