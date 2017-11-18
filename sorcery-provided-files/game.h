#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include <string>
#include "player.h"

class Game {
  std::vector<Player> players;
  int player1_pos = 0;
  int player2_pos = 1;
  bool test = false;
  
  public:
    Game();
    void initial(std::string deck1, std::string deck2, bool test, 
			std::string name1, std::string name2);
    
    void getMagic(int player);
    
    void begin_ritual(int player);
    void end_ritual(int player);
    
    void draw(int player);
    void discard(int player, int pos);
    void attack(int player, int pos);
    void attack(int player, int pos, int target);

    void play(int player, int pos, bool test);
    void play(int player, int pos, int target_player, int target, bool test);
    void play(int player, int pos, int target_player, bool test);

    void use(int player, int pos, bool test);
    void use(int player, int pos, int target_player, int target, bool test);


    void displayBoard();
    void displayHand(int whichPlayer);
    void inspect(int whichPlayer, int pos);

    
    void back_move(int player);
    
};

#endif
