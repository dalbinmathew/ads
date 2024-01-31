#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    printf("Enter no:of vertices: ");
    scanf("%d", &n);
    int A[n][n],visited[n],e=0,u,v,cost=0,min=999;
    printf("Enter adjacency matrix: ");
    for (int i=0; i<n; i++)
    {
        visited[i]=0;
        for(int j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
            if(A[i][j]==0)
                A[i][j]=999;
            if(A[i][j]<min)
            {
                min=A[i][j];
                u=i;
                v=j;
            }
        }
    }
    cost+=min;
    visited[u]=1;
    visited[v]=1;
    printf("\nEdge: %d %d",u,v);
    e+=1;
    while(e<n-1)
    {
        min=999;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(int j=0;j<n;j++)
                {
                    if(A[i][j]<min && visited[j]==0)
                    {
                        min=A[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        cost+=min;
        printf("\nEdge: %d %d",u,v);
        visited[u]=1;
        visited[v]=1;
        e+=1;
    }
    printf("\nmin Cost= %d",cost);
}

