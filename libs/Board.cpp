#include "../include/Board.h"

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

}

void Board::clear_board() {
    delete[] Board::map; 
}