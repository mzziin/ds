#include <stdio.h>
#include <stdlib.h>
#define N 5

int front = -1;
int rear = -1;
int Q[N];

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    while (1) {
        printf("\n\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enqueue() {
    int value;

    if ((rear + 1) % N == front) {
        printf("Queue is Full!\n");
        return;
    }

    printf("Enter a value: ");
    scanf("%d", &value);

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }

    Q[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
    }
    else if (front == rear) {
        printf("Removed %d\n", Q[front]);
        front = rear = -1;
    }
    else {
        printf("Removed %d\n", Q[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");
    int i = front;

    while (1) {
        printf("%d ", Q[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}

