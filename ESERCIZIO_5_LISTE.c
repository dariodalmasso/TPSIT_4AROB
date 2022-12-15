#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int valore;
    struct node *next;
} Node;

void insertHead(struct node* head, int new_value ){
    struct node* new_testa = (struct node*)malloc(sizeof(struct node));
    new_testa->valore = new_value; //carico il nuovo valore nel node new
    new_testa->next = (*head); //il next punterà alla testa attuale;



}