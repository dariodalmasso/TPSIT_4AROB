#include <stdio.h>
#include <stdlib.h>


int main(){
    int dim = 10;

    int vettore[dim];


    int *p = vettore;

    *(p + 3) = 20;
    *(p + 1) = 10;
    *(p + 5) = 67;
    *(p + 7) = 33;
for(int k = 0; k < dim; k++){
    printf(" %d ", *(p + k));
}




}
