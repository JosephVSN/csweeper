#include <csweeper/Board.h>
#include <csweeper/Game.h>
#include <csweeper/Tile.h>

Board::Board() {
    Board::width = 0;
    Board::height = 0;
    Board::mines = 0;
    Board::cleared = true;
    Board::map = nullptr;
}

Board::Board(int width, int height, int mines) {
    Board::width = width;
    Board::height = height;
    Board::mines = mines;
    Board::cleared = false;
    Board::map = new Tile * [Tile::width];
    for(int i = 0; i < Tile::height; i++) {
        map[i] = new Tile[Tile::height];
    }
}

void Board::generate() {
    /** Generate mine squares **/
    int placed = 0;
    int pos_x;
    int pos_y;
    srand(time(NULL)); // Default to seeding with time
    while (placed != Board::mines) {
        pos_x = rand() % Board::width;
        pos_y = rand() % Board::height;
        /** Try and place our mine **/
        if (Board::map[pos_x][pos_y]->tile_type != -1) {
            Board::map[pos_x][pos_y]->tile_type = -1;
            placed++;
        }
    }

    /** Generate non-mine squares **/
    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            
        }
    }
}

void Board::clear_board() {
    delete[] Board::map; 
}