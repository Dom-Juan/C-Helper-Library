#include <stdio.h>
#include <stdlib.h>

#include "lib/helper.h"

int main(void){
		printf("Usar a function *generateDateAndTime( char *string_passada); eh simples, basta apenas passar uma variavel do tipo string \npara a functionque ela retorna a data e hora do dia de hoje.\n\n");
		
		//String para onde o conteudo eh copiado dentro da function generateDateAndTime(string);
		char string[35];
		
		printf("A string que deve-se passar, tem que ter tamanho 35!\n\n");
		printf("Chamando a function...\n");
		
		char *outra_string = generateDateAndTime(string);
		
		printf("Resultado: %s\n",outra_string);
		printf("\n");
		pause();
		
		printf("\nSimples desse jeito :D\n\n");
		printf("Talvez seja um jeito um pouco mais complicado de fazer o strftime, mas tem suas utilidades!\n\n");
		pause();
		
	return 0;
}
