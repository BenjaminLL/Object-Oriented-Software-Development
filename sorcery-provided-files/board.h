#ifndef _BOARD_H_
#define _BOARD_H_
#include "collection.h"

class Board: public Collection {
  std::shared_ptr<Cards> ritual;
  public:
    Board();
    ~Board() override;

    std::shared_ptr<Cards> getRitual() override;
    void setRitual_on_cards(std::shared_ptr<Cards> new_ritual) override;
    bool hasRitual() override;
    void shuffle() override;
};

#endif


