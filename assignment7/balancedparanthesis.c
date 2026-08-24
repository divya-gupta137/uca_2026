#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 30

bool isBalanced (char expression[]) {
    char stack[MAX];
    int top = -1;
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if ( ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        }

        else if (ch == ')' || ch == ']' || ch == '{') {
	    if (top == -1) {
		return false;
	    }

	char opening = stack[top--];

      	    if ((ch == ')' && opening != '(') ||
		(ch == ']' && opening != '[') ||
	   	(ch == '}' && opening != '{')) {
		    return false;
	    }
    	}
    }

    return top == -1;


int main() {

    char expression[MAX];

    printf("Enter expression: ");
    scanf("%30s", expression);

    if (isBalanced(expression)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

