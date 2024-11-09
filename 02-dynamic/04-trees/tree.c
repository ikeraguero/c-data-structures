#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void imprimir(No *folha, int nivel){
    if(folha == NULL){
        puts("");
        for (int i = 0; i < nivel; i++) printf("\t");
        printf("#\n");
    }else{
        imprimir(folha->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("\t");
        printf("%d", folha->numero);
        imprimir(folha->esquerda, nivel + 1);
        
    }
}

Arvore *alocar() {
        Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));
        arvore->raiz=NULL;
        return arvore;

    }

    No *inserir(No *folha, int valor) {
        if (folha == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->numero = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (valor < folha->numero) {
        folha->esquerda = inserir(folha->esquerda, valor);
    } else if (valor > folha->numero) {
        folha->direita = inserir(folha->direita, valor);
    } else {
        return folha;
    }

    return folha;
    }

    int raiz(Arvore *arv) {
        if (arv->raiz != NULL) {
        return arv->raiz->numero;
    } else {
        printf("A árvore está vazia.\n");
        return -1;
        }
    }

    void folhas(No *folha){
        if (folha != NULL) {
        if (folha->esquerda == NULL && folha->direita == NULL) {
            printf("%d ", folha->numero);
        }
        folhas(folha->esquerda);
        folhas(folha->direita);
        }
    }

    void pre(No *folha) {
        if (folha != NULL) {
        printf("%d ", folha->numero);
        pre(folha->esquerda);
        pre(folha->direita);
    }
    }

    void em(No *folha) {
        if (folha != NULL) {
        em(folha->esquerda);
        printf("%d ", folha->numero);
        em(folha->direita);
        }
    }

    void pos(No *folha) {
        if (folha != NULL) {
        pos(folha->esquerda);
        pos(folha->direita);
        printf("%d ", folha->numero);
    }
    }

    void procurar(No *folha, int valor) {
         if (folha == NULL) {
        return;
    }

    if (valor == folha->numero) {
        printf("%d .\n", valor);
    } else if (valor < folha->numero) {
        procurar(folha->esquerda, valor);
    } else {
        procurar(folha->direita, valor);
        }
    }

    void apagarFolha(No *folha, int valor) {
        if (folha == NULL) return;

    if (folha->esquerda != NULL && folha->esquerda->numero == valor && folha->esquerda->esquerda == NULL && folha->esquerda->direita == NULL) {
        free(folha->esquerda);
        folha->esquerda = NULL;
        printf("Folha %d apagada.\n", valor);
    } else if (folha->direita != NULL && folha->direita->numero == valor && folha->direita->esquerda == NULL && folha->direita->direita == NULL) {
        free(folha->direita);
        folha->direita = NULL;
        printf("Folha %d apagada.\n", valor);
    } else {
        apagarFolha(folha->esquerda, valor);
        apagarFolha(folha->direita, valor);
    }
    }

    int altura(No *folha) {
       if (folha == NULL) {
        return -1;
    } else {
        int alturaEsquerda = altura(folha->esquerda);
        int alturaDireita = altura(folha->direita);
        return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
    } 
    }

    void apagarTudo(No *folha) {
        if (folha != NULL) {
        apagarTudo(folha->esquerda);
        apagarTudo(folha->direita);
        free(folha);
    }
    }

