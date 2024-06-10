#include<stdio.h>
#include<stdlib.h>

#define QUEUESIZE 100

struct queue {
	int front, rear;
	int items[QUEUESIZE];
};

//verifica se fila está vazia
int empty (struct queue *pq);
//remove e retorna o primeiro item da fila
int removeq (struct queue *pq);
//insere item x no fim da fila
void insert (struct queue *pq, int x);

 

int main (){
	struct queue q;
	int ret;
	
	//inicializando a fila
	q.rear=-1;
	q.front=0;

	
	insert(&q,10);
	ret=removeq(&q);
	printf("Removi o item %d", ret);
	

	return 0;
}


int empty (struct queue *pq){
	if (pq->rear < pq->front)
		return 1;
	return 0;	
}

int removeq (struct queue *pq){
	int x;

	if (empty(pq)){
		printf("ERRO- FILA VAZIA");
		exit(1);
	}

	x=pq->items[pq->front];
	pq->front++;

	return x;
}

void insert (struct queue *pq, int x){
	if (pq->rear==QUEUESIZE-1){
		printf("ERRO- FILA CHEIA");
		exit(1);		
	}
	pq->rear++;
	pq->items[pq->rear]=x;
}

