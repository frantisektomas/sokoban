#include "sokoban.h"

// Funkcia tvori hernu slucku celej hry.
// Funkcia je naprogramovana
// Param> game - smernik na vytvorenu hru
// Return> bez navratovej hodnoty
void game_play(GAME* game)
{
   bool end = false;
   LEVEL* level;

   if(game == NULL)
      return;
   if(game->first == NULL)
      return;

   level = game->first;
   do {
	clear();
	mvprintw(1,2,"M E N U");
        mvprintw(3,2,"G       - Play level");
        mvprintw(4,2,"R_arrow - Next level");
        mvprintw(5,2,"L_arrow - Previous level");
        mvprintw(6,2,"R       - Reset level");
        mvprintw(7,2,"ESC     - Exit game");
        mvprintw(9,2,"Your option> ...");
        mvprintw(12,2,"Information about level");
        mvprintw(13,2,"Name: %s",level->info.name);
        mvprintw(14,2,"Description: %s",level->info.description);
        mvprintw(15,2,"Password: %s",level->info.password);
        mvprintw(16,2,"Size: %02d rows %02d cols",level->info.nrows, level->info.ncols);
        mvprintw(17,2,"Sokoban position: %02d row %02d col",level->srow+1,level->scol+1);
        mvprintw(19,2,"Total steps: %04d",game->game_steps);
        level_preview(level,1,50);
        switch(get_input()){
           case IN_KEY_R:
           case IN_KEY_r:
                 level_reset(level);
                 break;
           case IN_KEY_G:
           case IN_KEY_g:
                 game->game_steps += level_play(level);
                 break;
           case IN_KEY_RIGHT:
                 if(level->next != NULL)
                    level = level->next;
                 break;
           case IN_KEY_LEFT:
                 if(level->prev != NULL)
                    level = level->prev;
                 break;
           case IN_KEY_ESCAPE:
                 end = true;
                 break;
           }
   }
   while(!end);
}

// Funkcia nacita stlaceny klaves z klavesnice
// Funkcia je naprogramovana
// Param> bez parametrov
// Return> kod nacitaneho klavesu podla enumeracneho zaznamu INPUT_KEY
INPUT_KEY get_input()
{
   switch(getch()){
      case KEY_DOWN:   return IN_KEY_DOWN;
      case KEY_UP:     return IN_KEY_UP;
      case KEY_LEFT:   return IN_KEY_LEFT;
      case KEY_RIGHT:  return IN_KEY_RIGHT;
      case KEY_ESCAPE: return IN_KEY_ESCAPE;
      case 'G':        return IN_KEY_G;
      case 'g':        return IN_KEY_g;
      case 'R':        return IN_KEY_R;
      case 'r':        return IN_KEY_r;
      }

   return IN_KEY_NONE;
}

// Funkcia zabezpeci hernu slucku pre hranie jednej urovne hry
// Funkcia je naprogramovana
// Param> level - smernik na aktualnu uroven
// Return> pocet dosiahnutych krokov pri uspesnom dohrani urovne
//         0 - pri preruseni hrania urovne pouzivatelom
//         0 - ak hra uz bola uspesne dohrana
int level_play(LEVEL* level)
{
if(level_is_solved(level)){
   clear();
   mvprintw(10,10,"This level is solved. Press ENTER ...");
   getch();
   return(0);
   }

level_display(level);
while(!level_is_solved(level)){
   switch(get_input()){
      case IN_KEY_LEFT: level_update(level,LEFT);break;
      case IN_KEY_RIGHT: level_update(level,RIGHT);break;
      case IN_KEY_UP: level_update(level,UP);break;
      case IN_KEY_DOWN: level_update(level,DOWN);break;
      case IN_KEY_ESCAPE: return(0);
      }
   level->level_steps++;
   level_display(level);
   }
mvprintw(20,5,"Congratulation for finish level - %03d steps. Pres ENTER ...",level->level_steps);
getch();
return(level->level_steps);
}
