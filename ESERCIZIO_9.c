#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 20


typedef struct {
    char carattere;
    struct node* next;
}Node;

void push(Node **head, Node *element){
    if(*head == NULL){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}
Node * pop(Node **head){
    Node *prova = *head;
    if(*head == NULL){
        return NULL;
    }else{
        *head = prova->next;
    }
    return prova;

}

void scorri(Node *pila, char frase[LUNG]) {

    int k = 0;
    Node *temp = (Node*)malloc(sizeof (Node));
    Node *temp2 = (Node*)malloc(sizeof (Node));
    temp->carattere = 'd';
    while(frase[k] !='/0'){
        if(frase[k] == '(' || frase[k] == '[' || frase[k] == '{'){
            push(pila,&temp);
            printf("%c", k);
        }else if(frase[k] == ')' || frase[k] == ']' || frase[k] == '}'){
            temp->carattere = pop(pila);
            printf("%c", k);
            if(temp != NULL){
                free(temp);
            }else{
                printf("esco");
            }

        }

    }

}
int main() {
    Node *pila;
    char frase[LUNG];
    printf("Inserire una frase: ");
    fflush(stdin);
    gets(frase);

    scorri(&pila, frase);

    if(pila == NULL){
        printf("tutte le parentesi sono chiuse");
    }else{
        printf("non tutte sono chiuse");
    }

    return 0;
}