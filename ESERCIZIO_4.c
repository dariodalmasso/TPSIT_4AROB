#include <stdio.h>
#include <stdlib.h>


int main() {

    int dim = 10;
    int vet[dim];
    int *p = vet;

    for(int j = 0; j < dim; j++){
        *(vet +j) = j;
    }
    *(p + 5) = 67;

    while(p - vet < dim){
    printf(" %d ", *(p)++);
}

}
