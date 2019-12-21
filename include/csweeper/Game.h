#ifndef GAME_H
#define GAME_H

#include <csweeper/Board.h>

class Game {
    public:
        bool finished;
        bool won;
        Game();
        bool play();
        void choose(int, int);
    private:
        Board game_board;
};

#endif