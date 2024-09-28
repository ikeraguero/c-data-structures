/*Construa um programa com as seguintes opções:

1 – Incluir nova letra na pilha

2 – Excluir a letra do topo da pilha

3 – Imprimir a letra do topo da pilha

4 – Imprimir todas as letras da pilha

5 – Excluir todas as letras da pilha*/

#include <stdio.h>
#define TAMANHO 20

typedef struct Estrutura {
    int dados[TAMANHO];
    int indice;
} Pilha;

void alocar(Pilha *p) {
    p->indice = -1;
}

void adicionar(Pilha *p) {
    if(p->indice == TAMANHO-1) {
        printf("Pilha cheia");
        return;
    }
    char letra;
    scanf(" %c", &letra);

    p->indice++;
    p->dados[p->indice] = letra;
}

int excluir(Pilha *p) {
    if(p->indice == -1) {
        printf("Pilha vazia");
        return 0;
    }

    p->indice = p->indice -1;
    return p->dados[p->indice+1];
}

int imprimir_topo(Pilha *p) {
    if(p->indice == -1) {
        printf("Pilha vazia");
        return 0;
    }

    printf("%c\n", p->dados[p->indice]);
}

int imprimir_tudo(Pilha *p) {
    if(p->indice == -1) {
        printf("Pilha vazia");
        return 0;
    }

    for(int i=p->indice; i>=0; i--) {
        printf("%c\n", p->dados[i]);
    }
}

int excluir_tudo (Pilha *p) {
    if(p->indice == -1) {
        printf("Pilha vazia");
        return 0;
    }

    p->indice = -1;
}

int main() {
    Pilha pilha;
    alocar(&pilha);
    int num =0;
    
    do {
        
    scanf("%d", &num);
        if (num < 1 || num > 5) {
        break;
    }
    switch (num)
    {
    case 1:
        adicionar(&pilha);
        break;
    
    case 2:
        excluir(&pilha);
        break;
    case 3:
        imprimir_topo(&pilha);
        break;
    case 4:
        imprimir_tudo(&pilha);
        break;
    case 5:
        excluir_tudo(&pilha);
        break;
    default:
        break;

    } 
} while (num != 0);
    
}

    