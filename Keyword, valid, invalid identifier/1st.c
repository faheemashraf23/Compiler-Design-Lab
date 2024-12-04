#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// List of C keywords
const char* keywords[] = {
    "asm", "auto", "break", "case", "char", "const", "continue",
    "default", "do", "double", "else", "enum", "extern", "float",
    "for", "goto", "if", "inline", "int", "long", "register", "restrict",
    "return", "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef", "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(const char* str) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1; // It is a keyword
        }
    }
    return 0; // Not a keyword
}

int isValidIdentifier(const char* str) {
    // Check if the first character is valid (must be a letter or an underscore)
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0; // Invalid if it starts with a digit or other character
    }

    // Check the rest of the characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0; // Invalid character found
        }
    }

    return 1; // Valid identifier
}

int main() {
    int testCase;
    char input[MAX_LENGTH];

    // Number of test cases
    printf("Input: Test Case: ");
    scanf("%d", &testCase);
    getchar(); // To consume the newline character after number input

    for (int i = 0; i < testCase; i++) {
        printf("Enter identifier: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline

        if (isKeyword(input)) {
            printf("Output: keyword\n");
        } else if (isValidIdentifier(input)) {
            printf("Output: valid identifier\n");
        } else {
            printf("Output: invalid identifier\n");
        }
    }

    return 0;
}
