#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct arvoreBinaria 
{
	int item;
	struct arvoreBinaria *left;
	struct arvoreBinaria *right;
};

struct arvoreBinaria* create_binary_tree(int item, struct arvoreBinaria *left, struct arvoreBinaria *right)
{
	struct arvoreBinaria *new_binary_tree = (struct arvoreBinaria*) malloc(sizeof(struct arvoreBinaria));
	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;
	return new_binary_tree;
}

int is_empty(struct arvoreBinaria *bt)
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

void print(struct arvoreBinaria *bt)
{
	if (bt == NULL) 
	{
	    return;
	}
	else
	{
		printf(" ( ");
        printf("%d ", bt->item); 
		if (bt->left == NULL)
        {
            printf(" () ");
        } 
        else
        {
        	print(bt->left);
        }

		if (bt->right == NULL)
        {
            printf(" () ");
        } 
        else
        {
        	print(bt->right);
        }
        printf(") ");
	}
}

struct arvoreBinaria* add(struct arvoreBinaria *bt, int item)
{
	if (bt == NULL) {
		bt = create_binary_tree(item, NULL, NULL);
	} else if (bt->item > item) {
		bt->left = add(bt->left, item);
	} else {
		bt->right = add(bt->right, item);
	}
	return bt;
}

int main() 
{
	int n;
	struct arvoreBinaria *bt = NULL;
	printf("----\n");
	while(scanf("%d", &n) != EOF)
	{	
		printf("Adicionando %d\n  ", n);
		bt = add(bt, n);
		print(bt);
		printf("\n----\n");
	}
	return 0;
}