////////////////////////////////////////
// Programa lista encadeada circular ///
////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//Declaracao de no

struct no {
	int numero;
	struct no *proximo;
	struct no* anterior;
};

//Declaracao de variaveis

struct no *cabeca = NULL;

//Funcao que insere um no na lista

void inserir (int numero) {
	//Alocacao de memoria para um novo no
	struct no *novoNo;
	novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		//caso facil, lista vazia
		cabeca = novoNo;
		novoNo -> proximo = cabeca;
	} else {
		//caso dificl, a lista NAO estava vazia
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
		novoNo -> proximo = cabeca;
	}
}

//Imprimir
void imprimir() {
	printf("------------------------\n");
	
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

//Funcao que remove um no da lista
void remover(int numero) {
	struct no *ptrExcluir = cabeca;
	//se estiver no inicio da lista
	if (cabeca -> numero == numero) {
		cabeca = cabeca -> proximo;
		cabeca -> anterior = NULL;
		free(ptrExcluir);
	} else {
		while (ptrExcluir != NULL) {
			if (ptrExcluir -> numero == numero) {
				if (ptrExcluir -> proximo != NULL) {
					//se estiver no meio da lista
					ptrExcluir -> proximo -> anterior = ptrExcluir -> anterior;
					ptrExcluir -> anterior -> proximo = ptrExcluir -> proximo;
					free(ptrExcluir);
				} else {
					//se estiver no final da lista
					ptrExcluir -> anterior -> proximo = NULL;
					free(ptrExcluir);
				}
			}
			ptrExcluir = ptrExcluir -> proximo;
		}
		
	}
}

////////////////////////////////////////////////
int main() {
	inserir(1);
	inserir(2);
	
	imprimir();
	
	remover(2);
	
	imprimir();
}
