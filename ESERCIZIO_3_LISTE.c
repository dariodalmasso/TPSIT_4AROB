#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20
typedef struct nodo{
    char name[DIM];
     struct nodo* next;
}Node;

int main() {

    Node *lista;
    Node *temp;

    lista = (Node*) malloc (DIM * sizeof(Node));
    temp = (Node*) malloc (DIM * sizeof(Node));
    printf("inserire un nome: ");
    gets(lista->name);
    lista->next = NULL;
    fflush(stdin);
    printf("Nome 1:%s", lista->name);
    lista->next = NULL;

    printf("\ninserisci un nome:");
    gets(temp->name);
    printf("Nome 2:%s", temp->name);
    temp->next = NULL;
    lista->next = temp;
    printf("\n inserisci un nome: ");
    gets(temp->name);
    printf("Nome 3: %s", temp->name);
    temp->next = NULL;
    lista->next->next = temp;
    printf("\n\nNome1:%s \nNome2:%s \nNome3:%s",lista->name, lista->next->name, lista->next->next->name);
    free(temp);
    free(lista);
    return 0;
}
