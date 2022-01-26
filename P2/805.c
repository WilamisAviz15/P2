#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct adj_list 
{
	int value;
	struct adj_list *next;
};

struct graph 
{
	struct adj_list *vertices[255];
	int visited[255];
};

struct guarda_dis_pred
{
	int distancia;
	int predecessor;
};

struct Queue
{
	int array[1000];
	int head;
	int tail;
	int size;
};

struct Queue* create_queue()
{
	int i;
	struct Queue *new_queue = (struct Queue*) malloc(sizeof(struct Queue));
	new_queue->size = 0;
	new_queue->head = 0;
	new_queue->tail = 1000-1;
	return new_queue;
}

void enqueue(struct Queue *queue, int item)
{
	queue->tail = (queue->tail+1) % 1000;
	queue->array[queue->tail] = item;
	queue->size++;
}

int dequeue(struct Queue *queue)
{
	int dequeued = queue->array[queue->head];
	queue->head = (queue->head + 1) % 1000;
	queue->size--;
	return dequeued;
}

struct graph* create_graph(int max)
{
	struct graph *graph = (struct graph*) malloc(sizeof(struct graph));
	int i;
	for (i = 0; i < max; i++) {
		graph->vertices[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

struct adj_list* create_adj_list(int item)
{
	struct adj_list *new_adj_list = (struct adj_list*) malloc(sizeof(struct adj_list));
	new_adj_list->value = item;
	new_adj_list->next = NULL;
	return new_adj_list;
}

struct guarda_dis_pred *criar_array_dist(int v)
{
	struct guarda_dis_pred* novo = (struct guarda_dis_pred*) malloc(v * sizeof(struct guarda_dis_pred));
	int i;
	for (i = 0; i < v; i++)
	{
		novo[i].distancia = -111;
		novo[i].predecessor = -111;
	}
	return novo;
}

struct guarda_dis_pred* add_array_dist(struct guarda_dis_pred* array_dist, int i, int distancia, int predecessor)
{
	array_dist[i].distancia = distancia;
	array_dist[i].predecessor = predecessor;
	return array_dist;
}

void add_edge(struct graph *graph, int vertex1, int vertex2)
{
	struct adj_list *vertex = create_adj_list(vertex2);
	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;
}

void limpar(struct graph *graph, struct guarda_dis_pred* novo, int V) {
    int i;
    for (i = 0; i < V; i++) {
        graph->visited[i] = 0;
        novo[i].distancia = -111;
		novo[i].predecessor = -111;
    }
}

void troca(struct adj_list *n1, struct adj_list *n2)
{
	int aux = n1->value;
	n1->value = n2->value;
	n2->value = aux;
}

void selectionSort(struct adj_list* LISTA) 
{ 
    struct adj_list* aux = LISTA; 
    
    while (aux) { 
        struct adj_list* old = aux; 
        struct adj_list* resltado = aux->next; 

        while (resltado) { 
            if (old->value > resltado->value) 
                old = resltado; 
  
            resltado = resltado->next; 
        } 
        
        troca(aux, old);
        aux = aux->next; 
    } 
} 

void printList(struct adj_list* node)
{
	struct adj_list* aux = node;
	while(node != NULL)
	{
		printf("%d -> \n", node->value);
		node = node->next;
	}
}

void printGraph(struct graph* graph, int max) {
    int i;
    for (i = 0; i < max; i++) {
        printf("ListNode %d:\n", i);
        if (graph->vertices[i] != NULL) {
            printList(graph->vertices[i]);
        }
    }
}

void print_dis_pred(int V, struct guarda_dis_pred* array_dist)
{
	int i = 0;
	while (i < V)
	{
		printf("%d", i);
	    printf(" | ");
	    if (array_dist[i].distancia == -111) {
	        printf("-");
	    } else {
	        printf("%d", array_dist[i].distancia);    
	    } 

	    printf(" | ");

	    if (array_dist[i].predecessor == -111) {
	        printf("-");
	    } else {
	        printf("%d", array_dist[i].predecessor);
	    }
	    printf("\n");
	    i++;
	}
}

void print_camin(struct guarda_dis_pred* array_dist, int aux, int last, int source)
{
	if(array_dist[aux].predecessor == -111)
	{
		printf("Caminho entre %d e %d: ", aux, last);
        printf("%d => ", aux);
        return;
	}

	print_camin(array_dist, array_dist[aux].predecessor, last, aux);
	if(aux != last)
	{
		printf("%d => ", aux);
    } else {
        printf("%d\n", aux);
    }
}

int is_empty(struct Queue* queue) {
    return queue->size == 0;
}

void bfs(struct graph* graph, int source, struct guarda_dis_pred* array_dist)
{
	printf("Iniciando busca em largura a partir de %d\n", source);
	struct graph* aux = graph;
	struct Queue* queue = create_queue();
	int dequeued;
	struct adj_list* adj_list = aux->vertices[source];
	aux->visited[source] = 1;
	array_dist[source].distancia = 0;
	array_dist[source].predecessor = -111;
	enqueue(queue, source);
	while (!is_empty(queue)) {
		dequeued = dequeue(queue);
		adj_list = aux->vertices[dequeued];
		while (adj_list != NULL) {
		if (!aux->visited[adj_list->value]) 
		{
			array_dist[adj_list->value].distancia = array_dist[dequeued].distancia +1;
			printf("Iniciando busca em largura a partir de %d\n", adj_list->value);
			aux->visited[adj_list->value] = 1;
			enqueue(queue, adj_list->value);
			array_dist = add_array_dist(array_dist, adj_list->value, array_dist[adj_list->value].distancia, dequeued);
		}
		adj_list = adj_list->next;
		}
	}
}

int main() 
{
	int V, A, T, i, O, D, j;
	scanf("%d", &V);
	scanf("%d", &A);
	scanf("%d", &T);
	struct guarda_dis_pred* array_dist = criar_array_dist(V);
	//printf("%d %d %d\n", V, A, T);
	struct graph* graph = create_graph(V);
	for (i = 0; i < A; i++)
	{
		scanf("%d %d", &O, &D);
		add_edge(graph, O, D);
		//printf("%d %d\n", O, D);

	}
	for (i = 0; i < A; i++)
	{
		if(graph->vertices[i] != NULL)
		{
			selectionSort(graph->vertices[i]);
		}
	}
	for (j = 0; j < T; j++)
	{
		scanf("%d %d", &O, &D);
		//printf("%d %d\n", O, D);
		printf("--------\n");
		printf("\n");
		printf("Caso de Teste #%d - BFS(%d)\n", j+1, O);
		printf("\n");
		limpar(graph,array_dist, V);
		bfs(graph, O, array_dist);
		printf("\n");
		print_dis_pred(V, array_dist);
		printf("\n");
        if (array_dist[D].predecessor == -111) {
            printf("Sem caminho entre %d e %d\n", O, D);
        } else {
            print_camin(array_dist, D,D, O);
        }
        printf("\n");
	}
	printf("--------\n");
	//printGraph(graph, V);
	return 0;
}