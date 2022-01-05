#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DBG(x) printf("[ %c ]\n", x)

int main(){
    int n, i, c = 0;
    int x = 0;
    char string[1001];
    scanf("%d", &n);
    while (n){
        gets(string);
        x = 0;
        for(i = 0; i < strlen(string); i++){
            if(string[i] == "C" && string[i+1] == "D"){
                x = 1;
                break;
            }
        }
        if(x != 1){
            c++;
        }
        string[0] = '\0';
    }
    printf("%d\n", c);
    return 0;
}