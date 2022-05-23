#include <stdio.h>
#include <string.h>

int main(){
	int n,i;
	char linha[14];
	char aux[6];
	scanf("%d",&n);
	for(i = 0; i<n ;i++){
		//printf("%d\n",i);
		scanf("%s", linha);
		printf("%c %c %c %c %c %c %c\n",linha[2],linha[3],linha[5],linha[6],linha[7],linha[11],linha[12]);
		strcat(aux, linha[2]);
		printf("%c", aux);



	}

	return 0;
}
