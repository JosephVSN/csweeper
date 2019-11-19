#include "../include/Tile.h"

Tile::Tile() {
    Tile::clicked = false;
    Tile::pos_x = -1;
    Tile::pos_y = -1;
    Tile::tile_type = -1;
}

Tile::Tile(int x, int y) {

}

void Tile::print_tile() {
    std::cout << "(" << Tile::pos_x << ", " << Tile::pos_y << ") [" << Tile::tile_type << "]" << std::endl;
}