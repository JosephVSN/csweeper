#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <csweeper/Tile.h>

class Board {
    public:
        int width;
        int height;
        int mines;
        bool ready;
        bool cleared;
        void generate();
        void clear_board();
        void print();
        Board();
        Board(int width, int height, int mines);
    private:
        int count_neighbours(int, int);
        Tile ** map;
};

#endif