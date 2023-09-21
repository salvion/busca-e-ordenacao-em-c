//////////////////////////////////////////////////////////////////////////
// Programa que implementa arvore binaria e suas respectivas navegacoes //
//////////////////////////////////////////////////////////////////////////

//TRAVESSIA (mundo oriental troca a esquerda com a direita e nao faz diferenca):
//pré ordem (raiz, esquerda, direita) se o num estiveer mais no comeco;
//em ordem (esquerda, raiz, direita) se o num estiver na media;
//pos ordem (esquerda, direita, raiz) se o num estiver mais no final, for mais recente;

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//Declaração de estruturas

struct no{  
    int numero;
    struct no *esquerda;
    struct no *direita;
};

//Função que insere um no na árvore

struct no *inserir(struct no *raiz, int numero){
    //caso fácil: árvore está vazia
    if (raiz == NULL) {
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else {
        //caso difícil: arvore nao esta vazia
        if ((rand() % 2) == 0) {
            raiz -> esquerda = inserir (raiz -> esquerda, numero);
        } else {
            raiz -> direita = inserir (raiz -> direita, numero);
        }
    }
    return raiz;
}

///////Navegação pré-ordem
void navegarPreOrdem(struct no *raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    }
}

//////Navegação em ordem
void navegarEmOrdem(struct no *raiz) {
    if (raiz != NULL) {
        navegarPreOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> direita);
    }
}

//////Navegação pós-ordem
void navegarPosOrdem(struct no *raiz) {
    if (raiz != NULL) {
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
        printf("%d\t", raiz -> numero);
    }
}



//Função principal de execução do programa
int main(){
    //Declaração da árvore
    struct no *raiz = NULL;

    //Inicialização da aleatoriedade
    time_t t;
    srand((unsigned) time(&t));

    //Preenchimento da árvore
    for (int i = 0; i < 3; i++) {
        raiz = inserir(raiz, i);
    }

    //Navegações
    printf("==========PRÉ-ORDEM============");
    navegarPreOrdem(raiz);
    printf("==========EM-ORDEM============");
    navegarEmOrdem(raiz);
    printf("==========PÓS-ORDEM============");
    navegarPosOrdem(raiz);
}