#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct binary_tree 
{
    int valor;
    struct binary_tree* esq;
    struct binary_tree* dir;
};

struct binary_tree* create_binary_tree(int valor, struct binary_tree *esq, struct binary_tree *dir) {
    struct binary_tree *bt = (struct binary_tree*) malloc(sizeof(struct binary_tree));
    bt->dir = NULL;
    bt->valor = valor;
    bt->esq = NULL;
    return bt;
}

struct binary_tree* search(struct binary_tree *bt, int *cont, int valor) {
    struct binary_tree *aux = bt;
    (*cont) = (*cont) + 1;
    if ((aux == NULL) || (aux->valor == valor)) {
        return aux;
    } else if (aux->valor > valor) {
        search(aux->esq, cont, valor);
    } else {
        search(aux->dir, cont, valor);
    }
}

struct binary_tree* new_tree(int *posicao, char *arvore)
{
	struct binary_tree* aux = NULL;
	int i = 0, valor_arvore;
	char string_arvore[255];

	while(arvore[*posicao] == '(')
	{
		(*posicao) = (*posicao) +1;
	}

	if(arvore[*posicao] == ')') { 
        (*posicao) = (*posicao) +1;
        return aux;
    }
    else
    {
    	while(arvore[*posicao] != '(') {    
            string_arvore[i++] = arvore[*posicao]; 
            (*posicao) = (*posicao) + 1;
        }
	    string_arvore[i] = '\0'; 
	    valor_arvore = atoi(string_arvore);

	    aux = create_binary_tree(valor_arvore, NULL, NULL); 
	    aux->esq = new_tree(posicao, arvore);  
	    aux->dir = new_tree(posicao, arvore);
    }
    (*posicao) = (*posicao) +1;
    return aux;
}

int main() 
{
	int i, cont = -1, valor, posicao = 0;
	char arvore[255];
	scanf("%[^\n]", arvore);
    scanf("%d", &valor);
    int tam = strlen(arvore);
    struct binary_tree* bt = new_tree(&posicao,arvore);

    if (search(bt, &cont, valor)) {
        printf("ESTA NA ARVORE\n");
        printf("%d", cont);
    } else {
        printf("NAO ESTA NA ARVORE\n");
        printf("%d", -1);
    }
	return 0;
}