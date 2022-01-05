#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DBG(x) printf("[ %s ]\n", x)

// TENTAR OUTRA HORA 2694_BEE
int main(){
    int n, i, num1 = 0, num2 = 0, num3 = 0,j =0;
    char string[14];
    scanf("%d", &n);
    while(n--){
        scanf("%s", &string);
        DBG(string);
        for(i = 0; i < 14; i++){
            if((int)string[i] < 60){
                DBG("teste");
            }
        }
        printf("%d", (num1 + num2 + num3));
        string[0] = '\0';
    }
    return 0;
}

