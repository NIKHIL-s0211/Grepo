#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node *head, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return head;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

struct node* delete(struct node *head, int value) {
    if (head == NULL)
        return head;

    if (head->data == value) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next != NULL) {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
    }

    return head;
}

void traverse(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    int n, value, del;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    traverse(head);

    scanf("%d", &del);
    head = delete(head, del);

    traverse(head);

    return 0;
}
