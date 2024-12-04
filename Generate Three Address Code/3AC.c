
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack {
    char* items[MAX];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char* item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %s\n", item);
        return;
    }
    stack->items[++stack->top] = item;
}

char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

void generateThreeAddressCode(char* expression) {
    Stack* stack = createStack();
    char t[10];
    int tempCount = 1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        if (isalnum(current)) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = current;
            operand[1] = '\0';
            push(stack, operand);
        } else {
            char* right = pop(stack);
            char* left = pop(stack);

            sprintf(t, "t%d", tempCount++);
            printf("    %s = %s %c %s\n", t, left, current, right);

            push(stack, strdup(t));
        }
    }

    free(stack);
}

int main() {
    char expression[MAX];

    printf("Input: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = 0;

    printf("Output: \n", expression);
    generateThreeAddressCode(expression);

    return 0;
}
