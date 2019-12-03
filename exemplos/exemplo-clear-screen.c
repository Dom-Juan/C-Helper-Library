#include <stdio.h>
#include <stdlib.h>

// Incluindo a biblioteca "caseira" no arquivo.
#include "lib/helper.h"

int main(void){
	printf("Usando a function clrscr() dessa lib.\n");
	printf("Basta chamar elas depois de um loop ou qualquer outra manipulacao que voce fez\n\n");
	
	// Chamando a clrscr()do helper.h
	
	int a = 2;
	int b = 3;
	int c = 0;
	
	c = a + b;
	
	printf("O valor de a eh %d\n",a);
	printf("O valor de b eh %d\n",b);
	printf("O resultado da soma de a + b = %d\n\n",c);
	
	printf("Utilizando o pause() da biblioteca para voce apreciar essa conta maravilhosa :3\n");
	
	pause();
	clrscr();
	
	printf("\nSimples desse jeito :D\n\n");
	
	pause();
	
	return 0;
}
