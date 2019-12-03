#include <stdio.h>
#include <stdlib.h>

// Incluindo a biblioteca "caseira" no arquivo.
#include "lib/helper.h"

int main(void){
	printf("Usando a function printfOfCurrentFolder(), essa function mostra na tela do usuario\napenas os arquivos do diretorio atual.\n\nVamos ver os arquivos neste diretorio exemplo!\n");
	pause();
	
	printfOfCurrentFolder();
	printf("\n\nOs '.' e '..' sao outros diretorios, sendo o '.' o diretorio aonde esta as coisas e '..' um diretorio dentro do diretorio '.'\n");
	printf("\n");
	
	pause();
	clrscr();
	
	printf("Agora vamos ver a printfFileOnFolder(char *nomeDoSufixo), essa function funcioma como a printfOfCurrentFoldeR()\nmas ela mostra so arquivos com um sufixo especifico.\n\n");
	pause();
	
	printf("\n\nPassando uma string para mostra so arquivos que terminam em .c\n");
	printf("Ela utiliza a function endsWithSuffix(string, sufixo) para verificar o tipo de sufixo que foi passado\n\n");
	printfFileOnFolder(".c");
	
	printf("\nSimplesmente assim mesmo :v\n");
	pause();
	
	return 0;
}
