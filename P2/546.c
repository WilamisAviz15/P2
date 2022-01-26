#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct arvore 
{
	int valor;
	struct arvore *esq;
	struct arvore *dir;
};

struct arvore* criar_abb(int valor)
{
	struct arvore* new_abb = (struct arvore*) malloc(sizeof(struct arvore*));
	new_abb->valor = valor;
	new_abb->esq = NULL;
	new_abb->dir = NULL;
}

int eh_vazio(struct arvore* abb)
{
	if(abb == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct arvore* new_tree(int *posicao, char *arvore)
{
	struct arvore* aux = NULL;
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

	    aux = criar_abb(valor_arvore); 
	    aux->esq = new_tree(posicao, arvore);  
	    aux->dir = new_tree(posicao, arvore);
    }
    (*posicao) = (*posicao) +1;
    return aux;
}

int main() 
{
	char arvore[255];
	int tam, posicao = 0;
	scanf("%[^\n]", arvore);
	//printf("%s\n", arvore);
	tam = strlen(arvore);

	struct arvore* abb = new_tree(&posicao, arvore);
	int aux = 0;
	//search(abb, aux);
	return 0;
}