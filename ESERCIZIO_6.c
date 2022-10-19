#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main() {

    int *p;
    int temp = 0;


    p =(int *)malloc(sizeof(int) * DIM);

    for (int k = 0; k < DIM; k++) {
        printf("inserire il %d valore :", k+1);
        scanf("%d",p + k);
    }
    printf("\n");



    for (int k = 1; k < DIM; k++) {
        for(int j = 0; j < k; j++) {
            if (*(p + k) < *(p + j)) {
                temp = *(p + k);
                *(p + k) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    for (int i = 0; i < DIM; i++) {
        printf("%d ", *(p + i));
    }
    free(p);
    printf("\n");
    return 0;
}
