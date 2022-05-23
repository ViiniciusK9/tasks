#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int vet[3];
    int aux[3];
    int n, i, j;
    for(i = 0; i < 3; i++){
        scanf("%d", &vet[i]);
        aux[i] = vet[i];
    }
    for(j = 0; j < 3; j++){
        for(i = 0; i < 2; i++){
            if(vet[i] > vet[i+1]){
                n = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = n;
            }
        }
    }
    for(i = 0; i < 3; i++){
        printf("%d\n", vet[i]);
    }
    printf('\n');
    for(i = 0; i < 3; i++){
        printf("%d\n", aux[i]);
    }
    return 0;
}