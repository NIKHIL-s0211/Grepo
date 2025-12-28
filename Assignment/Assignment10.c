#include <stdio.h>

int main() {
    int queue[100];
    int front = -1, rear = -1;
    int n, choice, value;

    scanf("%d", &n);

    while (1) {
        scanf("%d", &choice);

        if (choice == 1) {
            if (rear == n - 1) {
                printf("Queue Full\n");
            } else {
                scanf("%d", &value);
                if (front == -1)
                    front = 0;
                rear++;
                queue[rear] = value;
            }
        }

        else if (choice == 2) {
            if (front == -1 || front > rear) {
                printf("Queue Empty\n");
            } else {
                printf("%d\n", queue[front]);
                front++;
            }
        }

        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
