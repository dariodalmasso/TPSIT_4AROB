#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;
    int i = 10;

    p = &i;

    *p = 20;

    printf("\n%p\n", i);
    return 0;


}
