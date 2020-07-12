#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ttt.h"

int main() {
	matrix t;
	int i = 0, fst, sec, x, j, y;
	char f[2], s[2];
	init(&t);
	printf("	***TIC TAC TOE***\n\nStart Game\n\n");
	printf("1. 1st Player - X\n2. 2st Player - O\n");
	printttt(&t);
	while(i < 5) {
		printf("1st Player Turn\n");
		scanf("%s", f);
		fst = atoi(f);
		if(strlen(f) != 2) {
			printf("\nInvalid Input\n");
			continue;
		}
		j = insert(&t, 1, fst);
		if(j == -1) {
			printf("\nInvalid Input\n");
			continue;
		}
		if(j == -2) {
			printf("\nThis position is filled, try another...\n");
			continue;
		}
		printttt(&t);
		y = check(&t);
		if(y == 1) {
			printf("1st Player Wins\n");
			return 0;
		}
		
		i++;
		
		if(i == 5) {
			printf("Game Draw\n");
			return 0;	
		}
		
		loop:
			printf("2st Player Turn\n");
			scanf("%s", s);
			sec = atoi(s);
			if(strlen(s) != 2) {
				printf("\nInvalid Input\n");
				goto loop;
			}
			j = insert(&t, 0, sec);
			if(j == -1) {
				printf("\nInvalid Input\n");
				goto loop;
			}
			if(j == -2) {
				printf("\nThis position is filled, try another...\n");
				goto loop;
			}
			printttt(&t);
			y = check(&t);
			if(y == 0) {
				printf("2st Player Wins\n");
				return 0;
			}
		
	}
	
	return 0;
}
