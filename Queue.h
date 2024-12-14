#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Node structure representing a single node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure used internally for the stack implementation
typedef struct Queue {
    Node* front, * rear;
} Queue;

// Stack structure implemented using a single queue
typedef struct Stack {
    Queue* queue;
} Stack;

// Queue functions
Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);

// Stack functions
Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int top(Stack* stack);
int isStackEmpty(Stack* stack);

#endif // STACK_QUEUE_H
