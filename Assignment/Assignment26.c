#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *m = (int *)malloc(n * sizeof(int));
    int *c = (int *)calloc(n, sizeof(int));

    if (m == NULL || c == NULL)
        return 0;

    for (int i = 0; i < n; i++)
        printf("%d ", m[i]);

    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d ", c[i]);

    free(m);
    free(c);

    return 0;
}
