#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "minion.h"

class Enchantments: public Minion {
  protcted:
    Cards *component;
  public:
    Enchantments();
    virtual ~Enchantments();
    void setComp(Cards *enchant);
    Cards *getComp();
};


#endif
