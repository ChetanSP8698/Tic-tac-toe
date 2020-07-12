#include <stdio.h>
#include "ttt.h"

void init(matrix *t) {
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			t->a[i][j] = -1;
	}
}

int insert(matrix *t, int val, int pos) {
	int i, j;
	j = pos % 10;
	i = pos / 10;
	if (i < 3 && j < 3) {
		if(t->a[i][j] == -1)
			t->a[i][j] = val;
		else
			return -2;
	}
	else
		return -1;
	return 0;
}

int check(matrix *t) {
	int i;
	for(i = 0; i < 3; i++) {
		if(t->a[i][0] == 1 && t->a[i][1] == 1 && t->a[i][2] == 1)
			return 1;
	}		
	
	for(i = 0; i < 3; i++) {
		if(t->a[0][i] == 1 && t->a[1][i] == 1 && t->a[2][i] == 1)
			return 1;
	}
	
 	if(t->a[0][0] == 1 && t->a[1][1] == 1 && t->a[2][2] == 1)
		return 1;
		
	if(t->a[0][2] == 1 && t->a[1][1] == 1 && t->a[2][0] == 1)
		return 1;
	
	for(i = 0; i < 3; i++) {
		if(t->a[i][0] == 0 && t->a[i][1] == 0 && t->a[i][2] == 0)
			return 0;
	}		
	
	for(i = 0; i < 3; i++) {
		if(t->a[0][i] == 0 && t->a[1][i] == 0 && t->a[2][i] == 0)
			return 0;
	}
	
 	if(t->a[0][0] == 0 && t->a[1][1] == 0 && t->a[2][2] == 0)
		return 0;
		
	if(t->a[0][2] == 0 && t->a[1][1] == 0 && t->a[2][0] == 0)
		return 0;
		
	return -1;
}

void printttt(matrix *t) {
	int i, j;
	printf("\n   0   1   2\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(j == 2) {
				if(t->a[i][j] == 1) {
					printf(" X ");
				}
				else if(t->a[i][j] == 0) {
					printf(" O ");
				}
				else {
					printf("   ");
				}
			}
			else if(j == 1) {
				if(t->a[i][j] == 1) {
					printf(" X |");
				}
				else if(t->a[i][j] == 0) {
					printf(" O |");
				}
				else {
					printf("   |");
				}
			}
			else {
				if(t->a[i][j] == 1) {
					printf("%d  X |", i);
				}
				else if(t->a[i][j] == 0) {
					printf("%d  O |", i);
				}
				else {
					printf("%d    |", i);
				}
			}
		}
		if(i == 2 && j == 3) {
			printf("\n");
		}
		else
			printf("\n  -----------\n");
	}
	printf("\n");	
}

