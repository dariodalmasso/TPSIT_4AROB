#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//valore attribuito gestione lunghezza riga con STRTOK
#define LUNG 1024

//Creo struttura
typedef struct{
    char* cognome;
    char* nome;
    int nascita;
}Anagrafe;



/*****
Function: contaRighe
- gestisce l'apertura con controllo e la chiusura del file
- scorre il file con la funzione fgets posta come condizione nel while
- conta le righe del file
@return: conteggio numero di righe nel file
******/
int contaRighe(){
    FILE* fp;
    int righe = 0;
    char c[LUNG];
    char* riga = c;

    fp = fopen("date.csv", "r");

    //test sulla corretta apertura del file
    if(fp != NULL){
        //scorro il file con FGETS
        while(fgets(riga, LUNG, fp))
        {
            righe++;
        }
    }else
        printf("Il file non esiste\n");

    fclose(fp);

    return righe;
}



/*****
Function: caricaDati
- gestisce l'apertura con controllo e la chiusura del file
- scorre il file con la funzione fgets posta come condizione del while
- assegna i valori di ogni singola riga all'interno della struct
@param: Anagrafe* a - puntatore alla struttura allocata tramite malloc
@param: int dim     - numero di righe nel file

*****/
void caricaDati (Anagrafe* a, int dim){
    FILE* fp;
    char c[LUNG];
    char* riga = c;
    Anagrafe* posizione = a;
    int count = 1;


    fp = fopen("date.csv", "r");

    if(fp != NULL){
        printf("Sul file sono riportate le righe:\n");
        while(fgets(riga, LUNG, fp)){

            a->cognome = strdup(strtok(riga, ",")); //utilizzo funzione STRDUP per la gestione della stringa
            a->nome = strdup(strtok(NULL, ","));    //utilizzo funzione STRDUP per la gestione della stringa
            a->nascita = atoi(strtok(NULL, ","));   //utilizzo funzione ATOI per conversione ad intero
            printf("%d riga: %s %s %d\n",count, a->cognome, a->nome, a->nascita);
            a++;
            count++;
        }
        a = posizione;
    }else
        printf("Il file non esiste\n");

    fclose(fp);
}


/*****
Function: bubblesort
- ordina la struttura in ordine crescente
@param: Anagrafe* a - puntatore alla struttura allocata tramite malloc
@param: int dim     - numero di righe nel file

*****/
void bubblesort(Anagrafe* a, int dim){
    Anagrafe temp;
    Anagrafe* posizione = a;
    for(int sup = dim - 1; sup > 0; sup--){
        for(int k = 0; k < sup; k++){
            if(a->nascita > (a + 1)->nascita){
                temp = *a;
                *a = *(a + 1);
                *(a + 1) = temp;
            }
            a++;
        }
        a = posizione;
    }

}


/*****
Function: print
- stampa la struttura
@param: Anagrafe* a - puntatore alla struttura allocata tramite malloc
@param: int dim     - numero di righe nel file

*****/
void print(Anagrafe *p, int dim){
    Anagrafe* posizione = p;
    int count=1;
    printf("\nStampiamo dal piu vecchio al piu giovane:\n");
    for(p = posizione; p < posizione + dim; p++){
        printf("%d posto: %s %s %d\n",count, p->cognome, p->nome, p->nascita);
        count++;
    }
    p = posizione;
}




int main(){
    Anagrafe* p;
    int dim;

    dim = contaRighe();

    if(dim != 0){
        p = (Anagrafe*)malloc(dim * sizeof(Anagrafe)); //allocazione dinamica tramite malloc
        caricaDati(p, dim);
        bubblesort(p, dim);
        print(p, dim);
        free(p);  //libero la memoria
    }

    //system("pause");
    return 0;
}
