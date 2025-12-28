#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return;

    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Empty\n");
        return;
    }

    struct node *temp = top;
    printf("%d\n", top->data);
    top = top->next;
    free(temp);
}

void display() {
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
