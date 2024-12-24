#include <stdio.h>
#include <stdlib.h>

struct node {
    int priority;
    char device[20];
    struct node* next;
};

struct node* head = NULL;

void insert(char device[], int priority) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newnode->priority = priority;
    snprintf(newnode->device, 20, "%s", device);
    newnode->next = NULL;

    if (head == NULL || priority < head->priority) {
        newnode->next = head;
        head = newnode;
    } else {
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void process_requests() {
    while (head != NULL) {
        printf("Processing %s with priority %d\n", head->device, head->priority);
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    insert("Keyboard", 1);
    insert("Mouse", 2);
    insert("Scanner", 3);
    insert("Printer", 4);

    printf("Processing device requests:\n");
    process_requests();

    return 0;
}
