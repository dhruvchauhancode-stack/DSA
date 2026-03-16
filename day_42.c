#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    scanf("%d", &n);

    // Input queue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // Push queue elements into stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // Pop stack back to queue
    front = 0;
    rear = -1;

    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    // Print reversed queue
    for(int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
