#include <stdio.h>
#include <stdlib.h>

// Incluindo a biblioteca "caseira" no arquivo.
#include "lib/helper.h"

int main(void){
	printf("Usando a function pause() dessa lib.\n");
	printf("Basta chamar elas depois de um loop ou qualquer outra manipulacao que voce fez\n\n");
	
	// Chamando a pause() do helper.h
	pause();
	
	printf("\nSimples desse jeito :D\n\n");
	
	pause();
	
	return 0;
}
