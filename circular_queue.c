#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Circular Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    items[rear] = value;

    printf("Inserted %d into Circular Queue\n", value);
}

void delete() {
    if (front == -1) {
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("Deleted %d from Front\n", items[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", items[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    // 1. Insert 10, 20, 30, and 40
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    // 2. Delete two elements from the front
    delete();
    delete();

    // 3. Insert 50 and 60 into the queue
    insert(50);
    insert(60);

    // 4. Display the elements of the Circular Queue
    display();

    return 0;
}
