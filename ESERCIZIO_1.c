#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 50
#define NUM2 1024
#define NUM3 16598

/*
ESERCIZIO : 1;
TITOLO:Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui pu� essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

typedef struct videogioco {
    int rank;
    char* nome;
    char* piattaforma;
    int anno;
    char* genere;
    char* editore;
    float prezzoNA;
    float prezzoEU;
    float prezzoJP;
    float prezzoO;
    float prezzoG;
} Videogioco;

int main() {

    FILE *fp;
    Videogioco gioco[NUM3];
    char riga[NUM2];
    Videogioco* p = gioco;
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL) {
        printf("\nFILE INESISTENTE!");
        return 0;
    } else {
        printf("\nFILE APERTO!");
        int k = 0;
        fgets(riga, 1024, fp);
        while(fgets(riga, 1024, fp)!= EOF && k < NUM3) {
             //printf("\n%s\n", riga);
            (*(p)).rank = atoi(strtok(riga, ","));
            (*(p)).nome = strtok(NULL, ",");
            (*(p)).piattaforma = strtok(NULL, ",");
            (*(p)).anno =atoi(strtok(NULL, ","));
            (*(p)).genere = strtok(NULL, ",");
            (*(p)).editore = strtok(NULL, ",");
            (*(p)).prezzoNA = atof(strtok(NULL, ","));
            (*(p)).prezzoEU = atof(strtok(NULL, ","));
            (*(p)).prezzoJP = atof(strtok(NULL, ","));
            (*(p)).prezzoO = atof(strtok(NULL, ","));
            (*(p)).prezzoG = atof(strtok(NULL, ","));


            printf("\n%d %s %s %d  %s %s %.2f %.2f %.2f %.2f %.2f", (*p).rank, (*p).nome, (*p).piattaforma, (*p).anno,(*p).genere, (*p).editore, (*p).prezzoNA, (*p).prezzoEU, (*p).prezzoJP, (*p).prezzoO, (*p).prezzoG);
            k++;

        }

    }


    fclose(fp);


}
