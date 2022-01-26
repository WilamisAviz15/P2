#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Nos{
	char valor;
	struct Nos *proximo;
};

void inserir_comeco_lista(struct Nos** LISTA, char num)
{
	struct Nos *novo = (struct Nos*) malloc(sizeof(struct Nos));
	novo->valor = num;
	novo->proximo = (*LISTA);
	(*LISTA) = novo;
}

void insert_end_list(struct Nos** LISTA, char num)
{
	struct Nos* new = (struct Nos*) malloc(sizeof(struct Nos));
	struct Nos* current;
	new->valor = num;
	new->proximo = NULL;

	if((*LISTA) == NULL)
	{
		(*LISTA) = new;
	}
	else
	{
		current = (*LISTA);
		while(current->proximo != NULL)
		{
			current = current->proximo;
		}
		current->proximo = new;
	}
}

void print_lista(struct Nos *temp)
{
	int flag = 5;
	while(temp != NULL)
	{
		if(flag == 5 && temp->valor == '0')
		{
			while(temp->valor == '0')
			{
				temp = temp->proximo;
				//print_lista_recursao(temp);
			}
		}
		else if(flag == 6 && temp->valor == '0')
		{
			printf("%c ", temp->valor);
			temp = temp->proximo;
		}
		else if(temp->valor != '0')
		{
			flag = 6;
			printf("%c ", temp->valor);
			temp = temp->proximo;
			//print_lista_recursao(temp);
		}
	}
}

/*void print_lista(struct Nos *LISTA)
{
	struct Nos *temp = LISTA;
	int i = 0;
	while(temp != NULL)
	{
		//printf("%c / node: %d\n", temp->valor, i++);
		printf("%c ", temp->valor);
		temp = temp->proximo;
	}
}*/

int cont_n(struct Nos *LISTA)
{
	struct Nos *temp = LISTA;
	int c = 0;
	while(temp != NULL)
	{
		c++;
		temp = temp->proximo;
	}
	return c;
}

void soma_listas(struct Nos* lista1, struct Nos* lista2)
{
    struct Nos *temp1 = lista1;
    struct Nos *temp2 = lista2;
    struct Nos *L_soma = NULL;
    int vaium = 0;
    if(temp1 == NULL && temp2 == NULL)
    {
        printf("Lista vazia!");
    }
    while(temp1 != NULL && temp2 != NULL)
    {
        char a = temp1->valor;
        int aux1 = a - '0';
        char b = temp2->valor;
        int aux2 = b - '0';
        int soma;
        if(vaium != 0)
        {
            soma = aux1+ aux2 + vaium;
            vaium--;
        }
        else
        {
            soma = aux1+ aux2;
        }
        
        //printf("%d", soma);
        if(soma > 9)
        {
            int v1 = 0;
            v1 = soma %10;
            vaium++;
            char num2 = v1 + '0';
            inserir_comeco_lista(&L_soma, num2);
        }
        else
        {
            char num = soma + '0';
            //printf("%c", num);
            inserir_comeco_lista(&L_soma, num);
        }
        temp1 = temp1->proximo;
        temp2 = temp2->proximo;
    }
    if(vaium != 0)
    {
        char num = vaium + '0';
        inserir_comeco_lista(&L_soma, num);
    }
    print_lista(L_soma);
}


void loop_sem_recursao(struct Nos* lista1, struct Nos* lista2, int t)
{
	int tam = t;
	struct Nos *temp1 = lista1;
	struct Nos *temp2 = lista2;
	struct Nos *L_soma = NULL;
	int vaium = 0;

	if(temp1 == NULL && temp2 == NULL)
    {
        printf("Lista vazia!");
    }

	while(tam != 0)
	{
		while(t != 1)
		{
			temp1 = temp1->proximo;
			temp2 = temp2->proximo;
			t--;
		}
		if(t == 1)
		{
			char a = temp1->valor;
	        int aux1 = a - '0';
	        //printf("%d\n", aux1);
	        char b = temp2->valor;
	        int aux2 = b - '0';
	        int soma;
	        if(vaium != 0)
	        {
	            soma = aux1+ aux2 + vaium;
	            vaium--;
	        }
	        else
	        {
	            soma = aux1+ aux2;
	        }
	        
	        //printf("%d", soma);
	        if(soma > 9)
	        {
	            int v1 = 0;
	            v1 = soma %10;
	            vaium++;
	            char num2 = v1 + '0';
	            inserir_comeco_lista(&L_soma, num2);
	        }
	        else
	        {
	            char num = soma + '0';
	            //printf("%c", num);
	            inserir_comeco_lista(&L_soma, num);
	        }
	       	temp1 = lista1;
			temp2 = lista2;
			t = tam-1;
			tam = tam -1;
		}
	}
	if(vaium != 0)
	{
		char num = vaium + '0';
	    inserir_comeco_lista(&L_soma, num);
	}
	print_lista(L_soma);
}

void iguala_lista(struct Nos* lista1, struct Nos* lista2)
{
	int tam_l1 = cont_n(lista1);
	int tam_l2 = cont_n(lista2);
	int tam = 0;
	//printf("%d\n", tam_l1);
	//printf("%d\n", tam_l2);

	if(tam_l1 > tam_l2)
	{
		int i;
		char zero = '0';
		int dif_tams = tam_l1 - tam_l2;
		//printf("%d", dif_tams);
		for(i = 0; i < dif_tams; i++)
		{
			inserir_comeco_lista(&lista2, zero);
		}
		tam = tam_l1;
	}
	else if(tam_l2 > tam_l1)
	{
		int i;
		char zero = '0';
		int dif_tams = tam_l2 - tam_l1;
		for(i = 0; i < dif_tams; i++)
		{
			inserir_comeco_lista(&lista1, zero);
		}
		tam = tam_l2;
	}
	else if(tam_l2 == tam_l1)
	{
	    tam = tam_l1;
	}
	//print_lista(lista1);
	//print_lista(lista2);
	//soma_listas(lista1, lista2);
	//printf("%d", tam);
	loop_sem_recursao(lista1, lista2, tam);
}

int main() {
	struct Nos* lista1 = NULL;
	struct Nos* lista2 = NULL;
	char n;
	int aux = 0;
	while(scanf("%c", &n) != EOF)
	{
		if(n == '+')
		{
			aux++;
			//printf("? MAIS\n");
		}
		else if(n == '=')
		{
			//printf("? igual\n");
		}
		else if(n == ' ')
		{
		    continue;
			//printf("? espa?o\n");
		}
		else if(n == '\n')
		{
		    continue;
			//printf("? enter\n");
		}
		else
		{
			if(aux)
			{
				//printf("? numero\n");
		    	//insert_end_list(&lista2, n);
		    	insert_end_list(&lista2, n);
			}
			else
			{
				//printf("? numero\n");
		    	//insert_end_list(&lista1, n);
		    	insert_end_list(&lista1, n);
			}
		}
	}
	iguala_lista(lista1,lista2);
	//print_lista(lista1);
	//print_lista(lista2);
	return 0;
}