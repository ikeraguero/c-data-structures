/* Construa um programa com as seguintes opções:

1 – Incluir nova letra na pilha

2 – Excluir a letra do topo da pilha

3 – Imprimir a letra do topo da pilha

4 – Imprimir todas as letras da pilha

5 – Excluir todas as letras da pilha
Observação: O exercício deverá ser entregue com todas as funcionalidades exigidas. O VPL só poderá avaliar o código, uma vez que a operação "4-imprimir tudo" esteja funcionando corretamente. Os dados devem ser impressoes de maneira EMPILHADA.

A estrutura deve ser dinâmica e ao tentar remover elementos da pilha vazia, deve ser informada a seguinte mensagem "Pilha vazia". 

O código deve ter um loop com as opções do menu, ao ser digitada uma opção inválida, o código deve encerrar. Lembresse de comentar os printfs caso o código não esteja avaliando. */



#include <stdio.h>
#include <stdlib.h>

typedef struct Registro No;

struct Registro {
    char dados;
    No *anterior;
};

typedef struct Estrutura Pilha;

struct Estrutura {
    No *topo;
};


Pilha* alocar() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

void inserir(Pilha *p, char dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dados = dado;
    novo->anterior = p->topo;
    p->topo = novo;
}

char remover(Pilha *p) {
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return '\0';
    }
    No* auxiliar = p->topo;
    char dado = auxiliar->dados;
    p->topo = auxiliar->anterior;
    auxiliar = NULL;
    free(auxiliar);
    return dado;
}

void imprimir_topo(Pilha *p) {
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    };
    printf("%c ", p->topo->dados);
}

void imprimir_pilha(Pilha *p) {
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    };
    No *no_atual = p->topo;
    while (no_atual->anterior != NULL) {
        printf("%c\n", no_atual->dados);
        no_atual = no_atual->anterior;
    }
    if(no_atual->anterior == NULL) {
        printf("%c", no_atual->dados);
    };
}

void esvaziar(Pilha *p) {
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    };
    No *endereco;
    while(p->topo != NULL) {
        endereco = p->topo;
        p->topo = p->topo->anterior;
        endereco = NULL;
        free(endereco);
    }
    p = NULL;
    free(p);
}


int main() {
    Pilha* pilha = alocar();
    alocar(&pilha);
    int num = 0;
    char add_char; 
    do {
        scanf("%d", &num);
        if (num < 1 || num > 5) {
        break;
        }
    switch(num) {
        case 1:
            scanf(" %c", &add_char);
            inserir(pilha, add_char);
            break;
        case 2:
            remover(pilha);
            break;
        case 3:
            imprimir_topo(pilha);
            break;
        case 4:
            imprimir_pilha(pilha);
            break;
        case 5:
            imprimir_pilha(pilha);
            break;
    }
    } while (num !=0);
    free(pilha);
}