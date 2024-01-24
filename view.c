#include "sokoban.h"

// Funkcia zobrazi aktualny stav urovne pocas hrania
// Funkcia je naprogramovana
// Param: level - smernik na aktualnu uroven
// Return: bez navratovej hodnoty
void level_display(LEVEL* level)
{
clear();
refresh();
mvprintw(0,0,"Level> %s",level->info.name);
mvprintw(1,0,"Sokoban position: %02d col %02d row",level->scol,level->srow);
mvprintw(2,0,"Steps count: %d",level->level_steps);
level_preview(level,5,3);
}

// Funkcia zobrazi aktualny stav urovne pri vybere urovne pre hru
// Funkcia je naprogramovana
// Param> level / smernik na uroven pre zobrazenie
// Param> start_row, start_col / lavy horny rok zobrazenie urovne
// Return> bez navratovej hodnoty
void level_preview(LEVEL* level, int start_row, int start_col)
{
int col,row;
int r = start_row;
int c = start_col;

for(col=0; col<level->info.ncols; col++)
   for(row=0; row<level->info.nrows; row++)
      switch(level->map[row][col]){
         case EMPTY:
            attron(COLOR_PAIR(EMPTY) | A_BOLD);
            mvaddch(row+r,col+c,' ');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case BOX:
            attron(COLOR_PAIR(BOX) | A_BOLD);
            mvaddch(row+r,col+c,'X');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case WALL:
            attron(COLOR_PAIR(WALL) | A_BOLD);
            mvaddch(row+r,col+c,'#');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case PLACE:
            attron(COLOR_PAIR(PLACE) | A_BOLD);
            mvaddch(row+r,col+c,'*');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case BOX_ON_PLACE:
            attron(COLOR_PAIR(BOX_ON_PLACE) | A_BOLD);
            mvaddch(row+r,col+c,'X');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case SOK_ON_PLACE:
            attron(COLOR_PAIR(SOK_ON_PLACE) | A_BOLD);
            mvaddch(row+r,col+c,'O');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         case SOKOBAN:
            attron(COLOR_PAIR(SOKOBAN) | A_BOLD);
            mvaddch(row+r,col+c,'O');
            attroff(A_BOLD);
            attron(COLOR_PAIR(EMPTY));
            break;
         }
refresh();
}

