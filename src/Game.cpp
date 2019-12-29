#include <csweeper/Game.h>

Game::Game() {
    Game::won = false;
    Game::finished = false;
    Game::game_board = Board(10, 10, 5);
}

bool Game::play() {
    Game::game_board.generate();
    Game::game_board.print(false);
    return Game::won;
}

void Game::choose(int usr_x, int usr_y) {
    /** Error handling for user selection **/
    if (usr_x < 0 || usr_x > Game::game_board.width) {
        std::cout << "Invalid X coordinate" << std::endl;
        return;
    }
    if (usr_y < 0 || usr_y > Game::game_board.height) {
        std::cout << "Invalid Y coordinate" << std::endl;
        return;
    }

    /** Try to flip the tile the user picked **/
    bool tile_clicked = Game::game_board.is_clicked(usr_x, usr_y);
    if (!tile_clicked) {
        Game::game_board.click(usr_x, usr_y);
        /** User selected a bomb **/
        if (Game::game_board.get_type(usr_x, usr_y) == BOMB) {
            Game::won = false;
            Game::finished = true;
        }
    } else {
        std::cout << "Tile has already been revealed" << std::endl;
    }
}