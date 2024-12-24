#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stackNode {
    double data;
    struct stackNode* next;
};

struct stackNode* top = NULL;

void push(double value) {
    struct stackNode* newnode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

double pop() {
    if (top == NULL) return 0;
    struct stackNode* temp = top;
    double value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double evaluate(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            double b = pop();
            double a = pop();
            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push(pow(a, b)); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[] = "26+32/-2*^";
    double result = evaluate(postfix);
    printf("Result of postfix evaluation: %lf\n", result);
    return 0;
}
