#include <stdio.h>

int reg[10] = {0};
char ram[1000][3] = {{0},{0}};

int counter = 0;

void command2(int d, int n){
	reg[d] = n;
	counter++;
}

void command3(int d, int n){
	reg[d] += n;
	reg[d] %= 1000;
	counter++;
}

void command4(int d, int n){
	reg[d] *= n;
	reg[d] %= 1000;
	counter++;
}

void command5(int d, int s){
	reg[d] = reg[s];
	counter++;
}

void command6(int d, int s){
	reg[d]  += reg[s];
	reg[d] %= 1000;
	counter++;
}

void command7(int d, int s){
	reg[d] *= reg[s];
	reg[d] %= 1000;
	counter++;
}

void command8(int d, int a){
	reg[d] = ((ram[reg[a]][2] - '0') *   1) +
			 ((ram[reg[a]][1] - '0') *  10) +
			 ((ram[reg[a]][0] - '0') * 100);
	counter++;
}

void command9(int s, int a){
	ram[reg[a]][0] = (reg[s] / 100) + '0';
	ram[reg[a]][1] = ((reg[s] / 10) % 10) + '0';
	ram[reg[a]][2] = (reg[s] % 10) + '0';
	counter++;
}

int command0(int d, int s,int pc){
	if(reg[s] != 0)
		pc = reg[d] - 1;
	counter++;
	return pc;
}

void printMatrix() {
	int i = 0, j = 0;
	for(i = 0; i < 1000 ; i++){
		for(j = 0; j <= 2; j++)
			putchar(ram[i][j]);
		putchar('\n');
	}
}

void cleanRemain (int pc) {
	int k = 0, l = 0;
	for(k = pc; k < 1000; k++) {
		for(l = 0; l <= 2; l++ )
			ram[k][l] = '0';
	}
}

void printReg () {
	int i = 0;
	for(i = 0; i < 10; i++)
		printf("%d ",reg[i]);
	putchar('\n');
}

void cleanReg() {
	int i = 0;
	for(i = 0; i < 10; i++)
		reg[i] = 0;
}

int main () {
	int cases;
	char aux = 0;
	int i = 0;

	scanf("%d\n",&cases);


	while(cases--) {

		int pc = 0;
		aux = 0;
		while(aux != '\n'){
			   for(i = 0; i < 3; i++) {
				 aux = getchar();
				 if(aux == '\n') break;
				 ram[pc][i] = aux;

			   }
			if(aux != '\n'){
				getchar();
				pc++;
			}
		}

		cleanRemain(pc);
		cleanReg();

		pc = 0;


		while(ram[pc][0] != '1') {

			switch(ram[pc][0]){
			   case '2' : command2(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '3' : command3(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '4' : command4(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '5' : command5(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '6' : command6(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '7' : command7(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '8' : command8(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '9' : command9(ram[pc][1] - '0', ram[pc][2] - '0'); break;
			   case '0' : pc = command0(ram[pc][1] - '0', ram[pc][2] - '0',pc); break;
			   default: break;


			}
			pc++;
		}

		printf("%d\n\n",++counter);
		counter = 0;

	}

	return 0;
}
