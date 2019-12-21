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

int Board::count_neighbours(int root_x, int root_y) {
    /** Error handling for the arguments **/
    if (root_x < 0 || root_x >= Board::width) {
        return -1;
    }
    if (root_y < 0 || root_y >= Board::height) {
        return -1;
    }

    /** Check top row, mid row, then bottom row **/
    int neighbours = 0;
    for (int shift_x = -1; shift_x < 2; shift_x++) {
        int new_x = root_x + shift_x;
        if (new_x > -1 && new_x < Board::width) {
            for (int shift_y = -1; shift_y < 2; shift_y++) {
                int new_y = root_y + shift_y;
                if (new_y > -1 && new_y < Board::height) {
                    if (Board::map[new_x][new_y].tile_type == BOMB) {
                        neighbours++;
                    }
                }
            }
        }
    }
    return neighbours;
}

void Board::generate() {
    int placed = 0;
    int cur_x;
    int cur_y;
    srand(time(NULL));
    /** Zero out the board **/
    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            Board::map[i][j].pos_x = i;
            Board::map[i][j].pos_y = j;
            Board::map[i][j].tile_type = 0;
        }
    }
    /** Fill in bombs **/
    while (placed != Board::mines) {
        cur_x = rand() % Board::width;
        cur_y = rand() % Board::height;
        /** Check if our tile isn't already flipped to a bomb **/
        if (Board::map[cur_x][cur_y].tile_type != BOMB) {
            Board::map[cur_x][cur_y].tile_type = BOMB;
            placed++;
        }
    }
    /** Set neighbor counts **/
    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            if (Board::map[i][j].tile_type != BOMB) {
                Board::map[i][j].tile_type = Board::count_neighbours(i, j);
            }
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