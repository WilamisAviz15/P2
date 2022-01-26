#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_digitos(int i, int aux, int vt[])
{
    if(aux > 0)
    {
        //printf("%d\n", vt[aux]);
        //printf("Digito %d -> %d\n", i-aux+1, vt[aux]);
        if(vt[aux] % 2 == 0)
        {
            int sum = vt[aux] - 4;
            vt[aux] = sum;
            printf("%d", vt[aux]);
            return;
        }
        else
        {
            int sum = vt[aux] - 3;
            vt[aux] = sum;
            printf("%d", vt[aux]);
            return;
        }
        aux--;
        //return print_digitos(i, aux, vt);
    }
    else
    {
        return;
    }
}

void vetor_digitos(int numero, int vetor[], int countD, int i)
{
    if(numero > 9)
    {
        countD++;
        vetor[i] = numero % 10;
        numero /= 10;
        i++;
        return vetor_digitos(numero, vetor, countD, i);
    }
    else
    {
        vetor[i] = numero;
        int aux = i;
        print_digitos(i, aux, vetor);
        return;
    }
}


int main() {
    int n, vetor_dig[10];
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0){
            break;
        }
        vetor_digitos(n, vetor_dig, 0, 1);
    }
	return 0;
}