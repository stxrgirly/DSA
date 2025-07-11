#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct {
    int items[MAXSIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to insert an item into the queue
void insert(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d.\n", item);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Initialize front if queue is empty
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->items[q->rear] = item;
    printf("Inserted: %d\n", item);
}

// Function to delete an item from the queue
void delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    int deletedItem = q->items[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAXSIZE;
    }
    printf("Deleted: %d\n", deletedItem);
}

// Function to display the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue q;
    initQueue(&q);

    // Perform insertions
    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);

    // Display the queue
    display(&q);

    // Perform deletions
    delete(&q);
    delete(&q);

    // Display the queue again
    display(&q);

    // Insert another element
    insert(&q, 40);
    display(&q);

    return 0;
}
