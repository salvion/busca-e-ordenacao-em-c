///////////////////////
/// Busca Exaustiva ///
///////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de Vari�veis
int vetor[10000];
int i = 0;
int busca = 0;
int achei = -1;
time_t t;

//Fun��o Principal
int main() {
	//Inicializa��o da aleatoridade
	srand((unsigned) time(&t));
	
	//Inicializa��o da mem�ria
	for (i = 0; i < 10000; i++) {
		vetor[i] = rand() % 10000;
	}
	
	//Descoberta do parametro de busca
	printf("Digite um valor pra ser buscado: ");
	scanf("%d", &busca);
	
	//Busca propriamente dita
	for (i = 0; i < 10000; i++){
		if (vetor[i] == busca) {
			achei = i; 
		}
	}
	if (achei == -1) {
		printf("vish");
	} else {
		printf("achei, na posi��o %d", achei);
	}
}
