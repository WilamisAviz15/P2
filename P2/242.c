#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element {
	int key;
	int value;
	struct element *next;
};

struct hash_table {
	struct element *table[255];
};

struct hash_table* create_hash_table(int max)
{
	struct hash_table* new_hash_table = (struct hash_table*) malloc(sizeof(struct hash_table));
	int i;
	for (i = 0; i < max; i++) {
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

struct element* insert_list(struct element* lista, int key, int value)
{
	struct element* new = (struct element*) malloc(sizeof(struct element));
	new->key = key;
	new->value = value;
	new->next = NULL;

	return new;
}

void put(struct hash_table *ht, struct element *lista, int key, int value, int max)
{
	int h = key % max;
	//printf("H: %d\n", h);
	struct element* nodo = insert_list(lista, key, value);

	if(ht->table[h] == NULL)
	{
		ht->table[h] = nodo;
	}
	else
	{
	    struct element *t = ht->table[h];
		while(t != NULL && t->next != NULL)
		{
			t = t->next;
		}
		t->next = nodo;
	}
	//h = (h + 1) % max;
}

void print(struct hash_table *ht, int tam_hash)
{
	int i, indice =-1;
	struct hash_table *aux = ht;
	for(i = 0; i< tam_hash; i++)
	{
		if(aux->table[i] == NULL)
		{
			printf("%d -> \\\n", i);
		}
		else
		{
			while(aux->table[i] != NULL)
			{
				if(indice != i)
				{
					printf("%d -> %d", i, aux->table[i]->value);
					aux->table[i] = aux->table[i]->next;
					indice = i;
				}
				else
				{
					printf(" -> %d", aux->table[i]->value);
					aux->table[i] = aux->table[i]->next;
				}
			}
			if(aux->table[i] == NULL)
			{
				printf(" -> \\\n");
			}
		}
		
	}
}

int main()
{
	struct element *lista = NULL;
	int N_casos, qtd_end, qtd_chave, i, j, chaves;
	scanf("%d", &N_casos);
	for (int i = 0; i < N_casos; i++)
	{
		scanf("%d", &qtd_end);
		scanf("%d", &qtd_chave);
		struct hash_table *hash = create_hash_table(qtd_end);
		for (int j = 0; j < qtd_chave; j++)
		{
			scanf("%d", &chaves);
			//printf("%d\n", chaves);
			put(hash, lista,chaves, chaves, qtd_end);
		}
		//printf("%d\n", qtd_chave);
		print(hash, qtd_end);
		printf("\n");
			
	}
	return 0;
}