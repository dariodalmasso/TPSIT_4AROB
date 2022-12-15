/*crea  una  lista e la  stampa*/


#include  <stdio.h>
#include  <stdlib.h>

typedef struct node {
    int valore;
    struct node *next;
} Node;

void stampa(Node *lista){
    Node *l;
    l = lista;  //l è una variabile di appoggio
    printf("numeri  inseriti: \n");
    while (l != NULL) {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;  //al puntatore viene assegnato valore di l->next, se è null finisce il ciclo
    }
    printf("\n");
}
int lunghezza(Node *lista){
    int cont = 0;
    Node *l;
    l = lista;
    while (l != NULL){
        l = l->next;
        cont++;
    }

    return cont;
}

void stampaRicorsiva(Node *l){
    printf("%d - %p \n", l->valore, l->next);
    if(l->next != NULL){
        stampaRicorsiva(l->next);
    }
}

int lunghezzaRicorsiva(Node *l){
    if(l != NULL){
        return lunghezzaRicorsiva(l->next) + 1;
    } else{
        return 0;
    }
}

void insertHead(Node **head, int newValore){
    Node *newTesta = (Node *) malloc(sizeof(Node));

    newTesta->valore = newValore;  //carico nuovo valore new node nuovo
    newTesta->next = (*head);      //il next punta alla testa attuale
    (*head) = newTesta;            //assegno la nuova testa
}
void inserisciTesta(struct node** head, struct node* element, int new_value){
     struct node* cor = *head;
     struct node* prec = NULL;
    while(cor != NULL){
        if(element->valore <= cor->valore)
            break;
        prec = cor;
        cor = cor->next;

        if(prec == NULL){
            *head = element;
        }else{
            prec->next = cor;
        }
        element->next = cor;
            // cor = corrente   prec = precedente
    }
}
void dealloca1(Node *list){
    Node *temp;
    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }

}
int main() {
    int n;
    int contN = 0;
    Node *lista;
    Node *l;
    lista = NULL;

    do {
        printf("Inserisci  un  naturale o  -1 per  terminare:  \n");
        scanf("%d", &n);

        if (n >= 0) {
            if (lista == NULL) /*  prima  iterazione  */
            {
                lista = (Node *) malloc(sizeof(Node));
                l = lista; //puntatore d'appogggio l che punta a lista
            } else /*  iterazioni  successive  */
            {
                l->next = (Node *) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    insertHead(lista, 4);
    stampa(lista);



    //conta elementi in lista
    contN = lunghezza(lista);
    printf("\nci sono %d elementi", contN);



    return 0;
}