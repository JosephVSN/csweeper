#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../Tile.h"

class Board {
    public:
        int width;
        int height;
        int mines;
        bool cleared;
        void generate();
        void clear_board();
        Board();
        Board(int width, int height, int mines);
    private:
        Tile ** map;
}

#endif