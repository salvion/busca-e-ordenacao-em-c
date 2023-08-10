///////////////////////
// Programa de Lista //
// de encadeamento ////
// simples ////////////
///////////////////////

#include <stdio.h>
#include <stdlib.h>

//Declaracao de estrutura
struct no{
	int numero;
	struct no *proximo;
};

//Declaracao de variavel
struct no *cabeca = NULL;

//inserir no final da lista
void inserir (int num){
	struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	novoNo -> numero = num;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL){
		cabeca = novoNo;
	} else {
		struct no *ponteiro;
		ponteiro = cabeca;
		while (ponteiro -> proximo != NULL){
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
	}
}
	
//Imprime a lista na tela
void imprimir() {
	struct no *ponteiro;
	
	ponteiro = cabeca;
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

//Deletar elemento da lista
void deletar(int num){
	struct no* lixo;
	struct no *anterior;
	lixo = cabeca;
	
	//Caso o elemento esteja na primeira posição
	if (cabeca -> numero == num){
		cabeca = cabeca -> proximo;
		free(lixo);
	} else {	
		//Caso o elemento esteja no meio
		anterior = cabeca;
		while ((anterior -> proximo != NULL) && (anterior -> proximo -> numero != num)){
			anterior = anterior -> proximo;
		}
		if (anterior -> proximo != NULL) {
			lixo = anterior -> proximo;
			anterior -> proximo = lixo -> proximo;
			free(lixo);
		}
	}
}
	

//Função principal
int main(){
	for (int i = 0; i <= 100; i++){
		inserir(i);
	}
	imprimir();
}
