#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element 
{
	int value;
	struct element *next;
};

struct hash_table 
{
	struct element **table;
	int tam;
};

struct hash_table* create_hash_table(int max)
{
	struct hash_table* new_hash_table = (struct hash_table*) malloc(sizeof(struct hash_table));
	new_hash_table->table = (struct element*) malloc(max * sizeof(struct element));
	int i;
	for (i = 0; i < max; i++) {
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

int search(struct element *head, int item, int *iteracao)
{
    struct element *temp = head;
	while (temp != NULL) 
	{
		(*iteracao)++;
		if (temp->value == item) 
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

int valorN(struct hash_table *ht, int max)
{
	int i, t = 0;
	struct hash_table* aux = ht;
	for (i = 0; i < max; i++)
	{
		struct element* a = aux->table[i];
		while(a != NULL)
		{	
			t++;
			a = a->next;
		}
	}
	return t;
}

int maior_node(struct hash_table *ht, int max)
{
	int i, cnt = 0, maior = 0;
	for (i = 0; i < max; i++)
	{
		struct element* temp = ht->table[i];
		while(temp != NULL)
		{
			cnt++;
			temp = temp->next;
		}
		if(cnt > maior)
		{
			maior = cnt;
		}
		cnt = 0;
	}
	return maior;
}

void DEL(struct hash_table *ht, struct element* lista, int value, int max, int cnt)
{
	int h = value % max;
	struct element *previous = NULL;
	int iteracao = 0;
	struct element *current = ht->table[h];
	int r = search(ht->table[h], value, &iteracao);
	if(r == 1)
	{
		while (current != NULL && current->value != value) 
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL) 
		{
			ht->table[h] = current->next;
		} 
		else 
		{
			previous->next = current->next;
		}
		free(current);
		printf("%d %d %d\n", cnt, 1, iteracao);
		ht->tam--;
	}
	else
	{
		printf("%d %d %d\n", cnt, 0, iteracao);
	}
}


void ADD(struct hash_table *ht, struct element* lista, int value, int max, int cnt)
{
    int h = value % max;
    int r;
    int iteracao = 0;
    int result_search = search(ht->table[h], value, &iteracao);
    if(result_search == 1)
    {
    	printf("%d %d %d\n", cnt, 0, iteracao);
    }
    else
    {
    	struct element* novo = (struct element*) malloc(sizeof(struct element));
		novo->value = value;
		novo->next = ht->table[h];
		ht->table[h] = novo;
		printf("%d %d %d\n", cnt, 1, iteracao);
		ht->tam++;
    }
}

struct hash_table* resharing(struct hash_table* ht, int max)
{
	int i;
	struct hash_table* aux = create_hash_table(max);

	for(i = 0; i < max; i++)
	{
		struct element* temp = ht->table[i];
		while(temp != NULL)
		{
			int value = temp->value;
			aux->tam++;
			int h = value % max;

			struct element* novo = (struct element*) malloc(sizeof(struct element));
			novo->value = value;
			novo->next = aux->table[h];
			aux->table[h] = novo;
			temp = temp->next;
		}
	}
	return aux;
}

int main() 
{
	int max = 7;
    struct hash_table* ht = create_hash_table(max);
    struct element *lista = NULL;
	char operacao[3];
	int valor, i =0;

	while(scanf("%s", operacao) != EOF)
	{
    
		if(strcmp (operacao, "ADD") == 0)
		{
		    scanf("%d", &valor);
		    ADD(ht, lista, valor, max, i);
		    i++;
		}
		else if(strcmp (operacao, "DEL") == 0)
		{
		    scanf("%d", &valor);
		    DEL(ht, lista, valor, max, i);
		    i++;
		}
		else if(strcmp (operacao, "HAS") == 0)
		{
		    scanf("%d", &valor);
		    int iteracao = 0;
		    int h = valor % max;
		    int r = search(ht->table[h], valor, &iteracao);
		    if(r == 1)
		    {
		    	printf("%d %d %d\n", i, 1, iteracao);
		    }
		    else
		    {
		    	printf("%d %d %d\n", i, 0, iteracao);
		    }
		    i++;
		}
		else if(strcmp (operacao, "PRT") == 0)
		{
		    //scanf("%d", &valor);
		    //int n = valorN(ht, max);
		    int maior = maior_node(ht, max);
		    printf("%d %d %d %d\n", i, max, ht->tam, maior);
		    i++;
		}

		double fc = (double)ht->tam / (double)max;
		if(fc >= 0.75)
		{
			max = (2 * max) -1;
			//printf("NEW MAX: %d\n", max);
			ht = resharing(ht, max);
		}
	}
	return 0;
}