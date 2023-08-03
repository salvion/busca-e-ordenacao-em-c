//////////////////////////////
/// Ordenação Bubble Sort ///
/////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de Variáveis

int vetor[10000];
int i = 0;
int troquei = 0;
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
	troquei = 1;
	while (troquei) {
		troquei = 0;
		
		for (i = 0; i < 9999; i++) {
			if (vetor[i] > vetor[i+1]) {
				int temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				troquei = 1;
			}
		}
	}
	
	//Impressão do vetor
		for (i = 0; i < 10000; i++) {
		printf("%d\n", vetor[i]);
	}
}
