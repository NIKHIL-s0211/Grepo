#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));

    if (first == NULL || second == NULL)
        return 0;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = NULL;

    struct node *temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(first);
    free(second);

    return 0;
}
