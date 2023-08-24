////////////////////////////////////////////
// Programa que implementa uma pilha FILO //
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Declaracao estrutura do no

struct no {
	int numero;
	struct no *proximo;
};

// Declaracao de variaveis

struct no *cabeca;

// Funcao que insere um no na pilha 

void push(int numero) {
	//Alocacao de memoria
	struct no *novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	//Empilhamento
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

//Funcao que verifica primeiro no da pilha

int top() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		retorno = cabeca -> numero;
	}
	
	return retorno;
}

// Funcao que remove um no da pilha  

int pop() {
	int retorno = -1;
	
	if (cabeca != NULL){
		struct no *ponteiroExcluir = cabeca;
		retorno = cabeca -> numero;
		cabeca = cabeca -> proximo;
		free(ponteiroExcluir);
	}
	
	return retorno;
	
}

///////////////////////////////////////////////////////////////

int main() {
	printf("%d\n", pop());
	printf("==============================\n");
	
	push(1);
	printf("%d\n", pop());
	printf("==============================\n");
	
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}
