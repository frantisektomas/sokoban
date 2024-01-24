#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>

GAME* game_create(char filename[]) {

	if(filename == NULL) return NULL;

	FILE* f = fopen(filename,"r");
	if (f == NULL) return NULL;

	GAME* g;
	g = (GAME*)malloc(sizeof(GAME));
	if (g == NULL) {
		fclose(f);
		return NULL;
	}

	g->game_steps = 0;
	g->first=NULL;

    int c;
	char name[30];
    char pass[30];
    char desc[50];


    while ((c = fgetc(f)) != EOF) {
        LEVEL* level = level_create(f);
        if (level != NULL) {
            if (!level_push_to_game(g, level)) {
                fclose(f);
                free(g);
                return NULL;
            }
        }
    }

	fclose(f);
	return g;

}

GAME* game_destroy(GAME* game) {

	free(game);

}
