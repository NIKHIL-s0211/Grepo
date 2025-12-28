#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *adj[10];
int visited[10];

struct node* create(int v) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = v;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int u, int v) {
    struct node *newnode = create(v);
    newnode->next = adj[u];
    adj[u] = newnode;
}

void dfs(int start, int n) {
    int stack[10], top = -1;
    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];

        if (visited[v] == 0) {
            printf("%d ", v);
            visited[v] = 1;

            struct node *temp = adj[v];
            while (temp != NULL) {
                if (visited[temp->data] == 0)
                    stack[++top] = temp->data;
                temp = temp->next;
            }
        }
    }
}

void bfs(int start, int n) {
    int queue[10], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct node *temp = adj[v];
        while (temp != NULL) {
            if (visited[temp->data] == 0) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, u, v;

    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(0, n);
    printf("\n");
    bfs(0, n);

    return 0;
}
