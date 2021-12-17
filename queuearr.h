#include<stdio.h>
typedef element eltype;
typedef struct{
  eltype el[MAX];
  //store the elements
  int front, rear;
} queue;
void makeQ(queue *q){
  q->front=-1;
  q->rear=-1;
}
int emptyQ(queue q){
  return q.front==-1;
}
int fullQ(queue q){
  return (q.rear-q.front+1) % MAX==0;
}
void enQ(eltype x, queue *q){
  if (!fullQ(*q)){
    if(emptyQ(*q)){
      q->front=0;
    }
    q->rear=(q->rear+1) % MAX;
    q->el[q->rear]=x;
  } else printf("Queue is full!");
}
eltype deQ(queue *q){
  eltype e;
  if(!emptyQ(*q)){
    e=q->el[q->front];
    //if queue contain only one element
    if(q->front==q->rear) makenullQ(q);
    else q->front=(q->front+1) % MAX;
    return e;
  }
  else printf("Queue is empty!");
}

