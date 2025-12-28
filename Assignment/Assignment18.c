#include <stdio.h>

int tree[100];
int n;

void inorder(int i) {
    if (i >= n || tree[i] == -1)
        return;

    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    inorder(0);

    return 0;
}
