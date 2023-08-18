///////////////////////
/// Busca Binária ///// TEM QUE ESTAR PREVIAMENTE ORDENADA
///////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de Variáveis
int vetor[100];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 99;
int meio = 0;

//Função Principal
int main() {	
	//Inicialização da memória
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
			printf("achei, posuição %d", meio);
			return 0;
		} else if (vetor[meio] > busca) {
			fim = (meio - 1);
		} else {
			inicio = (meio + 1);
		}
	}
	printf("nao achei");

}
