#include "sokoban.h"

// Funkcia, ktora vytvara prostredie pre vyber urovne pre hranie
// Funkcia je naprogramovana.
// Param> bez parametrov
// Return> bez navratovej hodnoty

void run()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    clear();
    refresh();

    start_color();
    init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);
    init_pair(WALL, COLOR_GREEN, COLOR_BLACK);
    init_pair(BOX, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PLACE, COLOR_CYAN, COLOR_BLACK);
    init_pair(BOX_ON_PLACE, COLOR_YELLOW, COLOR_RED);
    init_pair(SOKOBAN, COLOR_RED, COLOR_BLACK);
    init_pair(SOK_ON_PLACE, COLOR_CYAN, COLOR_BLACK);

    GAME* game;

    game = game_create("levels.dat");
    game_play(game);
    game_destroy(game);

    clear();
    refresh();
    echo();
    curs_set(1);
    keypad(stdscr,FALSE);
    endwin();
}
