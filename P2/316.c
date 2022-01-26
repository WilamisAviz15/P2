#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
	int N, L, i, j, k, valor_letra, ttl = 0;
	char *array, a;
	array = (char *) malloc( 50 * sizeof(char*));

	scanf("%d",&N);

	for (k = 0; k < N; k++)
	{
		scanf("%d", &L);
		for (j = 0; j < L; j++)
		{
			scanf("%s", array);
			int tam_v = strlen(array);
			for (i = 0; i < tam_v; i++)
			{
				if(array[i] == 'A')
				{
					valor_letra = 0 + i + j;
				}
				else if(array[i] == 'B')
				{
					valor_letra = 1 + i + j;
				}
				else if(array[i] == 'C')
				{
					valor_letra = 2 + i + j;
				}
				else if(array[i] == 'D')
				{
					valor_letra = 3 + i + j;
				}
				else if(array[i] == 'E')
				{
					valor_letra = 4 + i + j;
				}
				else if(array[i] == 'F')
				{
					valor_letra = 5 + i + j;
				}
				else if(array[i] == 'G')
				{
					valor_letra = 6 + i + j;
				}
				else if(array[i] == 'H')
				{
					valor_letra = 7 + i + j;
				}
				else if(array[i] == 'I')
				{
					valor_letra = 8 + i + j;
				}
				else if(array[i] == 'J')
				{
					valor_letra = 9 + i + j;
				}
				else if(array[i] == 'K')
				{
					valor_letra = 10 + i + j;
				}
				else if(array[i] == 'L')
				{
					valor_letra = 11 + i + j;
				}
				else if(array[i] == 'M')
				{
					valor_letra = 12 + i + j;
				}
				else if(array[i] == 'N')
				{
					valor_letra = 13 + i + j;
				}
				else if(array[i] == 'O')
				{
					valor_letra = 14 + i + j;
				}
				else if(array[i] == 'P')
				{
					valor_letra = 15 + i + j;
				}
				else if(array[i] == 'Q')
				{
					valor_letra = 16 + i + j;
				}
				else if(array[i] == 'R')
				{
					valor_letra = 17 + i + j;
				}
				else if(array[i] == 'S')
				{
					valor_letra = 18 + i + j;
				}
				else if(array[i] == 'T')
				{
					valor_letra = 19 + i + j;
				}
				else if(array[i] == 'U')
				{
					valor_letra = 20 + i + j;
				}
				else if(array[i] == 'V')
				{
					valor_letra = 21 + i + j;
				}
				else if(array[i] == 'W')
				{
					valor_letra = 22 + i + j;
				}
				else if(array[i] == 'X')
				{
					valor_letra = 23 + i + j;
				}
				else if(array[i] == 'Y')
				{
					valor_letra = 24 + i + j;
				}
				else if(array[i] == 'Z')
				{
					valor_letra = 25 + i + j;
				}

				ttl = ttl + valor_letra;
				//printf("%c --> %d\n", array[i], i);
			}
		}
		printf("%d\n", ttl);
		ttl = 0;
	}
	
}