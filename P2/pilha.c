#include<stdio.h>
#include<stdlib.h>


typedef struct elemento{        
	int dado;        
	struct elemento *prox;
}Elemento;

typedef struct pilha{        
	Elemento *pilha;        
	Elemento *topo;
}Pilha;

void Inicializa(){        
	Elemento *pilha;        
	Elemento *topo;        
	pilha=NULL;        
	topo=(Elemento *)malloc(sizeof(Elemento));        
	topo->prox=pilha;
}

void insere(char d){        
	Elemento *pilha;        
	Elemento *topo;        
	Elemento *Novo;        
	Novo=(Elemento *)malloc(sizeof(Elemento));        
	Novo->dado=d;        
	topo->prox=Novo;        
	Novo->prox=topo->prox;        
}

char retira (){        
	Elemento *pilha;        
	Elemento *topo;        
	Elemento *Novo;        
	if (topo->prox == NULL){                
		printf("A pilha está vazia");        
	}        
	else{                
		Novo=(Elemento *)malloc(sizeof(Elemento));                
		Novo=topo->prox;                
		topo=topo->prox;                
		return Novo->dado;        
	}
}

int menu(){
	printf("\t\n>>CALCULADORA NO MODO RPN<<\n");
	printf("\n\n Escolha uma opcao:");
	printf("\n 1- Inserir valores para calculo");
	printf("\n 2- Resultado");
}

void calculadora(){   
	Elemento *topo;   
	char v1, v2, op, resultado;   
	while(topo->prox!=NULL){        
		v1 = retira();        
		v2 = retira();        
		op = retira();        
		printf("\n%d %c %d = ", v1,op,v2);        
		switch (op) {        
			case '+': resultado = v1 + v2;        
			break;        
			case '-': resultado = v1 - v2;        
			break;        
			case '*': resultado = v1 * v2;        
			break;        
			case '/': resultado = v1 / v2;        
			break;        
			default : printf( "Operador Inexistente\n");        
			system("pause");        
		}        
		insere(resultado);   
	}
}

int main(){    
	Inicializa();    
	int opcao, resultado;    
	char v;    
	menu();    
	printf("\n\n-->> ");    
	scanf("%i", &opcao);    
	if (opcao==1){            
		printf("\n>>> ");            
		scanf("%c", &v);            
		insere(v);    
	}    
	if (opcao==2){            
		calculadora();            
		resultado = retira();            
		printf("O valor final é = %i", resultado);    
	}    if (opcao != 1 && opcao != 2){            
		printf("\nEscolha Invalida.\n\n");            
		menu();    
	}
}