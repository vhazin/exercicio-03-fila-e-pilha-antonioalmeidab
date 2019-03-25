#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *next;
} node;

node *preencheFila(int qtdElementos, node *inicio, node *atual){
    int i = 0;
    while(i < qtdElementos){
        node *novo = malloc(sizeof(node));
        int dado;
        scanf("%d", &dado);
        
        novo->dado = dado;
        novo->next = NULL;

        if(inicio == NULL){
            inicio = novo;
            atual = inicio;
        }
        else{
            atual->next = novo;
            atual= atual->next;
        }
        i++;
    }
    return inicio;
}

node *retiradaFila(int qtdRetirados, node *inicio, node *atual){
    int retirados;
    // retirados = (int *)malloc(sizeof(int));
    node *anterior = NULL;

    // for(int i = 0; i < qtdRetirados; i++){
    //     scanf("%d", &retirados[i]);
    // }
    for(int i = 0; i < qtdRetirados; i++){
        scanf("%d", &retirados);
        atual = inicio;
        anterior = NULL;
        while(atual != NULL){
            if(atual->dado == retirados){
                if(anterior == NULL){
                    inicio = atual->next;
                }
                else{
                    anterior->next = atual->next;
                }
                break;
            }
            anterior = atual;
            atual = atual->next;
            
        }
    }
    return inicio;
}

void imprimeFila(node *inicio, node *atual){
    atual = inicio;
    while(atual != NULL){
        int valor = atual->dado;
        if(atual->next == NULL){
            printf("%d\n",valor);
        }
        else{
            printf("%d ",valor);
        }
        atual = atual->next;
    }
}

int main(void) {
    int qtElem;
    scanf("%d", &qtElem);
    
    node *ini = NULL;
    node *auxiliar = NULL;

    ini = preencheFila(qtElem, ini, auxiliar);
    
    auxiliar = ini;

    int qtRet;   
    scanf("%d", &qtRet);


    ini = retiradaFila(qtRet, ini, auxiliar);
    auxiliar = ini;
    imprimeFila(ini, auxiliar);
    return 0;
}