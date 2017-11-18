#ifndef _ENCHANTMENTS_H_
#define _ENCHANTMENTS_H_
#include "minion.h"

class Enchantments: public Minion {
  protected:
    std::shared_ptr<Cards> component;
    std::shared_ptr<Cards> prev;
  public:
    Enchantments(int cost);
    ~Enchantments() override;
    void setComp(std::shared_ptr<Cards> enchant) override;
    std::shared_ptr<Cards> getComp() override;
    std::shared_ptr<Cards> getPrev() override;
    void setPrev(std::shared_ptr<Cards> enchant) override;
};


#endif
