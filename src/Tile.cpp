#include <csweeper/Tile.h>

Tile::Tile() {
    Tile::clicked = false;
    Tile::pos_x = -1;
    Tile::pos_y = -1;
    Tile::tile_type = -1;
}

Tile::Tile(int x, int y, int tile_type) {
    Tile::pos_x = x;
    Tile::pos_y = y;
    Tile::clicked = false;
    Tile::tile_type = tile_type;
}

void Tile::print_tile(bool debug) {
    /** If the tile has already been clicked, or if we are debugging, print the tile's value anyway **/
    if (debug || Tile::clicked == true) {
        std::cout << "[" << Tile::tile_type << "]";
    } else {
        /** If the tile has not been flipped and we are not debugging, print a blank **/
        std::cout << "[ ]";
    }
}