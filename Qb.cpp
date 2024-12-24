#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    int data;
    struct stackNode* next;
};

struct stackNode* top = NULL;

void push(int value) {
    struct stackNode* newnode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void display() {
    struct stackNode* temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    return 0;
}
