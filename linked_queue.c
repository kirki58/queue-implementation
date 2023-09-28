#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct Queue{
    QNode* front;
    QNode* rear;  
} Queue;

Queue* init_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL; 
}
bool isEmpty(Queue q){
    return (q.front == NULL && q.rear == NULL);
}
void enqueue(Queue* q, int val){
    QNode* temp = (QNode*) malloc(sizeof(QNode));
    temp->data = val;
    temp->next = NULL;
    if(q->front == NULL && q->rear == NULL){
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(Queue* q){
    if(isEmpty(*q)){
        printf("Queue underflow!");
        return;
    }
    QNode* temp = q->front;
    if(q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        q->front = q->front->next;
    }
    free(temp);
}
int front(Queue q){
    return(q.front->data);
}
int rear(Queue q){
    return(q.rear->data);
}
void printQueue(Queue q){
    struct QNode* temp;
    temp = q.front;
    printf("[ ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("]");
}
int main(){
    Queue* q = init_queue();
    enqueue(q,2);
    enqueue(q,4);
    enqueue(q,6);
    dequeue(q);
    printQueue(*q);
    return 0;
}