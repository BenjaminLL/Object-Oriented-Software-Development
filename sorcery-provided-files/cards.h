#ifndef _CARDS_H_
#define _CARDS_H_
#include <memory>
#include <string>

class Cards {
protected:
    int cost;

public:
    Cards(int cost);
    virtual ~Cards() = 0;
    int getcost();
    virtual std::string getDesc() = 0;
    virtual int getAttack() {return 1;}
    virtual int getDefence() {return 1;}
    virtual void getAttacked(int i) {return;}
    
    virtual std::string getAttack_entan() {return "";}
    virtual std::string getDefence_entan() {return "";}
    
    virtual std::string getType() {return "";}
    virtual std::string getName() {return "";}
    virtual int getAbilityCost() {return 1;}

    virtual void setRitual(std::shared_ptr<Cards> new_ritual) {return;}
    virtual int getRitualCost() {return 1;}
    virtual int getRitualCharges() {return 1;}
    virtual void addRitualCharges(int i) {return;}
    
    virtual void addExtraAtk(int i) {return;}
    virtual void addExtraDef(int i) {return;}
    virtual void addExtraCost(int i) {return;}
    
    virtual bool isSilence() {return false;}
    virtual void setSilence(bool b) {return;}

    virtual std::shared_ptr<Cards> getEnchant() {
        std::shared_ptr<Cards> a;
        return a;
    }
    virtual void setEnchant(std::shared_ptr<Cards> en) {return;}
    virtual std::shared_ptr<Cards> getComp() {
        std::shared_ptr<Cards> a;
        return a;
    }
    virtual void setComp(std::shared_ptr<Cards> enchant) {return;}
    virtual std::shared_ptr<Cards> getPrev() {
        std::shared_ptr<Cards> a;
        return a;
    }
    virtual void setPrev(std::shared_ptr<Cards> enchant) {return;}
    
    virtual void clear() {return;}
    virtual void clear_extra_cost() {return;}
    
    virtual void inspect() {return;}
    
    virtual std::string no_enchant(std::shared_ptr<Cards> c) {return "";}
    virtual bool getMoved() {return false;}
    virtual void setMoved(bool b) {return;}
    
    virtual void setDamage(bool b) {return;}
    virtual bool getDamage() {return false;}
};

#endif
