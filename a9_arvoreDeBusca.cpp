/////////////////////////////////////////////////
// Programa que implementa uma Árvore de busca //
/////////////////////////////////////////////////

//elemento maior --> subarvore direita
//elemento menor --> subarvore esquerda

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definicao de estrutura do no da arvore

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
}; 

//Funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL) {
		// Caso fácil, árvore esta vazia
		raiz = (struct no*) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else {
		//Caso dificil, arvore nao esta vazia
		if (numero < raiz -> numero) {
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		} else {
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	
	return raiz;
}

//Funcao que busca um no na arvore

void buscar(struct no *raiz, int numero) {
	if (raiz == NULL) {
		//arvore vazia
		printf("Nao achei!");
	} else if (raiz -> numero == numero) {
		//numero na raiz
		printf("Achei !");
	} else if (raiz -> numero > numero) {
		//numero menor que a raiz
		buscar (raiz -> esquerda, numero);
	} else if (raiz -> numero < numero) {
		//numero maior que a raiz
		buscar(raiz -> direita, numero);
	}
}

//Funcao que navega arvore em ordem

void navegar(struct no *raiz) {
	if (raiz != NULL) {
		navegar(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegar(raiz -> direita);
	}
}

//Funcao que desenha um menu na tela

int menu() {
	int opcao;
	
	printf("+=====================================+\n");
	printf("|            Menu de Opcoes           |\n");
	printf("+=====================================+\n");
	printf("|    1 - inserir                      |\n");
	printf("|    2 - buscar                       |\n");
	printf("|    3 - navegar                      |\n");
	printf("|    4 - inicializar arvore aleatoria |\n");
	printf("|    5 - sair                         |\n");
	printf("+=====================================+\n");
	printf("Digite sua opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

//Funcao principal de execucao desse programa

int main() {
	//Declaracao de variaveis
	struct no *raiz = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	//Inicializacao aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	//Inicializacao da arovore
	while (opcao != 5) {
		opcao = menu();
		
		if (opcao == 1) {
			printf("Digite o numero: ");
			scanf("%d\n", &numero);
			raiz = inserir(raiz, numero);
		} else if (opcao == 1) {
			printf("Digite o numero: ");
			scanf("%d\n", &numero);
			raiz = inserir(raiz, numero);
		} else if (opcao == 3) {
			navegar(raiz);
		} else if (opcao == 4) {
			for (i = 0; i < 1000000; i++) {
				raiz = inserir (raiz, rand());
			}
		}
	}
	
}
