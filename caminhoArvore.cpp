/////////////////////////////////////////////////////
// Programa que implementa a descoberta de caminho //
/////////////////////////////////////////////////////

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//Declara��o de constantes
const int VERTICE = 5;

//Fun��o que cria um gr�fico
void criar (int grafo[VERTICE][VERTICE], int aleatoria) {
	int aresta = 0;
	for (int i = 0; i < VERTICE-1; i++) {
		for (int j = (i+1); j < VERTICE; j++) {
			if (aleatoria) {
				aresta = (rand()%2);
			} else {
				printf("Digite <1> se %d estiver conectado a %d: ", i, j);
				scanf("%d", &aresta);
			}
			
			grafo[i][j] = aresta;
			grafo[j][i] = aresta;
		}
	}
}

//Fun��o que descobre o caminho entre dois vertices de um grafo
int procurar (int grafo[VERTICE][VERTICE], int visitado[VERTICE], int inicio, int fim) {
	int vizinho = 0;
	int retorno = 0;
	
	if (inicio == fim) {
		retorno = 1;
	} else {
		visitado[inicio] = 1;
		
		for (vizinho = 0; vizinho < VERTICE; vizinho++){
			if ((grafo[inicio][vizinho]) && (! visitado[vizinho])){
				if (procurar(grafo, visitado, vizinho, fim)){
					retorno = 1;
					printf("%d <- ", vizinho);
					break;
				}
			}
		}
	}
}

//Fun��o que inicializa e executa a uncao do caminho entre dois vertices de um grafo
int procurarPercurso (int grafo[VERTICE][VERTICE], int inicio, int fim) {
	int visitado[VERTICE];
	int encontrei = 0;
	
	for (int i = 0; i < VERTICE; i++) {
		visitado[i] = 0;
	}
	
	encontrei = procurar(grafo, visitado, inicio, fim);
	printf("%d\n", inicio);
	
	return encontrei;
}

//Fun��o Principal
int main(){
	//Declara��o de vari�veis
	int grafo[VERTICE][VERTICE];
	int inicio = 0;
	int fim = 0;
	
	//Inicializa��o da aleatoriedade
	time_t t;
	srand((unsigned) time(&t));
	
	//Cria��o do grafo
	criar(grafo, 0);
	
	//Descoberta de caminhos
	while (inicio != -1) {
		printf("\nDigite o vertice inicial: ");
		scanf("%d", &inicio);
		printf("\nDigite o vertice final: ");
		scanf("%d", &fim);
		
		if (procurarPercurso(grafo, inicio, fim)){
			printf("Encontrei um caminho!\n\n");
		} else {
			printf("Nao encontrei um caminho!\n\n");
		}
	}
} 

