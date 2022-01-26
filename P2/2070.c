#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void soma_array(int i, int vet[], int soma)
{
    if (i > 0)
    {
        soma = soma + vet[i];
        i--;
        return soma_array(i, vet, soma);
    }
    else
    {
        printf("%d\n", soma);
        return;
    }
}

void print_digitos(int i, int aux, int vt[])
{
    if(aux > 0)
    {
        int digito = i-aux+1;
        if(vt[aux] % 2 == 0)
        {
            int k = vt[aux];
            vt[aux] = (k * 2 * aux);
        }
        else
        {
            int k = vt[aux];
            vt[aux] = (k* 3 * aux);
        }
        //printf("%d\n", vt[aux]);
        //printf("Digito %d -> %d\n", i-aux+1, vt[aux]);
        aux--;
        return print_digitos(i, aux, vt);
    }
    else
    {
        soma_array(i, vt, 0);
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