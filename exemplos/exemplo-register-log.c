#include <stdio.h>
#include <stdlib.h>

#include "lib/helper.h"

int somar(int a, int b){
	int c;
	return (c = a + b);
}

int main(void){
		printf("Usar a function registerLog(char log_name[50]) eh um pouquinho complicado.\nUma vez que  voce precisa escolher como concatenar aonde ou o que esta sendo feito para a __function_flow__[8000]\n");
		printf("Exemplo, vamos supor nesse programa existe uma function que realiza somas, entre 2 numeros e retorna o resultado\nVoce deve concatenar com strcat(), o nome da function e a variavel __function_flow_\n");
		printf("\n\nSoma de %d + %d = %d\n\n",2,3,somar(2,3));
		pause();
		
		printf("\nChamando a registerLog(log.txt) com log.txt como nome para log_name[50]\n\n");
		strcat(__function_flow__,"\n-->int somar(int a, int b)");
		registerLog("log.txt");

		printf("Nao se esqueca de colocar sua propria varaivel com nome dentro da registerLog(char log_name[50])\n\n");
		
		printf("\nNao tao Simples desse jeito, mas ta ai :D\n\n");
		pause();
		
	return 0;
}
