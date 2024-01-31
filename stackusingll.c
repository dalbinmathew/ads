#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *top=NULL;

void push(int);
void pop();
void display();
int peek();

int main(void){
int choice, data;

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Top element of stack: %d\n", peek());
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

void push(int data){
   Node *newnode=malloc(sizeof(Node));
   if(newnode == NULL){
    printf("\nStack Overflow");
    return;
   }
   newnode->data=data;
   newnode->next=top;
   top=newnode;
}

void pop(){
    if(top != NULL){
        Node *temp=top;
        top=top->next;
        free(temp);
        return;
    }
}

void display(){
    if(top==NULL){
        printf("stack is empty");
    }
    Node *current=top;
    while(current->next!=NULL){
        printf("%d-->",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
}

int peek(){
    if(top!=NULL){
        return top->data;
    }
}