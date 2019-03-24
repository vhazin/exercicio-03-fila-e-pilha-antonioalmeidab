#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *next;
} node;

int main(void) {
    int qtElem;
    scanf("%d", &qtElem);
    int i = 0;

    node *ini = NULL;
    node *auxiliar = NULL;
    

    while(i < qtElem){
        node *novo = malloc(sizeof(node));
        int dado;
        scanf("%d", &dado);
        
        novo->dado = dado;
        novo->next = NULL;

        if(ini == NULL){
            ini = novo;
            auxiliar = ini;
        }
        else{
            auxiliar->next = novo;
            auxiliar= auxiliar->next;
        }
        i++;
    }

    int qtRet;
    int *retirados;
    
    scanf("%d", &qtRet);
    retirados = (int *)malloc(qtRet * sizeof(int));

    for(i = 0; i < qtRet; i++){
        scanf("%d", &retirados[i]);
    }

    auxiliar = ini;
    node *anterior =NULL;
    
    while(auxiliar != NULL){
        for(i = 0; i < qtRet; i++){
            if(auxiliar->dado == retirados[i]){
                if(anterior == NULL){
                    ini = auxiliar->next;
                }
                else{
                    anterior->next = auxiliar->next;
                }
                break;
            }
            else if(i == qtRet - 1){
                anterior = auxiliar;
            }
        }
        auxiliar = auxiliar->next;
    }

    auxiliar = ini;
    while(auxiliar != NULL){
        int valor = auxiliar->dado;
        if(auxiliar->next == NULL){
            printf("%d\n",valor);
        }
        else{
            printf("%d ",valor);
        }
        auxiliar = auxiliar->next;
    }
    return 0;
}