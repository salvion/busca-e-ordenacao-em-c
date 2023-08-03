////////////////////////
/// Ordena��o Direta ///
////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de Vari�veis

int vetor[10000];
int i = 0;
int j = 0;
time_t t;

//Fun��o Principal

int main() {
	//Inicializa��o da aleatoridade
	srand((unsigned) time(&t));
	
	//Inicializa��o da mem�ria
	for (i = 0; i < 10000; i++) {
		vetor[i] = rand() % 10000;
	}
	
	//Ordena��o
	for (i = 0; i < 9999; i++) { //do primeiro ao pen�ltimo
		for (j = (i+1); j <10000; j++) { //do pr�ximo ao �ltimo
			if (vetor[i] > vetor[j]) {
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	//Impress�o do vetor
		for (i = 0; i < 10000; i++) {
		printf("%d\n", vetor[i]);
	}
}
