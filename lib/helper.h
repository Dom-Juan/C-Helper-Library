#ifndef _HELPER_LIB_H
#define _HELPER_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <dirent.h>

// Variaveis globais nesse escopo.
char __function_flow__[8000];	// Utilizada na geracao de log do seu arquivo.c

// Declarando as functions para facilitar o call delas no seu Visual Studio, Code::Blocks, CLion, etc.

// Functions void
void pause();																				// Function para pausar o CMD onde ocorre a app
void clrscr();																				// Function para limpar o CMD, ela nao respeita o "pause" do sistema.
void printfOfCurrentFolder();																// Function para printar os arquivos do diretorio atual
void printfFileOnFolder(char *nomeDoSufixo);												// Function para printar arquivos que tenham um tipo de sufixo especifico no diretorio atual, exemploe: ".doc"
void registerLog(char log_name[50]);														// Function que pega a variavel __function_flow__ e gera um log de texto contendo os conteudos dela.
// Fim das Functions void

// Functions em int
int endsWithSuffix(const char *string, const char *sufixo);									// Function para verificar sufixos, util para arquivos
// Fim das functions em int

// Functions char
char *generateDateAndTime( char *log);
char *replaceWord(const char *string, const char *palavraAntiga, const char *novaPalavra);	// Function para trocar palavras de uma string por outras - pego de https://www.geeksforgeeks.org/
// Fim functions char

// Fim das Declaracoes.

// Macros definidos pela propria linguagem C para pausar o CMD na execucao conforme teu OS
void pause(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)	// Caso seja Linux ou Mac
    system("read -p 'Press Enter to continue...' var");
#endif

#if defined(_WIN32) || defined(_WIN64) 								// Windows 32 ou 64 bits
    system("pause");
#endif

}

// Limpa a tela da aplicacao, mas nao respeitava o system pause, descontinuado.
void old_clrscr() {
    system("@cls||clear"); // Comando para limpar a tela.
    fflush(stdin);		   // Limpando o buffer do teclado.
}

// Limpando a tela conforme o sistema operacional do usuario, tambem definido por macros
void clrscr(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)	// Caso seja Linux ou Mac
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)								// Windows 32 ou 64 bits
    system("cls");
#endif
}

// Printa arquivos no diretorio atual do programa.
void printfOfCurrentFolder(){
	
	DIR *dir;				// Ponteiro do tipo diretorio para o diretorio atual. 
    struct dirent *lsdir;	// Ponteiro para uma estrutura do tipo diretorio.
    dir = opendir(".");		// Abrindo o diretorio.

    printf("      **Files  on this directory**\n");
    printf(" >Found!\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {    // Percorrendo todos so arquivos do diretorio.
        printf ("%s\n", lsdir->d_name); 			// printando os arquivos.
    }  
}

// Printa arquivos com um sufixo determinado pelo usuario no diretorio atual do programa.
void printfFileOnFolder(char *nomeDoSufixo){
	
	DIR *dir;				// Ponteiro do tipo diretorio para o diretorio atual. 
    struct dirent *lsdir;	// Ponteiro para uma estrutura do tipo diretorio.
    dir = opendir(".");		// Abrindo o diretorio.

    printf("      **Files with %s suffix on this directory**\n");
    printf(" >Found!\n");
    while ( ( lsdir = readdir(dir) ) != NULL ) {    		// So mostra o nome dos arquivos do mesmo sufixo escrito
        if(endsWithSuffix (lsdir->d_name,nomeDoSufixo)){	// So mostra o arquivo, se ele terminar com o sufixo determinado pelo usuario. 
            printf ("%s\n", lsdir->d_name);					// printando os arquivos de mesmo sufixo.
        }
    }
	
	closedir(dir); // fechando o diretorio.
}

// Criar o arquivo de log com o fluxo das functions
void registerLog(char log_name[50]){
    FILE *log_file; // variavel para o arquivo de text que contera o log

    if( (log_file = fopen(log_name,"w+")) != NULL){

        fprintf(log_file,"Execution: ");
        fprintf(log_file,"%s",__function_flow__);

        fclose(log_file);

    } else {
        printf("Error, could not create log file.");
        fclose(log_file);

    }
}

// Compra os sufixo do nome do arquivo com a o sufixo dado e retorna um valor boleano
int endsWithSuffix(const char *string, const char *sufixo) { // Compra os sufixo do nome do arquivo com a o sufixo dado
    int stringTamanho = strlen(string); // Pegando o tamanho da string
    int tamanhoSufixo = strlen(sufixo); // Pegando o tamanho do sufixo

    return (stringTamanho >= tamanhoSufixo) &&
           (strcmp(string + (stringTamanho-tamanhoSufixo), sufixo) == 0); // Retorna um valor booleano, depedendo da condicao.
}

// Retorna uma string com caracteres trocados.
char *replaceWord(const char *string, const char *palavraAntiga, const char *novaPalavra) {
    char *resultado;
    int i, contador = 0;
    int tamanhoDaNovaPalavra = strlen(novaPalavra);
    int tamanhoDaPalavraAntiga = strlen(palavraAntiga);

    // Contando o total de ocorrencias do char a ser substituido
    for (i = 0; string[i] != '\0'; i++) {
        if (strstr(&string[i], palavraAntiga) == &string[i]) {
            contador++;

            // saltando de um indice ate o outro na string antiga.
            i += tamanhoDaPalavraAntiga - 1;
        }
    }

    // Criando uma nova string com tamanho necessario
    resultado = (char *)malloc(i + contador * (tamanhoDaNovaPalavra - tamanhoDaPalavraAntiga) + 1);

    i = 0;
    while (*string) {
        // comparando a substring com o resultado
        if (strstr(string, palavraAntiga) == string) {
            strcpy(&resultado[i], novaPalavra);
            i += tamanhoDaNovaPalavra;
            string += tamanhoDaPalavraAntiga;
        }
        else
            resultado[i++] = *string++;
    }

    resultado[i] = '\0'; // "Fechando" a string resultado com o '\0' para identificar aonde a string para.
    return resultado;	 // Retornando o resultado da troca.
}

// Retorna uma data e hora do sistema.
char *generateDateAndTime( char *log){
	int MAX = 1000;											// Taamnho para a string.
	char string[MAX];										// string que recebe o "assert" dos valores gerados na variavel tempo.
															// A variavel tm é um ponteiro para o tempo e data pegado no sistema
	time_t tempo = time(NULL);                      		// Setando a variavel tempo.
    struct tm *tm = localtime(&tempo);              		// Pegando o tempo local.
    assert(strftime(string, sizeof(string), "%c", tm));   	// Concatenando o tempo com a data atual string anterior.
    strcat(log,string);										// Concatenando as strings.
    
	free(string);											// Liberando memória, se livrando da string auxiliar "string".
    
	return log;												// Retorno da string com o tempo e data atual ( aka dia de hoje).
}

#endif
