#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->items[s->top--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

void displayStack(Stack *s) {
    printf("\nStack Contents:\n");
    printf("┌─────┐\n");
    for (int i = s->top; i >= 0; i--) {
        printf("│  %c  │\n", s->items[i]);
        printf("├─────┤\n");
    }
    printf("└─────┘\n");
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    sleep(2);  // Pause for 2 seconds
} 