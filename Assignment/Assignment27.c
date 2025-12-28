#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node *head, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        newnode->next = newnode;
        return newnode;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
    return head;
}

struct node* delete(struct node *head, int value) {
    if (head == NULL)
        return NULL;

    struct node *curr = head, *prev = NULL;

    do {
        if (curr->data == value) {
            if (curr == head && curr->next == head) {
                free(curr);
                return NULL;
            }

            if (curr == head) {
                struct node *temp = head;
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                free(curr);
                return head;
            }

            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;
}

void display(struct node *head) {
    if (head == NULL)
        return;

    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct node *head = NULL;
    int n, value, del;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    display(head);

    scanf("%d", &del);
    head = delete(head, del);

    display(head);

    return 0;
}
