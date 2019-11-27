#include <csweeper/Game.h>

Game::Game() {
    Game::won = false;
    Game::finished = false;
    Game::game_board = Board(24, 24, 99);
}

bool Game::play() {
    Game::game_board.generate();
    Game::game_board.print();
    return Game::won;
}