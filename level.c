#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool level_reset(LEVEL* level) {

	if (level == NULL) {
    	return false;
    }

}

LEVEL* level_search_by_name(GAME* game, char name[]) {

    if (game == NULL || name[0] == '\0') {
        return NULL;
    }

    LEVEL* current_level = game->first;
    while (current_level != NULL) {
        if (strcmp(current_level->info.name, name) == 0) {
            return current_level;
        }
        current_level = current_level->next;
    }

    return NULL;
}

LEVEL* level_create(FILE* fd) {

    int i,c;
    char name[30];
    char pass[30];
    char desc[50];

    LEVEL* l;
    l = (LEVEL*)malloc(sizeof(LEVEL));
    i=0;

    while((c=fgetc(fd))!=';') {
        name[i]=c;
        i++;
    }

    name[i]='\0';
    i=0;

    while((c=fgetc(fd))!=';') {
        pass[i]=c;
        i++;
    }

    pass[i]='\0';
    i=0;

    while((c=fgetc(fd))!=';') {
        desc[i]=c;
        i++;
    }

    desc[i]='\0';

    int row=0,col=0;

    while((c=fgetc(fd))!='\n' && c != EOF) {
        switch(c) {
            case'#':l->map[row][col]=WALL;col++;break;
            case'-':l->map[row][col]=EMPTY;col++;break;
            case'$':l->map[row][col]=BOX;col++;break;
            case'.':l->map[row][col]=PLACE;col++;break;
            case'@':l->map[row][col]=SOKOBAN;l->srow=row;l->scol=col;col++;break;
            case'|':row++,col=0;break;
        }
    }

    l->level_steps=0;
    l->info.ncols=col;
    l->info.nrows=row+1;

    strcpy(l->info.password,pass);
    strcpy(l->info.name,name);
    strcpy(l->info.description,desc);

    return l;

}

bool level_push_to_game(GAME* game, LEVEL* level) {

    if (level == NULL || game == NULL) {
        return false;
    }

    if (game->first == NULL) {
        game->first = level;
        game->game_steps = 0;
        return true;
    }

    LEVEL* current = game->first;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = level;
    level->prev = current;
    level->next = NULL;

    return true;

}

LEVEL* level_destroy(LEVEL* level) {

	free(level);
	level = NULL;
	return level;

}

bool level_is_solved(LEVEL* level) {

	// idk uz to je zrobene

}

void level_update(LEVEL* level, DIRECTION direction) {

	int newRow = level->srow;
    int newCol = level->scol;

    switch(direction) {
       case UP:
			if (level->map[newRow - 1][newCol] == EMPTY || level->map[newRow - 1][newCol] == PLACE) {
				level->map[newRow][newCol] = (level->map[newRow][newCol]== SOK_ON_PLACE) ? PLACE : EMPTY;
				newRow--;
				level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
			}
			if ((level->map[newRow - 1][newCol] == BOX || level->map[newRow - 1][newCol] == BOX_ON_PLACE) && (level->map[newRow - 2][newCol] == EMPTY || level->map[newRow - 2][newCol] == PLACE)) {
				level->map[newRow][newCol] = (level->map[newRow] [newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
				level->map[newRow -1][newCol] = (level->map[newRow - 1][newCol] == BOX_ON_PLACE ) ? PLACE : EMPTY;
				newRow--;
				level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
				level->map[newRow - 1][newCol] =(level->map[newRow - 1][newCol] == PLACE) ? BOX_ON_PLACE : BOX;
			}
			break;
        case DOWN:
           	if (level->map[newRow + 1][newCol] == EMPTY || level->map[newRow + 1][newCol] == PLACE){
				level->map[newRow][newCol] = (level->map[newRow][newCol]== SOK_ON_PLACE) ? PLACE : EMPTY;
				newRow++;
				level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
			}
			if ((level->map[newRow + 1][newCol] == BOX || level->map[newRow + 1][newCol] == BOX_ON_PLACE) && (level->map[newRow + 2][newCol] == EMPTY || level->map[newRow + 2][newCol] == PLACE)) {
				level->map[newRow][newCol] = (level->map[newRow] [newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
				level->map[newRow + 1][newCol] = (level->map[newRow + 1][newCol] == BOX_ON_PLACE ) ? PLACE : EMPTY;
				newRow++;
				level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
				level->map[newRow + 1][newCol] =(level->map[newRow + 1][newCol] == PLACE) ? BOX_ON_PLACE : BOX;
			}
			break;
        case LEFT:
            if (level->map[newRow][newCol - 1] == EMPTY || level->map[newRow][newCol - 1] == PLACE) {
                level->map[newRow][newCol] = (level->map[newRow][newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
                newCol--;
                level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
            } else if (level->map[newRow][newCol - 1] == BOX || level->map[newRow][newCol - 1] == BOX_ON_PLACE) {
                if (level->map[newRow][newCol - 2] == EMPTY || level->map[newRow][newCol - 2] == PLACE) {
                    level->map[newRow][newCol] = (level->map[newRow][newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
                    level->map[newRow][newCol - 1] = (level->map[newRow][newCol - 1] == BOX_ON_PLACE) ? PLACE : EMPTY;
                    newCol--;
                    level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
                    level->map[newRow][newCol - 1] = (level->map[newRow][newCol - 1] == PLACE) ? BOX_ON_PLACE : BOX;
                }
            }
            break;
    	case RIGHT:
    		if(level->map[newRow][newCol + 1] == EMPTY || level->map[newRow][newCol + 1] == PLACE) {
        		level->map[newRow][newCol] = (level->map[newRow][newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
        		newCol++;
        		level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
    		} else if (level->map[newRow][newCol + 1] == BOX || level->map[newRow][newCol + 1] == BOX_ON_PLACE) {
        	if (level->map[newRow][newCol + 2] == EMPTY || level->map[newRow][newCol + 2] == PLACE) {
            	level->map[newRow][newCol] = (level->map[newRow][newCol] == SOK_ON_PLACE) ? PLACE : EMPTY;
            	level->map[newRow][newCol + 1] = (level->map[newRow][newCol + 1] == BOX_ON_PLACE) ? PLACE : EMPTY;
            	newCol++;
            	level->map[newRow][newCol] = (level->map[newRow][newCol] == PLACE) ? SOK_ON_PLACE : SOKOBAN;
            	level->map[newRow][newCol + 1] = (level->map[newRow][newCol + 1] == PLACE) ? BOX_ON_PLACE : BOX;
        	}
    	}

        break;
        default:
        break;

    }

    level->level_steps++;
    level->srow = newRow;
    level->scol = newCol;

}
