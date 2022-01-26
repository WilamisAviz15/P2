#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stack STACK;

typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

STACK* Create_stack();

NODE* create_node(int element);

int IS_EMPTY(STACK* stack);

int POP(STACK* stack);

void PUSH(STACK* stack, int element);

void result(STACK* stack, char operation);

void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
STACK* Create_stack()
{
    STACK* stack =(STACK*) malloc(sizeof(STACK));
    stack->head=NULL;
    return stack;
}

NODE* create_node(int element)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->element = element;
    newNode->next = NULL;
    return newNode;
}

void PUSH(STACK* stack, int element)
{
    NODE* node = create_node(element);
    node->next = stack->head;
    stack->head = node;
}

int IS_EMPTY(STACK* stack)
{
    return stack == NULL;
}

int POP(STACK* stack)
{
    if(IS_EMPTY(stack))
    {
        printf("Pilha vazia!\n");
        return 0;
    }
    else
    {
        NODE *peek = stack->head;
        stack->head = peek->next;
        peek->next = NULL;
        return peek->element;
    }
}

int verifica_digito(char digito)
{
    if(digito == '+' || digito == '-' 
        || digito == '*' || digito == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void result(STACK* stack, char operation)
{
    int temp, t1, t2;
    switch(operation) {
        case '+': 
            t1 = POP(stack);
            t2 = POP(stack);
            PUSH(stack, t1+t2);
        break;
        case '*': 
            t1 = POP(stack);
            t2 = POP(stack);
            PUSH(stack, t1 * t2);
        break;
        case '-': 
            temp = POP(stack);
            t2 = POP(stack);
            PUSH(stack, t2 - temp);
        break;
        case '/': 
            temp = POP(stack); 
            t2 = POP(stack);
            PUSH(stack, t2 / temp);
        break;
    }
}

void Calculadora(STACK* calculadora, int size)
{
    int i;
    char n[3];
    int conv;
    
    for(i = 0; i < size; i++)
    {
        int eh_op = 0;
        scanf("%s", n);
        //printf("%s\n", n);
        int len = strlen(n);
        //printf("%d\n", len);
        if(len == 1)
        {
            eh_op = verifica_digito(n[0]);
        }
        //printf("EH OP? %d\n", eh_op);

        if(eh_op == 1)
        {
            result(calculadora, n[0]);
            //printf("? op %c\n", n[0]); 
            eh_op = 0;
        }
        else
        {
            conv = atoi(n);
            PUSH(calculadora, conv);
        }
        //scanf("%c", &n);
        //printf("%s\n", n);
    }
}