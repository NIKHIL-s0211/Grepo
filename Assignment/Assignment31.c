#include <stdio.h>

int main() {
    int q[10];
    int n, front = -1, rear = -1;
    int choice, value;

    scanf("%d", &n);

    while (1) {
        scanf("%d", &choice);

        if (choice == 1) {
            if ((rear + 1) % n == front) {
                printf("Queue Full\n");
            } else {
                scanf("%d", &value);
                if (front == -1)
                    front = 0;
                rear = (rear + 1) % n;
                q[rear] = value;
            }
        }

        else if (choice == 2) {
            if (front == -1) {
                printf("Queue Empty\n");
            } else {
                printf("%d\n", q[front]);
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % n;
                }
            }
        }

        else if (choice == 3) {
            if (front == -1) {
                printf("Queue Empty\n");
            } else {
                int i = front;
                while (1) {
                    printf("%d ", q[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % n;
                }
                printf("\n");
            }
        }

        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
