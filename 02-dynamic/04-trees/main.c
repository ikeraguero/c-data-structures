#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Construa um programa com as seguintes opções para uma estrutura de ávore binária:

// 1 – Inserir número (proibir a inserção de números repetidos)

// 2 – Procurar número

// 3 – Excluir número (Apenas para folhas)

// 4 – Imprimir pré-ordem

// 5 – Imprimir em-ordem

// 6 – Imprimir pós-ordem

// 7 – Imprimir raiz

// 8 – Imprimir folhas

// 9– Imprimir altura

// 10 – Excluir todos os números

int main() {
    int opcao;
    int sair = 1;
    int num;

    Arvore *arv1 = alocar();

    do {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                scanf("%d", &num);
                arv1->raiz = inserir(arv1->raiz, num);
                break;

            case 2:
                scanf("%d", &num);
                procurar(arv1->raiz, num);
                break;

            case 3:
                scanf("%d", &num);
                apagarFolha(arv1->raiz, num);
                break;

            case 4: 
                pre(arv1->raiz);
                break;

            case 5:
                em(arv1->raiz);
                break;

            case 6: 
                pos(arv1->raiz);
                break;

            case 7: 
                if (arv1->raiz != NULL) {
                    printf("%d\n", arv1->raiz->numero);
                }
                break;

            case 8:
                folhas(arv1->raiz);
                break;

            case 9: 
                printf("%d\n", altura(arv1->raiz));
                break;

            case 10: 
                apagarTudo(arv1->raiz);
                arv1->raiz = NULL;
                break;

            case 11:
                if (arv1->raiz != NULL) {
                    imprimir(arv1->raiz, 0);
                }
                break;

            default:
                sair = 0;
                break;
        }
    } while (sair);

    return 0;
}
