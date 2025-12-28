#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, n = 5;
    arr = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    printf("Values after initialization:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}
