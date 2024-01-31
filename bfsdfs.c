#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void bfs(int adj[][MAX],int visited[],int start)
{
    int queue[MAX], rear= -1, front= -1, i, k;
    for(k=0;k<MAX;k++)
    visited[k]=0;

    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front) //end only when queue is empty
    {
        start=queue[front++];
        printf("%c-",start+65);
        for(i=0;i<MAX;i++) //add neighbours
        {
            if(adj[start][i] && visited[i]==0)
            {
                queue[++rear] = i;
                visited[i]=1;
            }
        }
    }
}

void dfs(int adj[][MAX],int visited[],int start)
{
    int stack[MAX];
    int top = -1, i, k;
    for(k=0;k<MAX;k++)
    visited[k]=0;

stack[++top]=start;
visited[start]=1;

while(top!=-1) //end only when stack is empty
{
    start=stack[top--];
    printf("%c-",start+65);
    for(i=0;i<MAX;i++)
    {
        if(adj[start][i] && visited[i]==0)
        {
            stack[++top]=i;
            visited[i]=1;
        }
    }
}
}

int main()
{
    int visited[MAX];
    int adj[MAX][MAX], i, j;
    int option,size;
    do 
    {
        printf("\nMAIN MENU\n\n1.Enter values in graph\n2.BFS Traversal\n3.DFS Traversal\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("\nEnter the adjacency matrix:\n");
                for(i=0;i<MAX;i++)
                for(j=0;j<MAX;j++)
                scanf("%d",&adj[i][j]);
                break;
            case 2:
                printf("BFS Traversal:");
                bfs(adj,visited,0);
                break;
            case 3:
                printf("DFS Traversal:");
                dfs(adj,visited,0);
                break;
        }
    }while(option!=4);
        
        return 0;
}