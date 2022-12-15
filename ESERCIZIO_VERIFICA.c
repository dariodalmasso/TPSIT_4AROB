#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 1024
#define MAX 2200
typedef struct{
    int data;
    char* cognome;
    int soldi;

}Gita;
typedef struct{
    char* cognome;
    int quota;
}Temp;

int contaRighe(Gita* quarta, int num){
    FILE* fp;
    int nRighe = 0;
    char s[LUNG];
    char* riga = s;

    fp = fopen("4AROB_GITA.csv", "r");
    if( fp == NULL){
        printf("\nfile inesistente");
    }else{
        while(fgets(riga, LUNG, fp)){
            nRighe++;
        }
    }
    fclose(fp);
    return nRighe;
}
void caricaDati(Gita* quarta, int num){
    FILE* fp;
    int cont = 1;
    char s[LUNG];
    char* riga = s;
    Gita* pos = quarta;

    fp = fopen("4AROB_GITA.csv", "r");
    if(fp == NULL){
        printf("\n FILE INISISTENTE");
    }else{
        while(fgets(riga, LUNG, fp)){

            quarta->data =  atoi(strtok(riga,";"));
            quarta->cognome = strdup(strtok(NULL,";"));
            quarta->soldi = atoi(strtok(NULL,";"));
            printf("\nnella %d riga: %d %s %d \n", cont, quarta->data, quarta->cognome,quarta->soldi);
            quarta++;
            pos++;
            cont++;
        }
        quarta = pos;
    }
    fclose(fp);
}
void stampaTotale(Gita* quarta, int num){
    Gita* pos = quarta;
    int somma = 0;
    int differenza = 0;
    for(int k = 0; k < num; k++){
        somma = somma + quarta->soldi;
    }
    if(somma == MAX){
        printf("\n si è raggiunto il totale richiesto");
    }else{
        differenza = MAX - somma;
        printf("\n mancano ancora %d euro ad arrivare al totale", differenza);
    }
    quarta = pos;
}

void ricercaStudente(Gita* quarta, int num, Temp* studenti){

    char s[LUNG];
    char * c = s;
    printf("\ninserire il vostro cognome:");
    scanf("%s", c);
    for(int k = 0; k < num; k++){
        if(0 == strcmp(quarta->cognome, c)){
            studenti->cognome = quarta->cognome;
            studenti->quota += quarta->soldi;
            printf("%s %d", studenti->cognome, studenti->quota);
            if(studenti->quota < 100){
                printf("\n lo studente  %s non ha pagato tutta la quota", studenti->cognome);
            }
        }
    }
}
void controlloStudenti(Gita* quarta, int num, Temp* studenti){
    for(int k = 0; k < num; k++){
        if(studenti->quota < 100){
            printf("%s %d", studenti->cognome, studenti->quota);
            printf("DA CONTROLLARE");
        }else{
            printf("%s %d", studenti->cognome, studenti->quota);
        }
    }
}
int main() {

    int cont = 0;
    Gita* quarta;
    Temp* alunni;
    cont =contaRighe(quarta, cont);
    if(cont > 0){
        // alloco in modo dinamico la struttura con la malloc
        quarta = (Gita*)malloc(cont * sizeof(Gita));
        caricaDati(quarta, cont);
        stampaTotale(quarta, cont);
        ricercaStudente(quarta, cont, alunni);
        controlloStudenti(quarta,cont, alunni);
        //libero lo spazio in memoria
        free(quarta);


    }


}

