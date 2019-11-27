#include <csweeper/Board.h>

Board::Board() {
    Board::width = 0;
    Board::height = 0;
    Board::mines = 0;
    Board::cleared = true;
    Board::ready = false;
    Board::map = nullptr;
}

Board::Board(int width, int height, int mines) {
    Board::width = width;
    Board::height = height;
    Board::mines = mines;
    Board::cleared = false;
    Board::ready = false;
    Board::map = new Tile * [Board::width];
    for(int i = 0; i < Board::width; i++) {
        map[i] = new Tile[Board::height];
    }
}

void Board::generate() {
    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            Board::map[i][j].pos_x = i;
            Board::map[i][j].pos_y = j;
            Board::map[i][j].tile_type = 0;
        }
    }
}

void Board::print() {
    /** Prints out the board **/
    if (map == nullptr) { return; }

    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            Board::map[i][j].print_tile();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Board::clear_board() {
    delete[] Board::map; 
}