#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n = 10000;
    int *arr = (int *)malloc(n * sizeof(int));
    struct node *head = NULL;
    clock_t start, end;
    double time_array, time_list;

    start = clock();
    for (int i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = 10;
    end = clock();
    time_array = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 10;
    newnode->next = head;
    head = newnode;
    end = clock();
    time_list = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array insertion time: %f\n", time_array);
    printf("Linked list insertion time: %f\n", time_list);

    start = clock();
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    end = clock();
    time_array = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    struct node *temp = head;
    head = head->next;
    free(temp);
    end = clock();
    time_list = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array deletion time: %f\n", time_array);
    printf("Linked list deletion time: %f\n", time_list);

    free(arr);
    return 0;
}
