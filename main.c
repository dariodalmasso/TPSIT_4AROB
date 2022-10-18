#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20
#define NUM2 1024

typedef struct anno{
    int anniN;
    int mese;
    int giorno;
}Anno;
typedef struct persona{
    char* nome;
    char* cognome;
    Anno anno;
}Persona;

int leggiDaFile(Persona gruppo[], int num){
    FILE* fp;
    char riga[NUM2];
    Persona* p;
    int cont = 0;
    p = (Persona*) malloc (DIM*sizeof(Persona));
    fp =fopen("..//FILE.csv", "r");
    if(fp == NULL){
        printf("FILE INESISTENTE!");
    }else{
        printf("FILE APERTO!");
        fgets(riga, 1024, fp);
        while(!feof(fp)) {
            fgets(riga, 1024, fp);
            (*(p)).nome = strtok(riga, ",");
            (*(p)).cognome = strtok(NULL, ",");
            (*(p)).anno.anniN = atoi(strtok(NULL, ","));
            (*(p)).anno.mese = atoi(strtok(NULL, ","));
            (*(p)).anno.giorno = atoi(strtok(NULL, ","));

            cont++;
            printf("\n%s %s %d %d %d", (*p).nome, (*p).cognome, (*p).anno.anniN, (*p).anno.mese,(*p).anno.giorno);




        }
        return cont;
        free(p);
        fclose(fp);
    }


}

int main() {

    Persona gruppo[DIM];
    int cont = 0;
     cont = leggiDaFile(gruppo, DIM);


    return 0;
}
