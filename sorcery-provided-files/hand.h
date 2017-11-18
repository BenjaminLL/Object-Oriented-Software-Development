#ifndef _HAND_H_
#define _HAND_H_
#include "collection.h"

class Hand: public Collection {
  public:
    Hand();
    ~Hand() override;
    std::shared_ptr<Cards> getRitual() override;
    bool hasRitual() override;
    void shuffle() override;
};

#endif
