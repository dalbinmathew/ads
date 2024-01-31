#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int);
void dequeue();
void display();
int peek();

int main(void) {
    int choice, data;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Front element of queue: %d\n", peek());
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void enqueue(int data) {
    Node *newnode = malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("\nQueue Overflow");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (rear == NULL) {
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    printf("Element dequeued successfully.\n");
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    Node *current = front;
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int peek() {
    if (front != NULL) {
        return front->data;
    } else {
        printf("Queue is empty\n");
        return -1; // or any other appropriate value to indicate queue is empty
    }
}
