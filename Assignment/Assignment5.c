#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int **arr = (int **)malloc(r * sizeof(int *));
    if (arr == NULL)
        return 0;

    for (int i = 0; i < r; i++) {
        arr[i] = (int *)malloc(c * sizeof(int));
        if (arr[i] == NULL)
            return 0;
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < r; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
