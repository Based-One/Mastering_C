     #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyStack(const Stack *s) {
    return s->top == -1;
}

int isFull(const Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s,const char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (!isEmptyStack(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peekStack(Stack *s) {
    if (!isEmptyStack(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(const char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(const char* exp, char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            postfix[j++] = exp[i];
        } else if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&s, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char match = 0;
            if (exp[i] == ')') match = '(';
            if (exp[i] == ']') match = '[';
            if (exp[i] == '}') match = '{';

            while (!isEmptyStack(&s) && s.items[s.top] != match) {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmptyStack(&s) && precedence(peekStack(&s)) >= precedence(exp[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, exp[i]);
        }
        i++;
    }
    while (!isEmptyStack(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int operate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return '\0';
    }
    return 0;
}

int evaluatePostfix(const char* postfix) {
    Stack s;
    initStack(&s);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int result = operate(a, b, postfix[i]);
            push(&s, result);
        }
        i++;
    }
    return pop(&s);
}
void printStack(Stack *stack) {
    if (!isEmptyStack(stack)) {
        for (int i = 0; i < MAX; ++i) {

        }
    }
        else {
            printf("Stack is empty %d",0);
        }
    }


int isPalindrome(char *str) {
    Stack s;
    initStack(&s);
    char cleanedStr[MAX];
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            cleanedStr[j++] = tolower(str[i]);
        }
    }
    cleanedStr[j] = '\0';

    for (i = 0; cleanedStr[i] != '\0'; i++) {
        push(&s, cleanedStr[i]);
    }

    for (i = 0; cleanedStr[i] != '\0'; i++) {
        if (cleanedStr[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

void printPalindrome(char *str) {

    printf("Verificando: '%s'\n", str);
    if (isPalindrome(str)) {
        printf("El enunciado es un palindromo.\n");
    } else {
        printf("El enunciado no es un palindromo.\n");
    }
}
//
// int main() {
//     // Ejemplo 1: Verificar si es un palindromo
//     char str[MAX];
//
//     printf("=== Verificacion de palindromos ===\n");
//
//     // Ejemplo 1: Palindromo simple
//     strcpy(str,"hola");
//     printPalindrome(str);
//
//     // Ejemplo 2: No es un palindromo
//     strcpy(str, "Hola mundo");
//     printf("\nVerificando: '%s'\n", str);
//     if (isPalindrome(str)) {
//         printf("El enunciado es un palindromo.\n");
//     } else {
//         printf("El enunciado no es un palindromo.\n");
//     }
//
//     printf("\n=== Conversion de infijo a postfijo y evaluacion ===\n");
//     char exp[MAX], postfix[MAX];
//
//     // Ejemplo 1: Expresion aritmetica simple
//     strcpy(exp, "3+5*2");
//     printf("Expresion infija: %s\n", exp);
//     infixToPostfix(exp, postfix);
//     printf("Expresion postfija: %s\n", postfix);
//     int result = evaluatePostfix(postfix);
//     printf("Resultado de la evaluacion: %d\n", result);
//
//     // Ejemplo 2: Expresion aritmetica mas compleja con parentesis
//     strcpy(exp, "(1+2)*(3+4)");
//     printf("\nExpresion infija: %s\n", exp);
//     infixToPostfix(exp, postfix);
//     printf("Expresion postfija: %s\n", postfix);
//     result = evaluatePostfix(postfix);
//     printf("Resultado de la evaluacion: %d\n", result);
//
//     // Ejemplo 3: Expresion con multiples operaciones
//     strcpy(exp, "2+3*4-5/2");
//     printf("\nExpresion infija: %s\n", exp);
//     infixToPostfix(exp, postfix);
//     printf("Expresion postfija: %s\n", postfix);
//     result = evaluatePostfix(postfix);
//     printf("Resultado de la evaluacion: %d\n", result);
// strcpy(str,"a           a           a");
//     printf("\nVerificando: '%s'\n", str);
//     if (isPalindrome(str)) {
//
//         printf("El enunciado es palindromo");
//     }
//     return 0;
// }
