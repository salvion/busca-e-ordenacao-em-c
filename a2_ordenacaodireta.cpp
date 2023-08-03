////////////////////////
/// Ordenação Direta ///
////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de Variáveis

int vetor[10000];
int i = 0;
int j = 0;
time_t t;

//Função Principal

int main() {
	//Inicialização da aleatoridade
	srand((unsigned) time(&t));
	
	//Inicialização da memória
	for (i = 0; i < 10000; i++) {
		vetor[i] = rand() % 10000;
	}
	
	//Ordenação
	for (i = 0; i < 9999; i++) { //do primeiro ao penúltimo
		for (j = (i+1); j <10000; j++) { //do próximo ao último
			if (vetor[i] > vetor[j]) {
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	//Impressão do vetor
		for (i = 0; i < 10000; i++) {
		printf("%d\n", vetor[i]);
	}
}
