#include <stdio.h>

int visited[10];

void dfs(int graph[10][10], int n, int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(graph, n, i);
    }
}

int main() {
    int n;
    int graph[10][10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    dfs(graph, n, 0);

    return 0;
}
