#ifndef _DECK_H_
#define _DECK_H_
#include "collection.h"

class Deck: public Collection {

  public: 
    Deck(std::string deck);
    ~Deck() override;

    void shuffle() override;
};

#endif
