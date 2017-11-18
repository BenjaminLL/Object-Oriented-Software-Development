#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include <vector>
#include <string>
#include <memory>
#include "cards.h"


class Collection {
  protected:
    std::vector<std::shared_ptr<Cards>> col;
    int num;

  public:
    void setNum(int num);
    int getNum();
    void attach(std::shared_ptr<Cards> c);
    void detach(std::shared_ptr<Cards> c);
    
    std::vector<std::shared_ptr<Cards>> &getcards();
    std::shared_ptr<Cards> getcard(int i);
    
    virtual std::shared_ptr<Cards> getRitual() {
        std::shared_ptr<Cards> a;
        return a;
    }
    virtual void setRitual_on_cards(std::shared_ptr<Cards> new_ritual) {return;}
    virtual bool hasRitual() {return false;}
    
    virtual void shuffle() {};
    
    Collection();
    virtual ~Collection() = 0;

    
};

#endif
