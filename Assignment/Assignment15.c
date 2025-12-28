#include <stdio.h>

int main() {
    int r, c;
    int matrix[10][10];
    int sparse[50][3];
    int k = 1;

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    sparse[0][0] = r;
    sparse[0][1] = c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;

    for (int i = 0; i < k; i++)
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    return 0;
}
