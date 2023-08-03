///////////////////////
/// Busca Bin�ria ///// TEM QUE ESTAR PREVIAMENTE ORDENADA
///////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de Vari�veis
int vetor[100];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 99;
int meio = 0;

//Fun��o Principal
int main() {	
	//Inicializa��o da mem�ria
	for (i = 0; i < 100; i++) {
		vetor[i] = i;
	}
	
	
	//Descoberta do parametro de busca
	printf("Digite um valor pra ser buscado: ");
	scanf("%d", &busca);
	
	//Busca propriamente dita
	while (fim >= inicio) {
		meio = (inicio + fim) / 2;
		
		if (vetor[meio] == busca) {
			printf("achei, posui��o %d", meio);
			return 0;
		} else if (vetor[meio] > busca) {
			fim = (meio - 1);
		} else {
			inicio = (meio + 1);
		}
	}
	printf("nao achei");

}
