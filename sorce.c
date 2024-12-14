#include<stdio.h>
#include "Queue.h"

void print_queue(Queue* q) {
    Queue* tempQueue = createQueue();

    while (!isEmpty(q)) {
        int front = dequeue(q);
        printf("%d ", front);
        enqueue(tempQueue, front);
    }

    while (!isEmpty(tempQueue)) {
        enqueue(q, dequeue(tempQueue));
    }
    free(tempQueue);
    printf("\n");
}


void sortQueue(Queue* originalQueue) 
{
    Queue* sortedQueue = createQueue(); 

    while (!isEmpty(originalQueue))
    {
        
        int min = INT_MAX;
        int size = 0;

        Node* temp = originalQueue->front;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        for (int i = 0; i < size; i++) 
        {
            int frontValue = dequeue(originalQueue);

            if (frontValue < min) {
                min = frontValue; 
            }
            enqueue(originalQueue, frontValue);
        }

        for (int i = 0; i < size; i++) 
        {
            int frontValue = dequeue(originalQueue);

            if (frontValue == min)
            {
                continue;
            }
            enqueue(originalQueue, frontValue);
        }

        enqueue(sortedQueue, min);
    }

    while (!isEmpty(sortedQueue)) {
        enqueue(originalQueue, dequeue(sortedQueue));
    }

    free(sortedQueue);
}

int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", top(stack)); // יציג 30

    printf("Pop element: %d\n", pop(stack)); // יציג 30
    printf("Pop element: %d\n", pop(stack)); // יציג 20

    push(stack, 40);
    printf("Top element: %d\n", top(stack)); // יציג 40

    printf("Pop element: %d\n", pop(stack)); // יציג 40
    printf("Pop element: %d\n", pop(stack)); // יציג 10

    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
    }

    return 0;
}
