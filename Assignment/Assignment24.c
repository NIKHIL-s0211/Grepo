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

void levelOrder(struct node *root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front < rear) {
        struct node *temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);
        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main() {
    struct node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    levelOrder(root);

    return 0;
}
