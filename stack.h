#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function declarations
void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char item);
char pop(Stack *s);
char peek(Stack *s);
void displayStack(Stack *s);
void clearScreen();
void pause();

// Expression conversion and evaluation functions
void infixToPostfix(char *infix, char *postfix);
void infixToPrefix(char *infix, char *prefix);
void postfixToPrefix(char *postfix, char *prefix);
void prefixToPostfix(char *prefix, char *postfix);
int evaluatePostfix(char *postfix);
int evaluatePrefix(char *prefix);
int getPrecedence(char op);
int isOperator(char ch);

#endif