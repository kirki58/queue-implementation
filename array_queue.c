#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int rear;
    int front;
    int* arr;
    int size;
} Queue;

Queue* init_q(unsigned n){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int*) malloc(n * sizeof(int));
    q->size = n;
    return q;
}
int increment(Queue q, int n){
    return((n+1)%q.size);
}
int decrement(Queue q, int n){
    return((n+q.size-1)%q.size);
}
bool isEmpty(Queue q){
    return (q.rear == -1 && q.front == -1);
}
bool isFull(Queue q){
    return (increment(q,q.rear) == q.front);
}
void enqueue(Queue* q, int val){
    if(isFull(*q)){
        printf("Queue Overflow!\n");
        return;
    }
    else if(isEmpty(*q)){
        q->front = increment(*q,q->front);
    }
    q->rear = increment(*q,q->rear);
    q->arr[q->rear] = val;
}
void dequeue(Queue* q){
    if(isEmpty(*q)){
        printf("Queue Underflow\n");
        return;
    }
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front = increment(*q,q->front);
}
int front(Queue q){
    if(!isEmpty(q)){
        return q.arr[q.front];
    }
    printf("Queue is empty! returned exit code -1\n");
    return -1;
}
void printQueue(Queue q){
    if(!isEmpty(q)){
        printf("[ ");
        for (int i = q.front; i <= q.rear; i++)
        {
            printf("%d ",q.arr[i]);
        }
        printf("]\n");
        return;
    }    
    printf("[ ]\n");
}

int main(){
    Queue* q = init_q(5);
    enqueue(q,4);
    enqueue(q,2);
    enqueue(q,6);
    enqueue(q,2);
    dequeue(q);
    printQueue(*q);
    return 0;
}