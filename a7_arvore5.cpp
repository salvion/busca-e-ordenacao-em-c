//////////////////////////////////////////
//  Programa que implementa uma árvore  //
//////////// de ordem 5 //////////////////
//////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Declaracao de Estruturas

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

//Inserir um no (elemento) na arvore

struct no *inserir(struct no *raiz, int numero){
	if (raiz == NULL) {
		//Caso fácil: a arvore esta vazia
		raiz = (struct no*) malloc(sizeof(struct no));
		
		raiz -> numero = numero;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	} else {
		//Caso difícil: a arvora NAO esta vazia
		int sorteio = (rand() % 5);
		
		if (sorteio == 0) {
			raiz -> filho1 = inserir(raiz -> filho1, numero);
		};
		if (sorteio == 1) {
			raiz -> filho2 = inserir(raiz -> filho2, numero);
		};
		if (sorteio == 2) {
			raiz -> filho3 = inserir(raiz -> filho3, numero);
		};
		if (sorteio == 3) {
			raiz -> filho4 = inserir(raiz -> filho4, numero);
		};
		if (sorteio == 4) {
			raiz -> filho5 = inserir(raiz -> filho5, numero);
		};	
	}
	
	return raiz;
}

//Funcao que imprime a arvore
void imprimir(struct no *raiz, char *endentacao) {
	if (raiz != NULL) {
	printf("%s%d\n", endentacao, raiz -> numero);
	
	char *temp = (char *) malloc(1024 *sizeof(char));
	strcpy(temp, endentacao);
	strcat(temp, "---");
	
	imprimir(raiz -> filho1, temp);
	imprimir(raiz -> filho2, temp);
	imprimir(raiz -> filho3, temp);
	imprimir(raiz -> filho4, temp);
	imprimir(raiz -> filho5, temp);
	}		
}

//////////////////////////////////////////////
// Funcao principal de execucao do programa //
//////////////////////////////////////////////

int main() {
	//Declaracao de variaveis
	struct no *raiz = NULL;
	time_t t;
	char *endentacao = (char *) malloc(1024 *sizeof(char));

	
	//inicializacao da aleatoriedade
	srand((unsigned) time(&t));
	
	//Manipulacao da arvore
	int opcao = 0;
	
	while (opcao!= 3){
		printf("+=================+\n");
		printf("|       Menu      |\n");
		printf("+=================+\n");
		printf("|    1-inserir    |\n");
		printf("|    2-imprimir   |\n");
		printf("|    3-sair       |\n");
		printf("+=================+\n");
		printf("Digite sua opcao: ");
		scanf("%d", &opcao);
		
		if (opcao == 1) {
			int numero = 0;
			printf("Digite o numero: ");
			scanf("%d", &numero);
			raiz = inserir(raiz, numero);
		} else if (opcao == 2) {
			imprimir(raiz, endentacao);
		}
	}
}

