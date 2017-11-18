#include "board.h"

using namespace std;

Board::Board() {}
Board::~Board() {}

shared_ptr<Cards> Board::getRitual() {
	return ritual;
}

void Board::setRitual_on_cards(shared_ptr<Cards> new_ritual) {
	ritual = new_ritual;
}

bool Board::hasRitual() {
    int count = ritual.use_count();
    if (count == 0) {
        return false;
    }
    return true;
}


void Board::shuffle() {return;}
