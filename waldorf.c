/*
 * waldorf.c
 *
 *  Created on: Nov 9, 2017
 *      Author: nxf27877
 */


#include <stdio.h>
#include <string.h>

char grid[50][50];
char words[20][100];

void readGrid(int n, int m) {
	int i = 0,j;
	int aux = 0;


	for(i = 0; i < n;  i++) {
		for(j = 0; j < m; j++) {
			aux = getchar();
			if (aux >= 'a' && aux <= 'z')
				grid[i][j] = aux;
			else
				grid[i][j] = aux + 32;
		}
		getchar();
	}
}

void readWords(int o) {
	int i = 0,j;
	int aux = 0;


	for(i = 0; i < o;  i++) {
		for(j = 0; ; j++) {
			aux = getchar();
			if(aux == '\n') break;

			if (aux >= 'a' && aux <= 'z')
				words[i][j] = aux;
			else
				words[i][j] = aux + 32;

		}
		//getchar();
		putchar('\n');
	}

	getchar();
}

void cleanGrid() {
	int i,j;

	for(i = 0; i < 50; i++) {
		for(j = 0; j < 50; j++)
			grid[i][j] = 0;
	}

}

void cleanWords() {
	int i,j;

	for(i = 0; i < 20; i++) {
		for(j = 0; j < 100; j++)
			words[i][j] = 0;
	}

}


void search(int o, int n, int m) {
	int i, j, k;
	for(i = 0; i < o; i++) {
		for(j = 0; j < n; j++) {
			for(k = 0; k < m; k++) {
				if(words[o][0] == grid[i][j]) {
					//checar en todas las direcciones
					// porla siguiente letra y si se encuentra
					//llamar un metodo con indices y direccion
					//direcciones[-1,-1    -1,0   -1,1      1,-1       1,0   1,1  ] e indice de la palabra actual
				}
			}
		}

	}

}

int main () {
	int cases = 0, n = 0, m = 0, o = 0;
	int x,y;

	scanf("%d\n\n",&cases);

	while(cases --) {
		x = y = 0;
		cleanGrid();


		scanf("%d %d\n", &n, &m );
		readGrid(n,m);

		scanf("%d\n", &o);
		readWords(o);





	}
	return 0;
}
