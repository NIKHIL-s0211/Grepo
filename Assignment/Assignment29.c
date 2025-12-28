#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertMiddle(struct node *head, int value, int pos) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return head;

    newnode->data = value;

    if (pos == 1) {
        newnode->next = head;
        return newnode;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* deleteMiddle(struct node *head, int pos) {
    if (head == NULL)
        return head;

    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
        return head;

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    int n, value, pos;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    scanf("%d %d", &value, &pos);
    head = insertMiddle(head, value, pos);
    display(head);

    scanf("%d", &pos);
    head = deleteMiddle(head, pos);
    display(head);

    return 0;
}
