#include <stdio.h>

void swap(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int main()
{
	int n1 = 3;
	int n2 = 4;

	printf("Antes da troca N1: %d | N2: %d\n", n1, n2);
	swap(&n1, &n2);
	printf("Depois da troca N1: %d | N2: %d\n", n1, n2);
	return 0;
}