#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1024

typedef struct{

    char* cognome;
    char* nome;
    int nascita;

}Anagrafe;

int contarighe(){

    FILE* fp;
    int cont = 0;
    char stringa[DIM];
    char* riga = stringa;

    fp = fopen("dati.csv","r");
    if(fp == NULL){
        printf("\n FILE INESISTENTE");
    }else{
        while(fgets(riga, DIM, fp)){
            cont ++;
        }
    }
    fclose(fp);
    return cont;
}
void caricaDati(Anagrafe* a, int num){

    FILE* fp;
    int cont = 1;
    char stringa[DIM];
    char* riga = stringa;
    Anagrafe* posizione = a;

    fp = fopen("dati.csv", "r");
    if(fp == NULL){
        printf("\n FILE INESISTENTE");
    }else{
        while(fgets(riga, DIM, fp)){

            a->cognome = strdup(strtok(riga,","));
            a->nome = strdup(strtok(NULL,","));
            a->nascita = atoi(strtok(NULL,","));
            printf("\nnella %d riga: %s %s %d\n", cont, a->cognome, a->nome,a->nascita);
            a++;
            cont++;
        }
        a = posizione;
    }
    fclose(fp);
}
void bubbleSort(Anagrafe* a, int num){

    Anagrafe temp;
    Anagrafe* posizione = a;
    for(int k = num -1; k > 0; k--){
        for(int j = 0; j < k; j++){
                if(a->nascita > (a+1)->nascita){
                    temp = *a;
                    *a = *(a+1);
                    *(a+1) = temp;
                    }
                    a++;
            }
            a = posizione;
    }
}
void stampaDati(Anagrafe* a, int num){
    Anagrafe* posizione = a;
    int cont = 1 ;
    printf("\nStampiamo dal piu vecchio al piu giovane:\n");
    for( a = posizione; a < posizione + num; a++){
        printf("\n %d posto: %s %s %d", cont, a->cognome, a->nome, a->nascita);
        cont++;
    }
    a = posizione;
}
int main(){

    Anagrafe* p;
    int cont = 0;

    cont = contaRighe();
    if(cont > 0){
        p = (Anagrafe*)malloc(cont * sizeof(Anagrafe));
        caricaDati(p, cont);
        bubbleSort(p, cont);
        stampaDati(p, cont);
        free(p);
    }
    return 0;


}
