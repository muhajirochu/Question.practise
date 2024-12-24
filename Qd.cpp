#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_at_beginning(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insert_at_end(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_at_beginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
