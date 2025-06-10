#include "stack.h"

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;
    
    printf("\nConverting Infix to Postfix:\n");
    printf("Infix Expression: %s\n", infix);
    
    for (int i = 0; infix[i] != '\0'; i++) {
        printf("\nStep %d: Processing '%c'\n", i + 1, infix[i]);
        
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
            printf("Operand found, adding to output\n");
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
            printf("Opening parenthesis, pushing to stack\n");
        }
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
                printf("Closing parenthesis, popping operators\n");
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack);
            }
        }
        else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && peek(&stack) != '(' && 
                   getPrecedence(peek(&stack)) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(&stack);
                printf("Operator found, popping higher precedence operators\n");
            }
            push(&stack, infix[i]);
            printf("Pushing current operator to stack\n");
        }
        
        printf("Current Postfix: %.*s\n", j, postfix);
        displayStack(&stack);
        pause();
    }
    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        printf("\nFinal step: Popping remaining operators\n");
        displayStack(&stack);
        pause();
    }
    
    postfix[j] = '\0';
    printf("\nFinal Postfix Expression: %s\n", postfix);
}

void infixToPrefix(char *infix, char *prefix) {
    // Reverse the infix expression
    int len = strlen(infix);
    char reversed[MAX_SIZE];
    for (int i = 0; i < len; i++) {
        reversed[i] = infix[len - 1 - i];
    }
    reversed[len] = '\0';
    
    // Convert to postfix
    char postfix[MAX_SIZE];
    infixToPostfix(reversed, postfix);
    
    // Reverse the postfix to get prefix
    len = strlen(postfix);
    for (int i = 0; i < len; i++) {
        prefix[i] = postfix[len - 1 - i];
    }
    prefix[len] = '\0';
}

void postfixToPrefix(char *postfix, char *prefix) {
    Stack stack;
    initStack(&stack);
    char temp[MAX_SIZE];
    int j = 0;
    
    printf("\nConverting Postfix to Prefix:\n");
    printf("Postfix Expression: %s\n", postfix);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        printf("\nStep %d: Processing '%c'\n", i + 1, postfix[i]);
        
        if (isalnum(postfix[i])) {
            temp[j++] = postfix[i];
            printf("Operand found, adding to temporary string\n");
        }
        else if (isOperator(postfix[i])) {
            char op2 = temp[--j];
            char op1 = temp[--j];
            temp[j++] = postfix[i];
            temp[j++] = op1;
            temp[j++] = op2;
            printf("Operator found, combining operands\n");
        }
        
        printf("Current Prefix: %.*s\n", j, temp);
        displayStack(&stack);
        pause();
    }
    
    strcpy(prefix, temp);
    printf("\nFinal Prefix Expression: %s\n", prefix);
}

void prefixToPostfix(char *prefix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;
    
    printf("\nConverting Prefix to Postfix:\n");
    printf("Prefix Expression: %s\n", prefix);
    
    // Process from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        printf("\nStep %d: Processing '%c'\n", strlen(prefix) - i, prefix[i]);
        
        if (isalnum(prefix[i])) {
            push(&stack, prefix[i]);
            printf("Operand found, pushing to stack\n");
        }
        else if (isOperator(prefix[i])) {
            char op1 = pop(&stack);
            char op2 = pop(&stack);
            char temp[MAX_SIZE];
            sprintf(temp, "%c%c%c", op1, op2, prefix[i]);
            for (int k = 0; temp[k] != '\0'; k++) {
                push(&stack, temp[k]);
            }
            printf("Operator found, combining operands\n");
        }
        
        displayStack(&stack);
        pause();
    }
    
    // Pop the final result
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
    printf("\nFinal Postfix Expression: %s\n", postfix);
}

int evaluatePostfix(char *postfix) {
    Stack stack;
    initStack(&stack);
    
    printf("\nEvaluating Postfix Expression:\n");
    printf("Postfix Expression: %s\n", postfix);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        printf("\nStep %d: Processing '%c'\n", i + 1, postfix[i]);
        
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
            printf("Digit found, pushing to stack\n");
        }
        else if (isOperator(postfix[i])) {
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            int result;
            
            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': 
                    result = 1;
                    for (int j = 0; j < op2; j++) {
                        result *= op1;
                    }
                    break;
            }
            
            push(&stack, result);
            printf("Operator found, performing operation\n");
        }
        
        displayStack(&stack);
        pause();
    }
    
    return pop(&stack);
}

int evaluatePrefix(char *prefix) {
    Stack stack;
    initStack(&stack);
    
    printf("\nEvaluating Prefix Expression:\n");
    printf("Prefix Expression: %s\n", prefix);
    
    // Process from right to left
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        printf("\nStep %d: Processing '%c'\n", strlen(prefix) - i, prefix[i]);
        
        if (isdigit(prefix[i])) {
            push(&stack, prefix[i] - '0');
            printf("Digit found, pushing to stack\n");
        }
        else if (isOperator(prefix[i])) {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            int result;
            
            switch (prefix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': 
                    result = 1;
                    for (int j = 0; j < op2; j++) {
                        result *= op1;
                    }
                    break;
            }
            
            push(&stack, result);
            printf("Operator found, performing operation\n");
        }
        
        displayStack(&stack);
        pause();
    }
    
    return pop(&stack);
} 