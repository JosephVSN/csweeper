#ifndef TILE_H
#define TILE_H
#include <iostream>

class Tile {
    public:
        int tile_type;
        bool clicked;
        int pos_x;
        int pos_y;
        void print_tile();
        Tile();
        Tile(int x, int y);
};

#endif