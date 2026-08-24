#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int evaluatePostfix(char expression[]) {
    int stack[MAX];
    int top = -1;

    char *token = strok(expression, " ");

   while (token!=NULL) {
       if(token[0] >= '0' && token[0]<='9') {
            stack[++top] = atoi(token);
       }

       else {

            int b = stack[top--];
            int a = stack[top--];

            int result;

            switch (token[0]) {

                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            stack[++top] = result;
        }
    
 
        token = strtok(NULL, " ");
    }

    return stack[top];
}

int main() {

    char expression[MAX];

    printf("Enter postfix expression: ");
    fgets(expression, MAX, stdin);

    printf("%d\n", evaluatePostfix(expression));

    return 0;
}
