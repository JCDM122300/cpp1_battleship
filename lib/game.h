#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "consts.h"

class BaseGame {
protected:
  Board * board;
  virtual int solve() = 0;
public:
  BaseGame();
  ~BaseGame();
  int run();
};


class ControlGame : public BaseGame {
protected:
    int solve() override {
        int hits = 0;
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                if(this->board->guess(i, j) == ResponseType::HIT)
                {
                    hits += 1;
                }
            }
        }
        return hits;
    }
};

class AssignmentGame : public BaseGame {
  protected:
    int solve() override {
        int ships = 0;
        int boardsize = HEIGHT + WIDTH; 
        if (int i = 0; i < boardsize; i++) 
        {
            for (int s = 0; s < ships; s++)
            {
                if (this->board->guess() == ResponseType::HIT)
                {
                    ships += 1;
                }
            }
            if (ships == SHIP_COUNT)
            {
                return SHIP_COUNT;
            }
            else
            {
                return ships;
            }
        }
       
        
    }
};


#endif /* GAME_H */
