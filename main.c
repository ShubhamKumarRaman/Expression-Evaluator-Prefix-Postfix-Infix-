#include "stack.h"

void displayMenu() {
    printf("\n=== Expression Evaluator ===\n");
    printf("1. Convert Infix to Postfix\n");
    printf("2. Convert Infix to Prefix\n");
    printf("3. Convert Postfix to Prefix\n");
    printf("4. Convert Prefix to Postfix\n");
    printf("5. Evaluate Postfix Expression\n");
    printf("6. Evaluate Prefix Expression\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

void getExpression(char *prompt, char *expression) {
    printf("%s", prompt);
    scanf("%s", expression);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear input buffer
        
        switch (choice) {
            case 1:
                getExpression("Enter infix expression: ", infix);
                infixToPostfix(infix, postfix);
                break;
                
            case 2:
                getExpression("Enter infix expression: ", infix);
                infixToPrefix(infix, prefix);
                printf("\nFinal Prefix Expression: %s\n", prefix);
                break;
                
            case 3:
                getExpression("Enter postfix expression: ", postfix);
                postfixToPrefix(postfix, prefix);
                break;
                
            case 4:
                getExpression("Enter prefix expression: ", prefix);
                prefixToPostfix(prefix, postfix);
                break;
                
            case 5:
                getExpression("Enter postfix expression: ", postfix);
                printf("\nResult: %d\n", evaluatePostfix(postfix));
                break;
                
            case 6:
                getExpression("Enter prefix expression: ", prefix);
                printf("\nResult: %d\n", evaluatePrefix(prefix));
                break;
                
            case 7:
                printf("\nThank you for using Expression Evaluator!\n");
                return 0;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        clearScreen();
    }
    
    return 0;
} 