#include <stdio.h>

int reg[10]   = {0};
int ram[1000] = {0};

int counter = 0;


void printReg () {
	printf("R\n");
	int i = 0;
	for(i = 0; i < 10; i++)
		printf("%03d ",reg[i]);
	putchar('\n');
}

void command1(int c){

	counter++;
}

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
	reg[d] = ram[reg[a]];
	counter++;
}

void command9(int s, int a){
	ram[reg[a]] = reg[s];
	counter++;
}

void command0(int d, int s,int* pc){
	if(reg[s] != 0) {
		*pc = reg[d] - 1;
	}

	counter++;
}

void printMatrix(int n) {
	int i = 0;
	printf("M\n");
	for(i = 0; i < 1000 ; i++){
			printf("%03d",ram[i]);

		putchar('\n');
	}
	putchar('\n');
}

void cleanRemain (int pc) {
	int k = 0;
	for(k = pc; k < 1000; k++) {
			ram[k] = 0;
	}
}


void cleanReg() {
	int i = 0;
	for( i = 0; i < 10; i++)
		reg[i] = 0;
}

int getLine(int* valor ) {
	int i = 0;
	int sum = 0, aux = 0;
	int p = 100;
	for(i = 0; aux != '\n'; p /= 10, i++) {
		aux = getchar();
		if(aux == '\n') break;
		sum += (aux - '0') * p;
	}

	*valor = sum;
	return i;
}

int main () {
	int num,x,y;
	num = x = y = 0;
	int flag = 0;
	int cases;
	scanf("%d\n\n",&cases);

	while(cases--) {
		int pc = 0;
		flag = 0;

		if(cases) {
			while(getLine(&ram[pc++]) > 0);
		}
		else {
			while(scanf("%d\n",&ram[pc++]) != EOF);
		}




		cleanRemain(pc);
		cleanReg();


		for(pc = 0; ; pc++) {

			num = ram[pc] % 100;
			x = num / 10;
			y = num % 10;


			switch(ram[pc] / 100){
			   case 1 : command1(cases); flag = 1; break;
			   case 2 : command2(x, y); break;
			   case 3 : command3(x, y); break;
			   case 4 : command4(x, y); break;
			   case 5 : command5(x, y); break;
			   case 6 : command6(x, y); break;
			   case 7 : command7(x, y); break;
			   case 8 : command8(x, y); break;
			   case 9 : command9(x, y); break;
			   case 0 : command0(x,y,&pc); break;
			   default: break;
			}

			if(flag) break;
		}

		if(cases) printf("%d\n\n",counter);
		else printf("%d\n",counter);
		counter = 0;
	}

	return 0;
}
