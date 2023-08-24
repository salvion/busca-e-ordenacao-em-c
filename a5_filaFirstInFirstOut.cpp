///////////////////////////////////////////
// Programa que implementa uma fila FIFO //
///////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

//Declaracao da estrutura do no

struct no {
	int numero;
	struct no *proximo;
};

//Declaração de variaveis

struct no *cabeca = NULL;

//Funcao que insere um no na fila

void inserir(int num) {
	//Alocacao de memoria
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = num;
	
	//Entrar na fila
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

//Remover no da fila

int remover() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {
			//So tem um no na fila
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		} else {
			//Tem mais de um no na lista
			struct no *ponteiro = cabeca;
			
			//Navegando pela lista
			while (ponteiro -> proximo -> proximo != NULL) {
				ponteiro = ponteiro -> proximo;
			}
			
			//Removendo o ultimo no
			retorno = ponteiro -> proximo -> numero;
			free(ponteiro -> proximo);
			ponteiro -> proximo = NULL;
		}
	}
	
	return retorno;
}

/////////////////////////////////////////////////////////////////////////

int main() {
	printf("%d\n", remover());
	printf("==============================\n");
	
	inserir(1);
	printf("%d\n", remover());
	printf("==============================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
}
