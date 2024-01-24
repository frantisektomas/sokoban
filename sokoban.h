#include <curses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"

// Enumeracny zaznam popisujuci smer pohybu hraca
typedef enum {
     UP,
     DOWN,
     LEFT,
     RIGHT
     } DIRECTION;

// Enumeracny zaznam popisujuci jednotlive prvky mapy skladoveho priestoru
typedef enum {
     EMPTY = 1,    // hodnota 1
     WALL,         // hodnota 2
     BOX,          // hodnota 3
     SOKOBAN,      // hodnota 4
     PLACE,        // hodnota 5
     BOX_ON_PLACE, // hodnota 6
     SOK_ON_PLACE  // hodnota 7
     } MAP_ITEM;

// Informacna cast popisujuca jednu uroven hry
typedef struct tinfo {
     char name[30];         // pomenovanie urovne
     char description[50];  // popis urovne
     char password[30];     // heslo pre uroven
     int nrows;             // realna vyska skladoveho priestoru
     int ncols;             // realna sirka skladoveho priestoru
     } TINFO;

// Udajovy typ popisujuci jednu uroven
typedef struct level {
     TINFO info;            // popis jednej urovne
     int srow;              // pozicia hraca (sokobana) - riadok
     int scol;              // y-ova pozicia hraca (sokobana) - stlpec
     int level_steps;       // pocet krokov v ramci jednej urovne
     MAP_ITEM map[25][80];  // mapa skladoveho priestoru
     struct level* next;    // smenik na dalsiu uroven
     struct level* prev;    // smernik na predchadzajucu uroven
     } LEVEL;

// Udajovy typ popisujuci celu hru
typedef struct game {
     LEVEL* first;          // smernik na prvu uroven
     int game_steps;        // pocet krokov dohranych urovni hry
     } GAME;

GAME* game_create(char filename[]);
void game_play(GAME* game);
GAME* game_destroy(GAME* game);

LEVEL* level_create(FILE* fd);
bool level_reset(LEVEL* level);
LEVEL* level_search_by_name(GAME* game, char name[]);
bool level_push_to_game(GAME* game, LEVEL* level);
LEVEL* level_destroy(LEVEL* level);
bool level_is_solved(LEVEL* level);
void level_preview(LEVEL* level, int row, int col);
void level_display(LEVEL* level);
void level_update(LEVEL* level, DIRECTION direction);
int level_play(LEVEL* level);

INPUT_KEY get_input();
