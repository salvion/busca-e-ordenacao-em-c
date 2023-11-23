////////////////////////////////////////////////////////////////
// Programa que implementa a ordenação topológica em um Grafo //
////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaracao de constantes 

const int VERTICE = 50;

//Funcao que cria o grafo

void criar(int grafo[VERTICE][VERTICE], int aleatorio) {
	
	int aresta = 0;
	
	for (int i = 0; i < VERTICE ; i++) {
		for (int j = 0; j < VERTICE; j++) {
			if (aleatorio) {
				aresta = (rand() % 2);
			} else {
				printf("Digite <1> de %d estiver conectado a %d: ", i, j);
				scanf("%d", &aresta);
			}
			
			grafo[i][j] = aresta;
		}
	}
}

//Funçao recursiva que organiza topologicamente um grafo

void ordenarRecursivo(int grafo[VERTICE][VERTICE], int visitado[VERTICE], int vertice) {
	
	visitado[vertice] = 1;
	
	for (int i = 0; i < VERTICE; i++) {
		if ((grafo[vertice][i]) && (! visitado[i])) {
			ordenarRecursivo(grafo, visitado, i);
		}
	}
	
	printf("%d\t", vertice);
}

// Função que ordena topologicamente um grafo

void ordenar(int grafo[VERTICE][VERTICE]) {
	
	int visitado[VERTICE];
	
	for (int vertice = 0; vertice < VERTICE; vertice++) {
		visitado[vertice] = 0;
	}
	
	for (int vertice = 0; vertice < VERTICE; vertice++) {
		if (! visitado[vertice]) {
			ordenarRecursivo(grafo, visitado, vertice);
		}
	}
	
	printf("\n");
}

//Função principal de execucao do programa 

int main(){
	//Declaração de variáveis
	int grafo[VERTICE][VERTICE];
	
	//inicializacao da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	//Criacao do grafo
	criar(grafo, 1);
	
	//Ordenacao do grafo;
	ordenar(grafo);
}
