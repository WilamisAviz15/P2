#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int contaDigitos = 0,i, valor, base, result, resto,vetor[20],cont=0;
    printf("\nDigite um numero inteiro: ");
    scanf("%d",&valor);
    //contando os digitos do nº digitado
    do{
        contaDigitos++;
        vetor[cont] = valor % 10;
        valor /= 10;
        cont++;
    }while( valor > 9 );
    vetor[cont]=valor;
    printf("\n");
    for(i=cont; i>=0; i--)
        printf("Digito %d -> %d\n",
        cont-i+1,vetor[i]);
    printf("\n\n\n");
    return 0;
}