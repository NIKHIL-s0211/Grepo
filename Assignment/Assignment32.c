#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int value;
    struct node *next;
};

struct node* insert(struct node *head, int r, int c, int v) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->row = r;
    newnode->col = c;
    newnode->value = v;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int r, c;
    int matrix[10][10];
    struct node *head = NULL;

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0)
                head = insert(head, i, j, matrix[i][j]);
        }
    }

    display(head);

    return 0;
}
