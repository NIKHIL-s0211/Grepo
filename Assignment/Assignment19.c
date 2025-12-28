#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* queue[100];
int front = 0, rear = 0;

struct node* create(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return NULL;

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void enqueue(struct node *temp) {
    queue[rear++] = temp;
}

struct node* dequeue() {
    return queue[front++];
}

void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, value;
    struct node *root = NULL;

    scanf("%d", &n);

    if (n == 0)
        return 0;

    scanf("%d", &value);
    root = create(value);
    enqueue(root);

    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        struct node *parent = queue[front];
        struct node *newnode = create(value);

        if (parent->left == NULL)
            parent->left = newnode;
        else {
            parent->right = newnode;
            dequeue();
        }

        enqueue(newnode);
    }

    inorder(root);

    return 0;
}
