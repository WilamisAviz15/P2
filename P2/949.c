#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct binary_tree 
{
	int inteiro;
	struct binary_tree *left;
	struct binary_tree *right;
};

struct binary_tree* create_binary_tree(struct binary_tree *left, struct binary_tree *right, int inteiro)
{
	struct binary_tree *new_binary_tree = (struct binary_tree*) malloc(sizeof(struct binary_tree));
	new_binary_tree->inteiro = inteiro;
	new_binary_tree->left = left;
	new_binary_tree->right = right;
	return new_binary_tree;
}

int is_empty(struct binary_tree* bt)
{
	if(bt == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int organizeRetorna(struct binary_tree* bt,int nivel, int maior[], int menor[])
{
	if (is_empty(bt))
    {
        return nivel;
    }
    else
    {	
     	if(bt->inteiro < menor[nivel])
     	{
     		menor[nivel] = bt->inteiro;
     	} 
     	if(bt->inteiro > maior[nivel])
     	{
     		maior[nivel] = bt->inteiro;
     	}
     
     	int r1 = organizeRetorna(bt->left, nivel+1, maior, menor);
     	int r2 = organizeRetorna(bt->right, nivel+1, maior, menor);

     	if(r1 > r2)
     	{
     		return r1;
     	}
     	else
     	{
     		return r2;
     	}
    }
}

void change(struct binary_tree *bt[], int j, int i, int n)
{
	if(i < n)
	{
		struct binary_tree *temp = bt[i];
		if(!is_empty(temp->right))
		{
			j = temp->right->inteiro;
			temp->right = bt[j];
		}

		if(!is_empty(temp->left))
		{
			j = temp->left->inteiro;
			temp->left = bt[j];
		}
		change(bt, j, i+1, n);
	}
}

void init_arr(int *arr)
{
	int i = 0;
	while(i < 100)
	{
		arr[i] = 0;
		i++;
	}
}

void init_arr_MENOR(int *arr)
{
	int i = 0;
	while(i < 100)
	{
		arr[i] = (1 << 20);
		i++;
	}
}

void print(int *maior, int *menor, int i, int nivel)
{
	if(i < nivel)
	{

		printf("Nivel %d: Maior = %d, Menor = %d\n", i+1, maior[i], menor[i]);
		print(maior, menor, i+1,nivel);
	}
}

int main() 
{
	int n, i, v, e,d, maior[100], menor[100];
	init_arr(maior);
	init_arr_MENOR(menor);
	struct binary_tree *bt = NULL;
	scanf("%d", &n);
	i = 0;
	struct binary_tree* nodes_arr[n];
	while (i < n)
	{
		scanf("%d", &v); 
		scanf("%d", &e);
		scanf("%d", &d);
		struct binary_tree *nodo, *aux;
		struct binary_tree *raiz = create_binary_tree(NULL, NULL, i);
		if(e != -1)
		{
			nodo = create_binary_tree(NULL, NULL, e);
		}
		else
		{
			nodo = NULL;
		}
		if(d != -1)
		{
			aux = create_binary_tree(NULL, NULL, d);
		}
		else
		{
			aux = NULL;
		}

		raiz->inteiro = v;
		raiz->left = nodo;
		raiz->right = aux;
		nodes_arr[i] = raiz;
		i++;
	}

	change(nodes_arr, 0, 0, n);

	struct binary_tree* raiz = nodes_arr[0];
	int nivel = organizeRetorna(raiz, 0, maior, menor);
	print(maior, menor, 0,nivel);
	return 0;
}