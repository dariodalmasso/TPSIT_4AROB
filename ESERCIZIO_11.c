#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 720

/*
 *12.15 (Simulazione di un supermercato) Scrivete un programma che simuli una fila alla cassa di un
supermercato. La fila è una coda. I clienti arriveranno casualmente in intervalli interi compresi tra 1 e
4 minuti. Anche i clienti saranno serviti in modo casuale a intervalli interi compresi tra 1 e 4 minuti.
Ovviamente, i ritmi dovranno essere bilanciati. La coda crescerà all'infinito qualora il ritmo degli arrivi
sia superiore a quello del servizio. Nonostante i ritmi bilanciati, il caso potrebbe causare delle lunghe
code. Eseguite la simulazione del supermercato per una giornata lavorativa di 12 ore (720 minuti),
usando il seguente algoritmo:

1) Scegliete un intero casuale compreso tra 1 e 4, per determinare il minuto in cui arriverà il primo
cliente.
2) Nel momento in cui arriva il primo cliente:
Determinate il tempo di servizio del cliente (un intero casuale compreso tra 1 e 4);
Cominciate a servire il cliente;
Stabilite il tempo di arrivo del prossimo cliente (un intero casuale compreso tra 1 e 4 aggiunto al
tempo corrente).
3) Per ogni minuto del giorno:
Qualora arrivi il cliente successivo:
Mettete il cliente nella coda;
Stabilite il tempo di arrivo del prossimo cliente;
Nel caso in cui sia stato completato il servizio per l’ultimo cliente:
Comunicatelo
Togliete dalla coda il prossimo cliente da servire

Determinate il tempo di completamento del servizio per il cliente (ovverosia,
un intero casuale da 1 a 4 aggiunto al tempo corrente).

Eseguite ora la vostra simulazione e ponetevi le seguenti questioni:
a) Qualè stato il numero massimo di clienti in coda durante tutta la simulazione?

b) Qual è stata l’attesa più lunga tra quelle sperimentate dai clienti?

c) Che cosa succederebbe se l’intervallo di arrivo, compreso tra 1 e 4 minuti, fosse cambiato in uno
compreso tra 1 e 3 minuti?

 */

typedef struct cliente{

    int time;
    int numero;
    struct Cliente* next;
}Cliente;

int isEmpty(Cliente * list) {
    return list == NULL;
}

void enqueue(Cliente** head, Cliente** tail, Cliente* el) {
    if(isEmpty(*head))
        *head = el;
    else
        (*tail)->next = el;
    *tail = el;
}
Cliente* dequeue(Cliente** head, Cliente** tail) {
    Cliente* ret = *head;
    if(isEmpty(*head))
        return NULL;
    *head = ret->next;
    if(isEmpty(*head))
        *tail = NULL;
    return ret;
}
int casuale(){
    int casuale;

    casuale = (rand() % (4 - 1)) + 1;

    return casuale;
}


int main() {

    Cliente *coda1 = (Cliente*) malloc(sizeof (Cliente));
    Cliente *tail1;
    Cliente *temp;

     int tempoarrivo =  casuale();
     int temposervizio = casuale();
     int tempoprossimo;

    srand(time(NULL));
    for(int k = 0; k < MAX; k++){

        if(tempoarrivo == 0){
            temp = (Cliente*) malloc(sizeof (Cliente));
            enqueue(&coda1,&tail1,temp);
            tempoprossimo = casuale();
        }
        if(temposervizio == 0){
            dequeue(&coda1,&tail1);
            temposervizio = casuale();


        }
        tempoarrivo--;
        temposervizio--;





    }







}
