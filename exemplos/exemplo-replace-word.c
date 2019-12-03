#include <stdio.h>
#include <stdlib.h>

#include "lib/helper.h"

int main(void){
	char name[10] = "Pedro";
	
		printf("Usando a replaceWord(const char *string, const char *palavraAntiga, const char *novaPalavra) eh simples.\n");
		printf("Basta botar o nome da string resultado,a string antiga, e a string que voce quer remover\n");
		printf("Exemplo:\n\n");
		printf("Temos %s na variavel name e queremos trocara e letra 'e' por 'a', logo\n",name);
		printf("chamamos a function como: strcpy(name,replaceWord(name, \"e\", \"a\"));\n");
		
		strcpy(name,replaceWord(name, "e", "a"));
		pause();
		printf("\nResultado: %s\n", name);
		
		printf("\nSimplesmente incrivel UwU\n\n");
		pause();
		
	return 0;
}
