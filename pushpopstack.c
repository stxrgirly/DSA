#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct {
    int items[MAXSIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAXSIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow. Cannot push %d.\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("Pushed: %d\n", item);
}

// Function to pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1; // Return -1 to indicate an error
    }
    return s->items[(s->top)--];
}

// Function to display the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    Stack s;
    initStack(&s);

    // Perform push operations
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    // Display the stack
    display(&s);

    // Perform pop operations
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    // Display the stack again
    display(&s);

    // Push another element
    push(&s, 40);
    display(&s);

    return 0;
}