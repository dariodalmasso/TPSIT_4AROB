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

    lista = (Node*) malloc (DIM * sizeof(Node));
    printf("inserire un nome: ");
    fflush(stdin);
    scanf("%s", lista[0].name);


    printf("%s", lista[0].name);
    return 0;
}
