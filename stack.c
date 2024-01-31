#include<stdio.h>

int stack[50];
int top= -1;
int i,s,o;
int choice;

void push()
{
int element;
if(top==s-1)
{
printf("stack overflow\n");
return;
}
else
{
printf("enter the element to be pushed:\n");
scanf("%d",&element);
stack[++top]=element;
}}

void pop()
{
if(top==-1)
{
printf("stack underflow\n");
return;
}
else  
top--;
}

void show()  
{  
for (i=top;i>=0;i--)  
{  
printf("%d\n",stack[i]);  
}  
if(top == -1)   
{  
printf("Stack is empty");  
}  
} 

void peek()
{
if(top== -1)
{
printf("Stack is empty");  
} 
else
printf("the element at the top of the stack is %d\n",stack[top]);
}


void main()
{
printf("enter the size of the stack:\n");
scanf("%d",&s);
do
{
    menu:
printf("Chose one from the below options...\n");  
printf("\n1.Push\n2.Pop\n3.Show\n4.Peek\n5.Exit");  
printf("\n Enter your choice \n");        
scanf("%d",&choice);  
switch(choice)  
{
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                break;  
            }  
            case 4:   
            {  
                peek();  
                break;   
            } 
            case 5:   
            {  
                printf("Exiting....\n");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice\n");  
            }   
        };  
printf("do you want to continue?\n \t 1.YES\t 2.NO\n");
scanf("%d",&o);
if(o==1)
goto menu;
    } while(o!=0);
} 
 
