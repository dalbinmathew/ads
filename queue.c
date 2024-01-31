#include <stdio.h>
#include <stdlib.h>
#define max 20
void insert();
void delete();
void display();
int queue[max], rear=-1, front=-1;
int main()
{
int choice;
while(1)
{
printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:insert();
		break;
case 2:delete();
		break;
case 3:display();
		break;
case 4:exit(0);
default:printf("\nwrong choice");
}
}
return 0;
}


void insert()
{
int item;
if(rear==max-1)
printf("queue overflow");
else
{
if(front==-1)
front=0;
printf("enter the element to be inserted:");
scanf("%d",&item);
rear=rear+1;
queue[rear]=item;
}
}

void delete()
{
if(front==-1||front>rear)
printf("queue underflow");
else
{
printf("element deleted from queue is %d",queue[front]);
front=front+1;
}
}

void display()
{
int i;
if(front==-1)
printf("queue is empty\n");
else
{
printf("queue is:\n");
for(i=front;i<=rear;i++)
printf("%d",queue[i]);
printf("\n");
}
}
