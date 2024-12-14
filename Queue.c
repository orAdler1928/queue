#include "Queue.h"

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to create a stack using a single queue
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue = createQueue();
    return stack;
}

// Function to add an element to the stack (Push)
void push(Stack* stack, int data) {
    enqueue(stack->queue, data);

    // Rotate the queue to make the last added element the front
    int size = 0;
    Node* temp = stack->queue->front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    for (int i = 0; i < size - 1; i++) {
        int front = dequeue(stack->queue);
        enqueue(stack->queue, front);
    }
}

// Function to remove an element from the stack (Pop)
int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(stack->queue);
}

// Function to get the top element of the stack
int top(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->queue->front->data;
}

// Function to check if the stack is empty
int isStackEmpty(Stack* stack) {
    return isEmpty(stack->queue);
}
